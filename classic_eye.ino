//The white eyes stay fixed, and only the black pupils move.

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void drawEyes(int pupilOffset)
{
  display.clearDisplay();

  // White eye sockets
  display.fillRoundRect(15, 15, 40, 40, 10, WHITE);
  display.fillRoundRect(73, 15, 40, 40, 10, WHITE);

  // Black pupils
  display.fillCircle(35 + pupilOffset, 35, 8, BLACK);
  display.fillCircle(93 + pupilOffset, 35, 8, BLACK);

  display.display();
}

void setup()
{
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    while(1);
  }
}

void loop()
{
  // Look Left
  drawEyes(-8);
  delay(5000);

  // Look Right
  drawEyes(8);
  delay(5000);
}
