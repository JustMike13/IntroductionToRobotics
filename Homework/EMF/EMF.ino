// Aaron ALAI EMF Detector May 28th 2009 VERSION 1.1
// aaronalai1@gmail.com
// contains code for averaging sensor data

#define sample 2000                    //this is how many samples the device takes per reading
                                                        //more information for #define http://arduino.cc/en/Reference/Define
int inPin = 5;                                  //analog 5
float val;                                         //where to store info from analog 5
int pin11 = 11;                              //output of red led

int array1[sample];                      //creates an array with number of elements equal to "sample"
                                                       //more information about arrays http://arduino.cc/en/Reference/Array
const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = 6;
const int pinF = 7;
const int pinG = 8;
const int pinDP = 9;
const int buzzerPin = 11;
const int segSize = 8;
bool dpState = LOW;
const int noOfDigits = 10;
int toneVal = 0;
int segments[segSize] = {
  pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP
};

bool digitMatrix[noOfDigits][segSize-1] ={
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};


void displayNumber(byte digit, bool decimalPoint){
  for(int i = 0; i < segSize - 1; i++){
    digitalWrite(segments[i], digitMatrix[digit][i]);
  }
  digitalWrite(pinDP, decimalPoint);
}

unsigned long averaging;         //the program uses this variable to store the sum of each array it makes


void setup() {
  for (int i = 0; i < segSize; i++) {
    pinMode(segments[i], OUTPUT);
  }
  Serial.begin(9600);
 
}

void loop() {
                   
for(int i = 0; i < sample; i++){              //this code tells the program to fill each element in the array we made with
   array1[i] = analogRead(inPin);       //information from the antenna wire coming out of the Arduino
   averaging += array1[i];                      //more information about for loops http://arduino.cc/en/Reference/For
}                                                               //the averaging line is simply saying: add averaging to whatever is in array position i
                                                                //averaging += array[i] is the same as averaging = averaging + array[i]
                                                                //for more information about += http://arduino.cc/en/Reference/IncrementCompound



val = averaging / sample;                   //here the program takes the sum of all numbers in array1, and divides by the number of elements "sample"

val = constrain(val, 0, 100);               //this constrains the variable value to between two numbers 0 and 100      
    // for one led:                                
    //val = map(val, 0, 100, 0, 255);      //for more information about constrain http://arduino.cc/en/Reference/Constrain  
    //analogWrite(pin11, val);                //the map statement tells the program to map out 0-100 to 0-255, 255 is
                                                              //the threashold of analogWrite for more information about map http://arduino.cc/en/Reference/Map

    // for 7-digit display:
    val = map(val, 0, 100, 0, 9);
    toneVal = val * 100;
    displayNumber(val, dpState);
    if(val = 0){
      noTone(buzzerPin);
    }
    tone(buzzerPin, toneVal);
    averaging = 0;                                 //this line of code sets averaging back to zero so it can be used again
    //delay(300);

}
