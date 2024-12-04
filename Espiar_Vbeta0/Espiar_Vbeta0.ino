#include "SevenSegmentTM1637.h"
const byte PIN_CLK = 12;   // define CLK pin (any digital pin)
const byte PIN_DIO = 13;   // define DIO pin (any digital pin)
SevenSegmentTM1637    display(PIN_CLK, PIN_DIO);

// run setup code
void setup() {
  Serial.begin(9600);         // initializes the Serial connection @ 9600 baud
  display.begin();            // initializes the display
  display.setBacklight(100);  // set the brightness to 100 %
  display.print("INIT");      // display INIT on the display
  delay(1000);                // wait 1000 ms
};

// run loop (forever)
void loop() {
  display.print("LOOP");                // display LOOP on the display
  delay(1000);                          // wait 1000 ms
  display.print("COUNTING SOME DIGITS");// print COUNTING SOME DIGITS
  display.clear();                      // clear the display
  for (uint8_t i=0; i < 100; i++) {     // loop from 0 to 100x
    display.print(i);                   // display loop counter
    delay(100);                         // wait 100 ms
  };
  display.clear();                      // clear the display
  display.print("SUCC");                // print SUCC for success
  display.blink();                      // blink SUCC
  delay(1000);                          // wait 1000 ms
};