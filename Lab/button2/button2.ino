const int pinButton = 2;
const int pinLed = 11;

int counter = 0;
int ledState = LOW;
bool buttonState = LOW;
bool previousState = HIGH;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(pinButton);
  ledState = !buttonState;
  digitalWrite(pinLed, ledState);
  
}
