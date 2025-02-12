# SEW24_Emotions_Vision

Hello fellow software engineers,

The goal of this (part-)project was to use the Arduino Portenta H7 microcontroller on the TurtleBot3 to equip the bot with the ability of recognizing facial emotions by generating live classification results and publishing these data as a topic through ROS1 which were then further used by other teams for their processing.

The project includes the following assets:
- one folder with a sketch for creating a publisher node with the generated data as a string topic and
- another folder with the sketch updated for creating a publisher node with the generated data as a topic through the custom data type 'UserEmotion'.

Also provided is an extra folder with the two custom libraries:
- 'EmotionVision2_inferencing' as a .zip file - which is the result of deploying the Edge Impulse project as an Arduino library. This one was needed for both string aswell as custom data type publishing.
- 'ros_lib' as a .zip file - which was provided by the kind colleague Julian Weidner from the fellow team 'Robot Emotions'. This one was only needed for the finalized publishing of the generated data via their custom data type - which is defined in the header file 'UserEmotion.h' (\ros_lib\emotion_msgs\UserEmotion.h). This library is basically the same as the official rosserial Arduino library, but with this addition.


Also required are the two following libraries:
- the 'Rosserial Arduino Library' (v0.9.1 used in this Project) (as just mentioned, in my case using the custom 'ros_lib' for the finalized publisher made using the original rosserial library obsolete)
- 'Arduino AVR Boards' (v1.8.6 used in this project) which is the library for the Arduino Portenta H7 hardware.

These two are not included in this project repository as they can be installed right from the library manager/boards manager within the Arduino IDE.

Their installation as well as all other steps are explained thoroughly in my comprehensive guides on Confluence:
https://wi-se.hwr-berlin.de/confluence/display/SEW24/Setting+up+Arduino+IDE+in+VM+environment+and+uploading+test+sketch
https://wi-se.hwr-berlin.de/confluence/display/SEW24/Establishing+serial+interface+between+ROS+and+Portenta+H7


Happy Engineering!
