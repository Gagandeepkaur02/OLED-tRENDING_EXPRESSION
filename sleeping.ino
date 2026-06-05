#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void drawSleepFrame(int h)
{
  display.clearDisplay();

  // Relaxed eyebrows
  for(int i=0;i<3;i++)
  {
    display.drawLine(15,18+i,50,22+i,WHITE);
    display.drawLine(78,22+i,113,18+i,WHITE);
  }

  // Eyelids
  display.fillRoundRect(15,30,40,h,4,WHITE);
  display.fillRoundRect(73,30,40,h,4,WHITE);

  display.display();
}

void sleeping1()
{
  display.clearDisplay();

  // Eyebrows
  for(int i=0;i<3;i++)
  {
    display.drawLine(15,18+i,50,22+i,WHITE);
    display.drawLine(78,22+i,113,18+i,WHITE);
  }

  // Closed eyes
  display.fillRoundRect(15,32,40,4,2,WHITE);
  display.fillRoundRect(73,32,40,4,2,WHITE);

  display.setTextSize(2);
  display.setTextColor(WHITE);

  display.setCursor(95,5);
  display.print("Z");

  display.display();
}

void sleeping2()
{
  display.clearDisplay();

  for(int i=0;i<3;i++)
  {
    display.drawLine(15,18+i,50,22+i,WHITE);
    display.drawLine(78,22+i,113,18+i,WHITE);
  }

  display.fillRoundRect(15,32,40,4,2,WHITE);
  display.fillRoundRect(73,32,40,4,2,WHITE);

  display.setTextSize(2);
  display.setCursor(100,5);
  display.print("Z");

  display.setTextSize(1);
  display.setCursor(88,18);
  display.print("z");

  display.display();
}

void sleeping3()
{
  display.clearDisplay();

  for(int i=0;i<3;i++)
  {
    display.drawLine(15,18+i,50,22+i,WHITE);
    display.drawLine(78,22+i,113,18+i,WHITE);
  }

  display.fillRoundRect(15,32,40,4,2,WHITE);
  display.fillRoundRect(73,32,40,4,2,WHITE);

  display.setTextSize(2);
  display.setCursor(105,5);
  display.print("Z");

  display.setTextSize(1);
  display.setCursor(92,18);
  display.print("z");

  display.setCursor(82,28);
  display.print("z");

  display.display();
}

void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop()
{
  // Eyes slowly close
  for(int h=24; h>=4; h-=2)
  {
    drawSleepFrame(h);
    delay(70);
  }

  // Sleep animation
  for(int i=0;i<6;i++)
  {
    sleeping1();
    delay(300);

    sleeping2();
    delay(300);

    sleeping3();
    delay(300);
  }

  // Wake up slowly
  for(int h=4; h<=24; h+=2)
  {
    drawSleepFrame(h);
    delay(70);
  }

  delay(2000);
}
