#include "Led.h"

LedLib leds1(10, false);  // pin, if debug info
LedLib led2(11, true);    // pin, if debug info

void setup()
{
  leds1.start_db(9600);    // start leds1 debug with baud rate of 9600
  led2.start_db();         // start led2  debug with baud rate of default = 9600
}

void loop()
{
  leds1.blk(300);             // led blink funktion
  delay(500);
  leds1.on(30);               // pwm pin on 30
  delay(500);
  leds1.off();                // turns led off
  delay(500);
  led2.fade(200, 2, false);   // fades led from 200 to 0
  led2.fade(0, 1, true);      // fades led from 0 to 255 
  led2.fade(100, 5, false);   // fades led from 100 to 0
  led2.say();                 // test with a function in a function
  delay(500);
}
