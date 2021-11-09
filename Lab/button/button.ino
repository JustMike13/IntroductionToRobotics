const int pinButton = 2;

int counter = 0;
bool buttonState = LOW;
bool previousState = HIGH;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinButton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(pinButton);
  if (previousState != buttonState && buttonState == HIGH){
    counter ++;
  }
    previousState = buttonState;
  Serial.println(counter);
  delay(1);
}
