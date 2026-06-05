// classic eye with thin eyebrow and angry face

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void drawEyes(int pupilOffset)
{
  display.clearDisplay();

  // Eye sockets
  display.fillRoundRect(15, 18, 40, 32, 8, WHITE);
  display.fillRoundRect(73, 18, 40, 32, 8, WHITE);

  // Pupils
  display.fillCircle(35 + pupilOffset, 34, 7, BLACK);
  display.fillCircle(93 + pupilOffset, 34, 7, BLACK);

  // Left eyebrow
  display.drawLine(10, 12, 55, 18, WHITE);

  // Right eyebrow
  display.drawLine(73, 18, 118, 12, WHITE);

  display.display();
}

void setup()
{
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    while (1);
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
