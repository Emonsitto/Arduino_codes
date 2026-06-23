
// date: 6/23/2026
// Eight-LEDs-With-Shift-Register(8LWSR) by: Arz0n

int latchPin = 11;    //Digital pin 11 from the Arduino goes to pin #12 of the 74HC595 shift register
int clockPin = 9;     //Digital pin 9 from the Arduino goes to pin #11 of the 74HC595 shift register
int dataPin = 12;     //Digital pin 12 from the Arduino goes to pin #14 of the 74HC595 shift register
byte leds = 0;        //Define variable 'leds' as type 'byte', which represents numbers using eight bits, and there's eight leds

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW); // Pull latch low to start data transmission
   shiftOut(dataPin, clockPin, LSBFIRST, leds); // Shift out the 'leds' byte (LSB first) using the defined Data and Clock pins
   digitalWrite(latchPin, HIGH); // Pull latch high to lock the data and update the outputs
}

void setup() 
{
  //set all pins as outputs
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() 
{
  updateShiftRegister(); // run function 'updateShiftRegister', which was defined before
  delay(100); //wait 100 ms
  for (int i = 0; i < 8; i++) // create a for loop, in which most of the important stuff happens
  {
    bitSet(leds, i);
    updateShiftRegister();
    delay(200);
  }
  leds = 0; //Make variable led's value 0 
}

//code inspired from the elegoo super starter kit
