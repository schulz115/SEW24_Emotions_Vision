#ifndef _ROS_emotion_msgs_UserEmotion_h
#define _ROS_emotion_msgs_UserEmotion_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace emotion_msgs
{

  class UserEmotion : public ros::Msg
  {
    public:
      typedef float _none_type;
      _none_type none;
      typedef float _happy_type;
      _happy_type happy;
      typedef float _sad_type;
      _sad_type sad;
      typedef float _angry_type;
      _angry_type angry;
      typedef float _surprised_type;
      _surprised_type surprised;
      typedef float _neutral_type;
      _neutral_type neutral;

    UserEmotion():
      none(0),
      happy(0),
      sad(0),
      angry(0),
      surprised(0),
      neutral(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_none;
      u_none.real = this->none;
      *(outbuffer + offset + 0) = (u_none.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_none.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_none.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_none.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->none);
      union {
        float real;
        uint32_t base;
      } u_happy;
      u_happy.real = this->happy;
      *(outbuffer + offset + 0) = (u_happy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_happy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_happy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_happy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->happy);
      union {
        float real;
        uint32_t base;
      } u_sad;
      u_sad.real = this->sad;
      *(outbuffer + offset + 0) = (u_sad.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sad.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sad.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sad.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sad);
      union {
        float real;
        uint32_t base;
      } u_angry;
      u_angry.real = this->angry;
      *(outbuffer + offset + 0) = (u_angry.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angry.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angry.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angry.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angry);
      union {
        float real;
        uint32_t base;
      } u_surprised;
      u_surprised.real = this->surprised;
      *(outbuffer + offset + 0) = (u_surprised.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_surprised.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_surprised.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_surprised.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->surprised);
      union {
        float real;
        uint32_t base;
      } u_neutral;
      u_neutral.real = this->neutral;
      *(outbuffer + offset + 0) = (u_neutral.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_neutral.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_neutral.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_neutral.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->neutral);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_none;
      u_none.base = 0;
      u_none.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_none.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_none.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_none.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->none = u_none.real;
      offset += sizeof(this->none);
      union {
        float real;
        uint32_t base;
      } u_happy;
      u_happy.base = 0;
      u_happy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_happy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_happy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_happy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->happy = u_happy.real;
      offset += sizeof(this->happy);
      union {
        float real;
        uint32_t base;
      } u_sad;
      u_sad.base = 0;
      u_sad.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sad.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sad.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sad.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sad = u_sad.real;
      offset += sizeof(this->sad);
      union {
        float real;
        uint32_t base;
      } u_angry;
      u_angry.base = 0;
      u_angry.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angry.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angry.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angry.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angry = u_angry.real;
      offset += sizeof(this->angry);
      union {
        float real;
        uint32_t base;
      } u_surprised;
      u_surprised.base = 0;
      u_surprised.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_surprised.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_surprised.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_surprised.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->surprised = u_surprised.real;
      offset += sizeof(this->surprised);
      union {
        float real;
        uint32_t base;
      } u_neutral;
      u_neutral.base = 0;
      u_neutral.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_neutral.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_neutral.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_neutral.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->neutral = u_neutral.real;
      offset += sizeof(this->neutral);
     return offset;
    }

    virtual const char * getType() override { return "emotion_msgs/UserEmotion"; };
    virtual const char * getMD5() override { return "fbdf9be88a61551971cb1cb9dd72498a"; };

  };

}
#endif
