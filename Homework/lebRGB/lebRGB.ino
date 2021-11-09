const int ledPinR = 11;
const int ledPinG = 10;
const int ledPinB = 9;
const int potPinR = A0;
const int potPinG = A1;
const int potPinB = A2;
const int maxAnalogValue = 1023;
const int maxDigitalValue = 255;
int potValueR = 0;
int potValueG = 0;
int potValueB = 0;
int RValue;
int GValue;
int BValue;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinB, OUTPUT);
  pinMode(potPinR, INPUT);
  pinMode(potPinG, INPUT);
  pinMode(potPinB, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read potentiometer value
  potValueR = analogRead(potPinR);
  potValueG = analogRead(potPinG);
  potValueB = analogRead(potPinB);
  // map value from (0,1023) to (0,255)
  RValue = map(potValueR,0,maxAnalogValue,0,maxDigitalValue);
  GValue = map(potValueG,0,maxAnalogValue,0,maxDigitalValue);
  BValue = map(potValueB,0,maxAnalogValue,0,maxDigitalValue);
  // send value to LED
  analogWrite(ledPinR, RValue);
  analogWrite(ledPinG, GValue);
  analogWrite(ledPinB, BValue);
}
