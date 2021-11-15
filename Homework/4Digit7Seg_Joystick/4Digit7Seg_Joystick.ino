//shift register pins
const int dataPin = 12; // DS
const int latchPin =  11; // STCP
const int clockPin = 10; // SHCP
//joystick pins
const int pinSW = 9;
const int pinX = A0;
const int pinY = A1;
bool switchState = LOW;
int xValue = 0;
int yValue = 0;
int minThreshold = 350;
int maxThreshold = 700; 
bool joyMovedX = false;
bool joyMovedY = false;
bool lastSwitchState = LOW;

//display values
int digits[4] = {0, 0, 0, 0}; // cifrele de afisat pe display, in ordine inversa
int points[4] = {0, 0, 0, 0}; // salvez starea pentru decimal point
int activeDisplay = 3;
bool state = 0;
long lastDpTime = 0;
int dpDelay = 300;
int minDigit = 0;
int maxDigit = 9;
//display pins
const int segD1 = 7;
const int segD2 = 6;
const int segD3 = 5;
const int segD4 = 4;

const int displayCount = 4;

const int displayDigits[] = {
  segD1, segD2, segD3, segD4
};

bool registers[8];

int digitArray[16] = {
//A B C D E F G DP 
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110, // 9
  B11101110, // A
  B00111110, // b
  B10011100, // C
  B01111010, // d
  B10011110, // E
  B10001110  // F
};

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(pinSW, INPUT_PULLUP);
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);

  for (int i = 0; i < displayCount; i++) {
    pinMode(displayDigits[i], OUTPUT);
    digitalWrite(displayDigits[i], LOW); 
  }
  Serial.begin(9600);
}

void loop() {
  xValue = analogRead(pinX);
  yValue = analogRead(pinY);
  switchState = digitalRead(pinSW);
  
  if(switchState == LOW && lastSwitchState == HIGH){
    state = !state;
  }
  lastSwitchState = switchState;
  
  if (state == 0){
     if(yValue < minThreshold && joyMovedY == false){
      if(activeDisplay < displayCount - 1){
        points[activeDisplay] = 0;
        activeDisplay++;
      }
      joyMovedY = true;
    }
    if(yValue > maxThreshold && joyMovedY == false){
      if(activeDisplay > 0){
        points[activeDisplay] = 0;
        activeDisplay--;
      }
      joyMovedY = true;
    }
    if (yValue > minThreshold && yValue < maxThreshold){
      joyMovedY = false;
    }
    if(millis() - lastDpTime > dpDelay){
      points[activeDisplay] = !points[activeDisplay];
          lastDpTime = millis();
    }
  }
  //
  if (state == 1){
    points[activeDisplay] = 1;
     if(xValue < minThreshold && joyMovedX == false){
      if(digits[activeDisplay] > minDigit){
        digits[activeDisplay]--;
      }
      joyMovedX = true;
    }
    if(xValue > maxThreshold && joyMovedX == false){
      if(digits[activeDisplay] < maxDigit){
        digits[activeDisplay]++;
      }
      joyMovedX = true;
    }
    if (xValue > minThreshold && xValue < maxThreshold){
      joyMovedX = false;
    }
  }
  //
  writeDigits();
  
//  printFunction();
}

//void writeNumber( long number){
//  long currentNumber = number;
//  //while(currentNumber > 9999){
//    //currentNumber /= 10;
//  //}
//  int displayDigit = 0;
//  int lastDigit;
//  
//  while(currentNumber != 0 && displayDigit < displayCount){
//    lastDigit = currentNumber % 10;
//    showDigit(displayDigit);
//    writeReg(digitArray[lastDigit]);
//    displayDigit ++;
//    currentNumber = currentNumber/ 10;
//    delay(5);
//  }
//  while(displayDigit < displayCount){
//    showDigit(displayDigit);
//    writeReg(digitArray[0]);
//    displayDigit ++;
//    delay(5);
//    
//  }
//}

void printFunction(){
  for(int i = 3; i >= 0; i--){
    Serial.print(i);
    Serial.print(" ");
    Serial.print(digitArray[digits[i]]);
    Serial.print(" ");
    Serial.print(points[i]);
    Serial.println("");
  }
}

void showDigit(int digit) {
  for (int i = 0; i< displayCount; i++){
    digitalWrite(displayDigits[i], HIGH);
  }
  digitalWrite(displayDigits[digit], LOW);
}

void writeReg(int digit, int dpState) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, digit+dpState);
  digitalWrite(latchPin, HIGH);
}

void writeDigits(){
  for(int i = 0; i < displayCount; i++){
    showDigit(i);
    writeReg(digitArray[digits[i]], points[i]);
    delay(5);
  }
}
