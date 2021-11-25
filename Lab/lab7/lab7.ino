#include <LiquidCrystal.h>

const int RS = 12;
const int enable = 11;
const int d5 = 4;
const int d4 = 5;
const int d6 = 3;
const int d7 = 2;

const int trigPin = 9;
const int echoPin = 10;

long duration = 0;
int distance = 0;
int reading = 0;
String incomingString = "";
int incomingByte = 0;
char incomingChar;
LiquidCrystal lcd(RS,enable, d4, d5, d6, d7);

void setup() {
  lcd.begin(16,2);
  lcd.print("hello, world!");
  lcd.setCursor(0, 1);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0){
    incomingByte = Serial.read();
    incomingChar = (char)incomingByte;
    if(incomingChar != '\n'){
      incomingString += incomingChar;
    }else{
      Serial.println(incomingString);
      incomingString = "";
    }
    
//    Serial.println(incomingChar);
  }
}
