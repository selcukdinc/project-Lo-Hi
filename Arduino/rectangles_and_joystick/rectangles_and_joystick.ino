#include <OLED_I2C.h>

const int X_pin = 3;
const int Y_pin = 2;
int step = 1;

int startX1 = 61, startY1 = 29, startX2 = 65, startY2 = 33; // center of screen
OLED myOLED(SDA, SCL);

extern uint8_t SmallFont[];
int x = 0, y = 0;
void setup() {
  if(!myOLED.begin(SSD1306_128X64))
    while(1);

  myOLED.setFont(SmallFont);
  
}

void loop() 
{
  myOLED.clrScr();
  int x_value = analogRead(X_pin);
  int y_value = analogRead(Y_pin);
  int delayTime = 15;
  String result = "x : " + String(x_value) + "  y : " + String(y_value);
  myOLED.print(result, CENTER, 0);
  //myOLED.drawRect(123, 59, 127, 63); // max values : x : 127 , y : 63

  myOLED.drawRect(startX1, startY1, startX2, startY2);

  if(x_value < 50 || x_value > 1000 || y_value < 50 || y_value > 1000)
  {
    step = 4;
  }    
  else
  {
    step = 1;
  } 
  

  if(x_value < 250 && startY1 > 0)
  {// movement to up
    startY1 -= step;
    startY2 -= step;
  }
  else if (x_value > 600 && startY1 < 59)
  {
    startY1 += step;
    startY2 += step;
  }

  if(y_value < 250 && startX1 < 123)
  {
    startX1 += step;
    startX2 += step;
  }
  else if (y_value > 750 && startX1 > 0)
  {
    startX1 -= step;
    startX2 -= step;
  }

  myOLED.update();
  
}
