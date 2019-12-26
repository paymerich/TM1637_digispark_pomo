 /*
 * This is the Arduino code for TM1637 4 digits display.
 *  * 
 * Written by Ahmad S. for Robojax Video
 * Date: Dec 06, 2017, in Ajax, Ontario, Canada
 * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 * 
 */

/*
 * Original code from https://github.com/avishorp/TM1637
 * Modified for Robojax video on Dec 06, 2017

 */
#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 0

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000

#define setTimer 1500

TM1637Display display(CLK, DIO);

#define button 3
#define gnd 4

int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {                
  pinMode (button, INPUT);
  digitalWrite (button, HIGH); // enable pullup
  pinMode(gnd, OUTPUT);
  digitalWrite (gnd, LOW); // use this pin as a ground
}

void loop()
{


  display.setBrightness(0x0f);

  uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
  display.setSegments(data);
//  display.showNumberDec(023, false, 2,0);
//  delay(TEST_DELAY);
  
  display.setSegments(data);
  display.showNumberDec(9153, false, 4, 0);
  delay(TEST_DELAY);

  display.setSegments(data);
  for(int i=setTimer; i>= 0; i--)
  {
      buttonState = digitalRead(button);
     if (buttonState == LOW) {i=setTimer;}
     display.showNumberDec(i,true,4,0); 
    
    delay(1000);
  }

}
   
