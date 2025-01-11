#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Arduino.h>

extern char *ssid;
extern char *password;
extern String weekDays[7];
extern String months[12];
extern int buzzerPin;
extern int vrxPin;
extern int vryPin;
extern int swPin;
extern unsigned char image_wifi_full_bits[];
extern unsigned char image_wifi_1_bits[];
extern unsigned char image_ButtonRight_bits[];
extern unsigned char image_wifi_not_connected_bits[];
extern const unsigned char* hello_animationallArray[85];
extern const int framesInHelloAnimation;
extern int frameRate;

#endif
