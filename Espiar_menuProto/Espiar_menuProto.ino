#include "SevenSegmentTM1637.h"

const byte PIN_CLK = 12;
const byte PIN_DIO = 13;
const byte POT = 0;
char c = 0;
int pot = 0;
SevenSegmentTM1637 display(PIN_CLK, PIN_DIO);


int value = 0;
int channel = 14;

enum {minMenu, mainMenu, channelMenu, valueMenu, maxMenu} currentMenu;

void setup() {

  Serial.begin(9600);         
  display.begin();            
  display.setBacklight(100);  
  display.print("INIT");      
  delay(100);
}

void channelAction() {
  Serial.print("CHAN");
  display.print("CHAN");
  channel = map(pot, 0, 4096, 0, 512);
}

void valueAction() {
  Serial.print("VAL");
  display.print("VAL");
  value = map(pot, 0, 4096, 0, 255);
}

void navigating(){
  if (Serial.available()) {
    char c = Serial.read();
    Serial.print((int) c);
    switch (c)
      case 1:
        currentMenu = currentMenu + 1;
      case 2:
        currentMenu = currentMenu - 1;
      default:
        delay(10);
  }
}

void updateMenu() {
  switch (currentMenu) {
    
    case minMenu:
      currentMenu = mainMenu;
     break;

    case mainMenu:
      display.print ("MAIN");
      Serial.println("Main Menu");
     break;
    
    case channelMenu:
      display.print("C");
      delay(10);
      display.print(channel);
      delay(10);
      Serial.println("C ");
      Serial.print(channel);
      channelMenu();
     break;
    
    case valueMenu:
      display.print("V");
      delay(10);
      display.print(value);
      delay(10);
      Serial.println("V ");
      Serial.print(channel);
      valueMenu();
     break;
      
    case maxMenu:
      currentMenu = valueMenu;
      break;
  }
}

void loop() {
  pot = analogRead(POT)
  updateMenu();
