#ifndef CONSTANTS_CPP
#define CONSTANTS_CPP

#include <Arduino.h>
#include "Constants.h"
#include "HelloAnimation.h"

char *ssid = "while(TRUE)";
char *password = "breaktheloop";
String weekDays[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
String months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
int buzzerPin = 15;
int vrxPin = 4;
int vryPin = 2;
int swPin = 18;
unsigned char image_wifi_full_bits[] = {0x80,0x0f,0x00,0xe0,0x3f,0x00,0x78,0xf0,0x00,0x9c,0xcf,0x01,0xee,0xbf,0x03,0xf7,0x78,0x07,0x3a,0xe7,0x02,0xdc,0xdf,0x01,0xe8,0xb8,0x00,0x70,0x77,0x00,0xa0,0x2f,0x00,0xc0,0x1d,0x00,0x80,0x0a,0x00,0x00,0x07,0x00,0x00,0x02,0x00,0x00,0x00,0x00};
unsigned char image_wifi_1_bits[] = {0x80,0x0f,0x00,0x60,0x30,0x00,0x18,0xc0,0x00,0x84,0x0f,0x01,0x62,0x30,0x02,0x11,0x40,0x04,0x08,0x87,0x00,0xc4,0x18,0x01,0x20,0x20,0x00,0x10,0x42,0x00,0x80,0x0d,0x00,0x40,0x10,0x00,0x00,0x02,0x00,0x00,0x05,0x00,0x00,0x02,0x00,0x00,0x00,0x00};
unsigned char image_ButtonRight_bits[] = {0x01,0x03,0x07,0x0f,0x07,0x03,0x01};
unsigned char image_wifi_not_connected_bits[] = {0x84,0x0f,0x00,0x68,0x30,0x00,0x10,0xc0,0x00,0xa4,0x0f,0x01,0x42,0x30,0x02,0x91,0x40,0x04,0x08,0x85,0x00,0xc4,0x1a,0x01,0x20,0x24,0x00,0x10,0x4a,0x00,0x80,0x15,0x00,0x40,0x20,0x00,0x00,0x42,0x00,0x00,0x85,0x00,0x00,0x02,0x01};
const unsigned char* hello_animationallArray[85] = {
  hello_animation2_hello_animation,
  hello_animation3_hello_animation,
  hello_animation4_hello_animation,
  hello_animation5_hello_animation,
  hello_animation6_hello_animation,
  hello_animation7_hello_animation,
  hello_animation8_hello_animation,
  hello_animation9_hello_animation,
  hello_animation10_hello_animation,
  hello_animation11_hello_animation,
  hello_animation12_hello_animation,
  hello_animation13_hello_animation,
  hello_animation14_hello_animation,
  hello_animation15_hello_animation,
  hello_animation16_hello_animation,
  hello_animation17_hello_animation,
  hello_animation18_hello_animation,
  hello_animation19_hello_animation,
  hello_animation20_hello_animation,
  hello_animation21_hello_animation,
  hello_animation22_hello_animation,
  hello_animation23_hello_animation,
  hello_animation24_hello_animation,
  hello_animation25_hello_animation,
  hello_animation26_hello_animation,
  hello_animation27_hello_animation,
  hello_animation28_hello_animation,
  hello_animation29_hello_animation,
  hello_animation30_hello_animation,
  hello_animation31_hello_animation,
  hello_animation32_hello_animation,
  hello_animation33_hello_animation,
  hello_animation34_hello_animation,
  hello_animation35_hello_animation,
  hello_animation36_hello_animation,
  hello_animation37_hello_animation,
  hello_animation38_hello_animation,
  hello_animation39_hello_animation,
  hello_animation40_hello_animation,
  hello_animation41_hello_animation,
  hello_animation42_hello_animation,
  hello_animation43_hello_animation,
  hello_animation44_hello_animation,
  hello_animation45_hello_animation,
  hello_animation46_hello_animation,
  hello_animation47_hello_animation,
  hello_animation48_hello_animation,
  hello_animation49_hello_animation,
  hello_animation50_hello_animation,
  hello_animation51_hello_animation,
  hello_animation52_hello_animation,
  hello_animation53_hello_animation,
  hello_animation54_hello_animation,
  hello_animation55_hello_animation,
  hello_animation56_hello_animation,
  hello_animation57_hello_animation,
  hello_animation58_hello_animation,
  hello_animation59_hello_animation,
  hello_animation60_hello_animation,
  hello_animation61_hello_animation,
  hello_animation62_hello_animation,
  hello_animation63_hello_animation,
  hello_animation64_hello_animation,
  hello_animation65_hello_animation,
  hello_animation66_hello_animation,
  hello_animation67_hello_animation,
  hello_animation68_hello_animation,
  hello_animation69_hello_animation,
  hello_animation70_hello_animation,
  hello_animation71_hello_animation,
  hello_animation72_hello_animation,
  hello_animation73_hello_animation,
  hello_animation74_hello_animation,
  hello_animation75_hello_animation,
  hello_animation76_hello_animation,
  hello_animation77_hello_animation,
  hello_animation78_hello_animation,
  hello_animation79_hello_animation,
  hello_animation80_hello_animation,
  hello_animation81_hello_animation,
  hello_animation82_hello_animation,
  hello_animation83_hello_animation,
  hello_animation84_hello_animation,
  hello_animation85_hello_animation,
  hello_animation86_hello_animation
};
const int framesInHelloAnimation = 85;
int frameRate = 10;

#endif
