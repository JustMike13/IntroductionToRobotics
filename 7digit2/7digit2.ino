const int pinSW = 10;
const int pinX = A0;
const int pinY = A1;

bool switchState = LOW;
int xValue = 0;
int yValue = 0;

bool joyMoved = false;

const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = 6;
const int pinF = 7;
const int pinG = 8;
const int pinDP = 9;

bool lastSwitchState = LOW;
const int segSize = 8;
bool dpState = LOW;
bool state = HIGH;
const int noOfDigits = 10;
int index = 0;

int minThreshold = 350;
int maxThreshold = 700; 

int segments[segSize] = {
  pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP
};

bool digitMatrix[noOfDigits][segSize-1] ={
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void displayNumber(byte digit, bool decimalPoint){
  for(int i = 0; i < segSize - 1; i++){
    digitalWrite(segments[i], digitMatrix[digit][i]);
  }
  digitalWrite(pinDP, decimalPoint);
}

void setup() {
  for (int i = 0; i < segSize; i++) {
    pinMode(segments[i], OUTPUT);
  }
  pinMode(pinSW, INPUT_PULLUP);
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  Serial.begin(9600);
}

void loop() {
  xValue = analogRead(pinX);
  yValue = analogRead(pinY);
  switchState = digitalRead(pinSW);
  
  if(switchState == LOW && lastSwitchState == HIGH){
    dpState = !dpState;
  }
    lastSwitchState = switchState;
  
  if(xValue > maxThreshold && joyMoved == false){
    index ++;
    joyMoved = true;
  }
  if(xValue < minThreshold && joyMoved == false){
    index --;
    joyMoved = true;
  }
  if(index > 9){
    index = 0;
  }
  if(index < 0){
    index = 9;
  }
  if (xValue > minThreshold && xValue < maxThreshold){
    joyMoved = false;
  }
  displayNumber(index, dpState);
  delay(200);
  
}
