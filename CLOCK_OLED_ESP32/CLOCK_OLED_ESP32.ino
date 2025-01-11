#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <U8g2lib.h>
#include "Utils.cpp" 
#include "Constants.h"

State productState = WELCOME_SCREEN;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

int frame = 0;
unsigned long lastFrame = 0;
bool isWiFiConnected = false;

unsigned long button_time = 0;  
unsigned long last_button_time = 0; 

void wifiConnect() {
  WiFi.begin(ssid, password);

  while (frame != framesInHelloAnimation) {
    if (millis() - lastFrame >= (1000 / frameRate)) {
      u8g2.clearBuffer();
      lastFrame = millis();
      u8g2.drawXBMP(0, 0, 128, 64, hello_animationallArray[frame]); 
      u8g2.sendBuffer();
      frame++;
    }
  }
  
  while (WiFi.status() != WL_CONNECTED) {
    u8g2.clearBuffer();
    u8g2.setFontMode(1);
    u8g2.setBitmapMode(1);
    u8g2.setFont(u8g2_font_profont22_tr);
    u8g2.drawStr(35, 21, "Can't");
    u8g2.drawStr(31, 58, "WiFi");
    u8g2.drawStr(5, 38, "connect to");
    u8g2.drawXBM(83, 43, 19, 15, image_wifi_not_connected_bits);
    u8g2.sendBuffer();
  }
}

void drawCenteredText(const char *text, const uint8_t *font, int yOffset = 0, bool isHighleted = false) {
  u8g2.setFont(font);

  int textWidth = u8g2.getStrWidth(text);
  int textHeight = u8g2.getAscent() - u8g2.getDescent();

  int xPosition = (u8g2.getDisplayWidth() - textWidth) / 2;
  int yPosition = (u8g2.getDisplayHeight() + textHeight) / 2 + yOffset;

  // if (y != -1) {
  //   yPosition = y;
  // }

  u8g2.drawStr(xPosition, yPosition, text);

  if (isHighleted) {
    u8g2.setDrawColor(2);
    u8g2.drawRBox(xPosition - 5, yPosition - 12, textWidth + 8, textHeight + 4, 2);
    // u8g2.setDrawColor(1);
  }
}

unsigned long lastPixelDrawn = 0;


void clockDisplay() {
  timeClient.update();

  int currentHour = timeClient.getHours();
  int currentMinute = timeClient.getMinutes();
  int currentSecond = timeClient.getSeconds();
  String am_pm = (currentHour < 12) ? "AM" : "PM";
  
  if (currentHour == 0) {
    currentHour = 12;
  } else if (currentHour > 12) {
    currentHour -= 12;
  }

  String weekDay = weekDays[timeClient.getDay()];
  time_t epochTime = timeClient.getEpochTime();
  struct tm *ptm = gmtime(&epochTime);
  int monthDay = ptm->tm_mday;
  int currentMonth = ptm->tm_mon + 1;
  String currentMonthName = months[currentMonth - 1];
  int currentYear = ptm->tm_year + 1900;

  char timeBuffer[20];
  sprintf(timeBuffer, "%02d:%02d %s", currentHour, currentMinute, am_pm.c_str());

  char dateBuffer[30];
  sprintf(dateBuffer, "%s, %d-%s", weekDay.c_str(), monthDay, currentMonthName.c_str());
  // drawCenteredText(timeBuffer, u8g2_font_profont22_tr, -2);//u8g2_font_timR24_tr
  drawCenteredText(timeBuffer, u8g2_font_logisoso24_tf, -7);//u8g2_font_timR24_tr

  drawCenteredText(dateBuffer, u8g2_font_t0_13b_tr, u8g2.getAscent() - u8g2.getDescent() -8, true);
  u8g2.setCursor(115, 10);
  u8g2.setFont(u8g2_font_t0_13_tr);
  // u8g2.print(currentSecond);

  // drawing a line for showing how many seconds left
  // u8g2.drawBox(1, 1, map(currentSecond, 0, 59, 2, 126), 3);
  // u8g2.drawFrame(0, 0, 128, 5);
  u8g2.setFontMode(1);
  u8g2.setBitmapMode(1);
  u8g2.setDrawColor(1);
  u8g2.drawRBox(1, 1, map(currentSecond, 0, 59, 7, 126),  6, 2);
  u8g2.drawRFrame(0, 0, 128, 8, 3);

  // u8g2.setFont(u8g2_font_helvB08_tr);
  // drawCenteredText("LSK", u8g2_font_helvB08_tr, -28);
  // u8g2.drawXBM(45, 1, 4, 7, image_ButtonRight_bits);
  
  // if (currentSecond <= 10) {
  //   u8g2.drawLine(0, 63, 0, 0);
  // } else if (currentSecond <= 30) {
  //   u8g2.drawLine(0, 63, 0, 0);
  //   u8g2.drawLine(1, 63, 127, 64);
  // } else if (currentSecond <= 40) {
  //   u8g2.drawLine(0, 63, 0, 0);
  //   u8g2.drawLine(1, 63, 127, 63);
  //   u8g2.drawLine(127, 1, 127, 63);
  // } else if (currentSecond <= 60) {
  //   u8g2.drawLine(0, 63, 0, 0);
  //   u8g2.drawLine(1, 63, 127, 63);
  //   u8g2.drawLine(127, 1, 127, 63);
  //   u8g2.drawLine(0, 0, 128, 0);
  // }
}

void setup() {
  Serial.begin(9600);

  u8g2.begin();
  u8g2.setBusClock(400000);

  wifiConnect();

  productState = CLOCK;

  timeClient.begin();
  timeClient.setTimeOffset(19800);
}

void loop() {
  u8g2.clearBuffer();
  
  switch (productState) {
    case WELCOME_SCREEN:
      break;
    case NOT_CONNECTED_TO_WIFI:
      break;
    case CLOCK:
      clockDisplay();
      break;
    case STOPWATCH:
      break;
    default:
      break;
  }

  u8g2.sendBuffer();
}
