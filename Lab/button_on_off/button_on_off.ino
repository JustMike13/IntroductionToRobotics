const int buttonPin = 2;
const int pinLed = 11;

int ledState = LOW;
bool buttonState = LOW;
bool previousState = HIGH;

int reading = HIGH;
int previousReading = HIGH;
unsigned int lastDebounceTime = 0; 
unsigned int debounceDelay = 50; 
void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  reading = digitalRead(buttonPin);
  if(reading != previousReading){
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime > debounceDelay){
    if (reading != buttonState){
      buttonState = reading;
      if (buttonState == HIGH){
        ledState = !ledState;
        digitalWrite(pinLed, ledState);
      }
      
    }
  }

  previousReading = reading;
}
