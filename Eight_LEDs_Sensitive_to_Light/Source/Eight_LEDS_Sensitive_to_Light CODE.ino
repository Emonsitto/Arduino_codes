
// date: 6/29/2026
// Eight_LEDs_that_are_sensitive_to_light by: Arz0n (these names are getting hard 😭)

// Hardware connections
int lightPin = A0;      //Analog pin 0 from the Arduino goes to the photocell
int latchPin = 11;    //Digital pin 11 from the Arduino goes to pin #12 of the 74HC595 shift register
int clockPin = 9;     //Digital pin 9 from the Arduino goes to pin #11 of the 74HC595 shift register
int dataPin = 12;     //Digital pin 12 from the Arduino goes to pin #14 of the 74HC595 shift register
int leds = 0;           //Define variable 'leds' as type 'int'

void setup() 
{
  //set all pins as outputs
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}

void loop() 
{
  // Calculate how many LEDs to turn on based on light levels
  int reading  = analogRead(lightPin);
  int numLEDSLit = reading / 57;  // Scale 0-1023 analog range down to 0-8 (57 lol)
  
  // Cap the value to prevent bit-shifting past 8 bits
  if (numLEDSLit > 8) numLEDSLit = 8;
  
  leds = 0;   // Reset pattern
  
  for (int i = 0; i < numLEDSLit; i++)
  {
    leds = leds + (1 << i);  
  }
  
  updateShiftRegister();
}

//code inspired from the elegoo super starter kit
