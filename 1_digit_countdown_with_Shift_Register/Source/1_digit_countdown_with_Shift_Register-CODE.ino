
// date: 7/2/2026
// 1-digit_countdown_with_Shift-Register by: Arz0n

// define the LED digit patterns, from 0 - 9
byte seven_seg_digits[10] = { 
  B11111100,  // 0
  B01100000,  // 1
  B11011010,  // 2
  B11110010,  // 3
  B01100110,  // 4
  B10110110,  // 5
  B10111110,  // 6
  B11100000,  // 7
  B11111110,  // 8
  B11100110   // 9
};
 
 
int latchPin = 3;    //Digital pin 3 from the Arduino goes to pin #12 of the 74HC595 shift register
int clockPin = 4;    //Digital pin 4 from the Arduino goes to pin #11 of the 74HC595 shift register
int dataPin = 2;     //Digital pin 2 from the Arduino goes to pin #14 of the 74HC595 shift register
 
void setup() {
  // Set  all pins to outputs
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
 
// display a number on the digital segment display
void sevenSegWrite(byte digit) {
  digitalWrite(latchPin, LOW);  // set the latchPin to low potential, before sending data
  shiftOut(dataPin, clockPin, LSBFIRST, seven_seg_digits[digit]);    // the original data (bit pattern)
  digitalWrite(latchPin, HIGH);  // set the latchPin to high potential, after sending data
}
 
void loop() {       
  // count from 9 to 0
  delay(1000);
  for (byte digit = 10; digit > 0; --digit) {
    delay(1000);
    sevenSegWrite(digit - 1); 
  }
  // count from 0 to 9
  delay(1000);
  for (byte digit = 0; digit < 9; ++digit) {
    delay(1000);
    sevenSegWrite(digit + 1); 
  }
}

//code inspired from the elegoo super starter kit
//I kinda forgot to publish the code on July 7th, sorry
