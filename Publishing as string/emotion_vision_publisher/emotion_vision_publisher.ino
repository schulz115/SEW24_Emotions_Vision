#include <EmotionVision2_inferencing.h>
#include <ros.h>
#include <std_msgs/String.h>
#include "camera.h"
#include "himax.h"
#include "edge-impulse-sdk/dsp/image/image.hpp"

#define EI_CAMERA_RAW_FRAME_BUFFER_COLS 320
#define EI_CAMERA_RAW_FRAME_BUFFER_ROWS 240
#define EI_CAMERA_FRAME_BUFFER_SDRAM

#ifdef EI_CAMERA_FRAME_BUFFER_SDRAM
#include "SDRAM.h"
#endif

#define ALIGN_PTR(p,a) ((p & (a-1)) ?(((uintptr_t)p + a) & ~(uintptr_t)(a-1)) : p)

static bool is_initialised = false;
static bool is_ll_initialised = false;
HM01B0 himax;
static Camera cam(himax);
FrameBuffer fb;

#ifdef EI_CAMERA_FRAME_BUFFER_SDRAM
static uint8_t *ei_camera_frame_mem;
static uint8_t *ei_camera_frame_buffer;
#else
static uint8_t ei_camera_frame_buffer[EI_CAMERA_RAW_FRAME_BUFFER_COLS * EI_CAMERA_RAW_FRAME_BUFFER_ROWS] __attribute__((aligned(32)));
#endif

static uint8_t *ei_camera_capture_out = NULL;

ros::NodeHandle nh;
std_msgs::String emotion_msg;
ros::Publisher emotion_pub("emotionvision", &emotion_msg);

bool setup_board() {
#ifdef EI_CAMERA_FRAME_BUFFER_SDRAM
    if (!SDRAM.begin(SDRAM_START_ADDRESS)) {
        return false;
    }

    ei_camera_frame_mem = (uint8_t *)SDRAM.malloc(EI_CAMERA_RAW_FRAME_BUFFER_COLS * EI_CAMERA_RAW_FRAME_BUFFER_ROWS + 32);
    if (ei_camera_frame_mem == NULL) {
        return false;
    }
    ei_camera_frame_buffer = (uint8_t *)ALIGN_PTR((uintptr_t)ei_camera_frame_mem, 32);
#endif

    if (!cam.begin(CAMERA_R320x240, CAMERA_GRAYSCALE, 30)) {
        return false;
    }

    fb.setBuffer(ei_camera_frame_buffer);
    is_initialised = true;
    return true;
}

bool ei_camera_capture(uint32_t img_width, uint32_t img_height, uint8_t *out_buf) {
    if (!is_initialised) {
        return false;
    }

    int snapshot_response = cam.grabFrame(fb, 3000);
    if (snapshot_response != 0) {
        return false;
    }

    ei_camera_capture_out = ei_camera_frame_buffer;

    return true;
}

bool get_emotion_predictions(char *output, size_t output_size) {
    ei::signal_t signal;
    signal.total_length = EI_CLASSIFIER_INPUT_WIDTH * EI_CLASSIFIER_INPUT_HEIGHT;
    signal.get_data = &ei_camera_cutout_get_data;

    if (!ei_camera_capture((size_t)EI_CLASSIFIER_INPUT_WIDTH, (size_t)EI_CLASSIFIER_INPUT_HEIGHT, NULL)) {
        return false;
    }

    ei_impulse_result_t result = {0};
    EI_IMPULSE_ERROR err = run_classifier(&signal, &result, false);

    if (err != EI_IMPULSE_OK || EI_CLASSIFIER_LABEL_COUNT != 6) {
        return false;
    }

    snprintf(output, output_size,
             "angry : %.5f    "

             "happy : %.5f    "

             "neutral : %.5f    "

             "no_face : %.5f    "

             "sad : %.5f    "

             "surprised : %.5f",
             result.classification[0].value,
             result.classification[1].value,
             result.classification[2].value,
             result.classification[3].value,
             result.classification[4].value,
             result.classification[5].value);

    return true;
}

int ei_camera_cutout_get_data(size_t offset, size_t length, float *out_ptr) {
    size_t bytes_left = length;
    size_t out_ptr_ix = 0;

    while (bytes_left != 0) {
        uint8_t pixel = ei_camera_capture_out[offset];

        uint8_t r, g, b;
        r = g = b = pixel;

        float pixel_f = (r << 16) + (g << 8) + b;
        out_ptr[out_ptr_ix] = pixel_f;

        out_ptr_ix++;
        offset++;
        bytes_left--;
    }

    return 0;
}

void setup() {
    nh.initNode();
    nh.advertise(emotion_pub);

    if (!setup_board()) {
        nh.logerror("Failed to initialize camera");
        while (1);
    }
}

void loop() {
    char emotion_output[256];

    if (get_emotion_predictions(emotion_output, sizeof(emotion_output))) {
        emotion_msg.data = emotion_output;
        emotion_pub.publish(&emotion_msg);
    } else {
        nh.logerror("Failed to get emotion predictions");
    }

    nh.spinOnce();
    delay(2000); // Publish every 2 seconds
}
