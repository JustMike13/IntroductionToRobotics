//pini
const int buzzerPin = 11;
const int buttonPin = 10;
const int rosuPietPin = 2;
const int verdePietPin = 3;
const int rosuMasPin = 5;
const int galbenMasPin = 6;
const int verdeMasPin = 7;
//constante pentru logica
const int state3Time = 10000;
const int state3BuzzTime = 200;
//variabile
int state = 1;
int lastButtonVal = HIGH;
int buttonVal = HIGH;
unsigned int lastBuzz = 0; 
unsigned int lastStateChange = 0;
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
    digitalWrite(rosuMasPin, LOW);
  }
  if (state == 3){
    if (millis() - lastStateChange > state3Time){
      state = 1;
      noTone(buzzerPin);
      
    }else{
      digitalWrite(verdePietPin, HIGH);
      digitalWrite(rosuPietPin, LOW);
      digitalWrite(verdeMasPin, LOW);
      digitalWrite(rosuMasPin, HIGH);
      if (millis() - lastBuzz > state3BuzzTime){
        noTone(buzzerPin);
      }
      if (millis() - lastBuzz > 2 * state3BuzzTime){
        tone(buzzerPin, 500);
        lastBuzz = millis();
      }
    }
  }
  //button
  buttonVal = digitalRead(buttonPin);
  if (buttonVal == LOW){
    if (lastButtonVal == HIGH){
      lastButtonVal = LOW;
      if (state == 1){
        state = 3;
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
