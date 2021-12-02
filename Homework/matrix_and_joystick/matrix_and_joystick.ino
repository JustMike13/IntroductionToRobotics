#include "LedControl.h" //  need the library
//#include <ctime>
const int dinPin = 12;
const int clockPin = 11;
const int loadPin = 10;
const int rows = 8;
const int cols = 8;
LedControl lc = LedControl(dinPin, clockPin, loadPin, 1); //DIN, CLK, LOAD, No. DRIVER

int col = 0, row = 0, oldCol = 0, oldRow = 0;
//joystick pins
const int pinSW = 2;
const int pinX = A0;
const int pinY = A1;
//joystick values
bool switchState = LOW;
int xValue = 0;
int yValue = 0;
int minThreshold = 350;
int maxThreshold = 700; 
bool joyMovedX = false;
bool joyMovedY = false;
bool lastSwitchState = LOW;

long lastButtonPress = 0;
const long buttonPressDelay = 200;


int blinkLed = -1;
int blinkState = 1;
int blinkDelay = 200;
int blinkRow = 0;
int blinkCol = 0;
long lastBlink = 0;
// pin 12 is connected to the MAX7219 pin 1
// pin 11 is connected to the CLK pin 13
// pin 10 is connected to LOAD pin 12
// 1 as we are only using 1 MAX7219
 
void setup()
{
  // the zero refers to the MAX7219 number, it is zero for 1 chip
  lc.shutdown(0, false); // turn off power saving, enables display
  lc.setIntensity(0, 2); // sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen
  pinMode(pinSW, INPUT_PULLUP);
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  Serial.begin(9600);
}

void blinkFunction(int x){
  blinkRow = x/8;
  blinkCol = x%8;
  lc.setLed(0, blinkRow, blinkCol, blinkState);
  if(millis() - lastBlink > blinkDelay){
    blinkState = !blinkState;
    lastBlink = millis();
  }
  if(blinkRow == row && blinkCol == col){
    blinkLed = -1;
    lc.setLed(0, blinkRow, blinkCol, false);
  }
}

void loop()
{
  lc.setLed(0, row, col, true); // turns on LED at col, row
  oldRow = row;
  oldCol = col;
  xValue = analogRead(pinX);
  yValue = analogRead(pinY);
  switchState = digitalRead(pinSW);

  if(yValue < minThreshold && joyMovedY == false){
      if(col > 0)
        col -= 1;
      joyMovedY = true;
    }
    if(yValue > maxThreshold && joyMovedY == false){
      if(col < 7)
        col += 1;
      joyMovedY = true;
    }
    if (yValue > minThreshold && yValue < maxThreshold){
      joyMovedY = false;
    }
    if(xValue < minThreshold && joyMovedX == false){
      if(row < 7)
        row += 1;
      joyMovedX = true;
    }
    if(xValue > maxThreshold && joyMovedX == false){
      if(row > 0)
        row -= 1;
      joyMovedX = true;
    }
    if (xValue > minThreshold && xValue < maxThreshold){
      joyMovedX = false;
    }

    if(blinkLed == -1){
      blinkLed = random(0,50); // numar random intre 0 si 63
    }
    blinkFunction(blinkLed);
    
    
    lc.setLed(0, oldRow, oldCol, false);
}
