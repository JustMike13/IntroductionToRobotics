const int ledPinR = 11;
const int ledPinG = 10;
const int ledPinB = 9;
const int potPinR = A0;
const int potPinG = A1;
const int potPinB = A2;
int potValueR = 0;
int potValueG = 0;
int potValueB = 0;

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
  potValueR = analogRead(potPinR);
  potValueG = analogRead(potPinG);
  potValueB = analogRead(potPinB);
  analogWrite(ledPinR, potValueR/4);
  analogWrite(ledPinG, potValueG/4);
  analogWrite(ledPinB, potValueB/4);
}
