//pini
const int buzzerPin = 11;
const int buttonPin = 10;
const int rosuPietPin = 2;
const int verdePietPin = 3;
const int rosuMasPin = 5;
const int galbenMasPin = 6;
const int verdeMasPin = 7;
//constante pentru logica
const int state2Delay = 10000;
const int state2Time = 3000;
const int state3Time = 10000;
const int state3BuzzTime = 200;
const int state4Time = 5000;
const int state4BuzzTime = 100;
const int state4LedTime = 300;
//variabile
int state = 1;
int lastButtonVal = HIGH;
int buttonVal = HIGH;
unsigned long lastBuzz = 0; 
unsigned long lastStateChange = 0;
unsigned long lastLedChange = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(rosuPietPin,OUTPUT);
  pinMode(verdePietPin,OUTPUT);
  pinMode(rosuMasPin,OUTPUT);
  pinMode(galbenMasPin,OUTPUT);
  pinMode(verdeMasPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (state == 1){
    digitalWrite(rosuPietPin, HIGH);
    digitalWrite(verdePietPin, LOW);
    digitalWrite(verdeMasPin, HIGH);
    digitalWrite(galbenMasPin, LOW);
    digitalWrite(rosuMasPin, LOW);
  }
  if (state == 2) {
    if (millis() - lastStateChange > state2Delay){
      if (millis() - lastStateChange > state2Delay + state2Time){
        state = 3;
        lastStateChange = millis();
      } else {
        digitalWrite(rosuPietPin, HIGH);
        digitalWrite(verdePietPin, LOW);
        digitalWrite(verdeMasPin, LOW);
        digitalWrite(galbenMasPin, HIGH);
        digitalWrite(rosuMasPin, LOW);
      }
    }
  }
  if (state == 3){
    if (millis() - lastStateChange > state3Time){
      state = 4;
      lastStateChange = millis();
      noTone(buzzerPin);
      
    }else{
      digitalWrite(verdePietPin, HIGH);
      digitalWrite(rosuPietPin, LOW);
      digitalWrite(verdeMasPin, LOW);
      digitalWrite(galbenMasPin, LOW);
      digitalWrite(rosuMasPin, HIGH);
      if (millis() - lastLedChange > state3BuzzTime){
        noTone(buzzerPin);
      }
      if (millis() - lastLedChange > 2 * state3BuzzTime){
        tone(buzzerPin, 500);
        lastLedChange = millis();
      }
    }
  }
  if (state == 4){
    if (millis() - lastStateChange > state4Time) {
      state = 1;
      lastStateChange = millis();
      noTone(buzzerPin);
    }else {
      if (millis() - lastBuzz > state4BuzzTime){
        noTone(buzzerPin);
      }
      if (millis() - lastBuzz > 2 * state4BuzzTime){
        tone(buzzerPin, 500);
        lastBuzz = millis();
      }
      if (millis() - lastLedChange > state4LedTime){
        digitalWrite(verdePietPin, LOW);
      }
      if (millis() - lastLedChange > 2 * state4LedTime){
        digitalWrite(verdePietPin, HIGH);
        lastLedChange = millis();
      }
    }
  }
  //button
  buttonVal = digitalRead(buttonPin);
  if (buttonVal == LOW){
    if (lastButtonVal == HIGH){
      lastButtonVal = LOW;
      if (state == 1){
        state = 2;
        lastStateChange = millis();
      }
    }
  }else {
    lastButtonVal = HIGH;
  }
  Serial.println("stare: ");
  Serial.println(state);
  Serial.println("timp: ");
  Serial.println(millis() - lastStateChange);
  Serial.println("\n");
}
