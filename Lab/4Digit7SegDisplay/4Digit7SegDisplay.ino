const int dataPin = 12; // DS
const int latchPin =  11; // STCP
const int clockPin = 10; // SHCP

const int segD1 = 7;
const int segD2 = 6;
const int segD3 = 5;
const int segD4 = 4;

const int displayCount = 4;

const int displayDigits[] = {
  segD1, segD2, segD3, segD4
};

bool registers[8];

int digitArray[16] = {
//A B C D E F G DP 
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110, // 9
  B11101110, // A
  B00111110, // b
  B10011100, // C
  B01111010, // d
  B10011110, // E
  B10001110  // F
};

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  for (int i = 0; i < displayCount; i++) {
    pinMode(displayDigits[i], OUTPUT);
    digitalWrite(displayDigits[i], LOW); 
  }
  Serial.begin(9600);
}

void loop() {
  writeNumber(567);
  
}

void writeNumber( long number){
  long currentNumber = number;
  //while(currentNumber > 9999){
    //currentNumber /= 10;
  //}
  int displayDigit = 0;
  int lastDigit;
  
  while(currentNumber != 0 && displayDigit < displayCount){
    lastDigit = currentNumber % 10;
    showDigit(displayDigit);
    writeReg(digitArray[lastDigit]);
    displayDigit ++;
    currentNumber = currentNumber/ 10;
    delay(5);
  }
  while(displayDigit < displayCount){
    showDigit(displayDigit);
    writeReg(digitArray[0]);
    displayDigit ++;
    delay(5);
    
  }
}

void showDigit(int digit) {
  for (int i = 0; i< displayCount; i++){
    digitalWrite(displayDigits[i], HIGH);
  }
  digitalWrite(displayDigits[digit], LOW);
}

void writeReg(int digit) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, digit);
  digitalWrite(latchPin, HIGH);
}
