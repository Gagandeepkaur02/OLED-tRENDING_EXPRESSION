#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void animeFace(int eyeOffset)
{
  display.clearDisplay();

  // Happy Eyebrows
  for(int i=0; i<3; i++)
  {
    display.drawLine(18,18-i,48,14-i,WHITE);
    display.drawLine(80,14-i,110,18-i,WHITE);
  }

  // Left Eye
  display.fillRoundRect(15,20,40,28,12,WHITE);

  // Right Eye
  display.fillRoundRect(73,20,40,28,12,WHITE);

  // Pupils
  display.fillCircle(35 + eyeOffset,34,8,BLACK);
  display.fillCircle(93 + eyeOffset,34,8,BLACK);

  // Eye shine
  display.fillCircle(32 + eyeOffset,30,2,WHITE);
  display.fillCircle(90 + eyeOffset,30,2,WHITE);

  display.fillCircle(38 + eyeOffset,38,1,WHITE);
  display.fillCircle(96 + eyeOffset,38,1,WHITE);

  // Cute smile
  display.drawLine(58,55,70,55,WHITE);
  display.drawPixel(57,54,WHITE);
  display.drawPixel(71,54,WHITE);

  display.display();
}

void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop()
{
  // Look left
  animeFace(-3);
  delay(1000);

  // Center
  animeFace(0);
  delay(1000);

  // Look right
  animeFace(3);
  delay(1000);

  // Center
  animeFace(0);
  delay(1000);
}
