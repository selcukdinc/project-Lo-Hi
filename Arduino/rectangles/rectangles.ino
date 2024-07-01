#include <OLED_I2C.h>

OLED myOLED(SDA, SCL);

//extern uint8_t SmallFont[];
int x = 0, y = 0;
void setup() {
  // put your setup code here, to run once:
  if(!myOLED.begin(SSD1306_128X64))
    while(1);

  //myOLED.setFont(SmallFont);

}

void loop() 
{
  myOLED.clrScr();
  myOLED.drawRect(x, y, x+4, y+4);
  if(x >= 122){
    x = 0;
    if(y >= 56)
      y = 0;
    else
      y+= 4;
  }
  myOLED.update();
  //delay (5);
  x += 1;
}