// any button press (no matter how long) changes the state of the LED (ON/OFF)
// releasing the button does not change the state

const int buttonPin = 2;
const int ledPin = 13;

int buttonState = 0;
int pressedDown = 0; 
int ledState = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  Serial.print("button: ");
  Serial.print(buttonState);
  Serial.print(" pressedDown: ");
  Serial.print(pressedDown);
  Serial.print("\n");
  if (buttonState) {
    if (pressedDown == 0){
      pressedDown = 1;
      if (ledState == LOW){
        ledState = HIGH;
      }else{
        ledState = LOW;
      }
    }
  } else {
    pressedDown = 0;
  }
  digitalWrite(ledPin, ledState);
}
