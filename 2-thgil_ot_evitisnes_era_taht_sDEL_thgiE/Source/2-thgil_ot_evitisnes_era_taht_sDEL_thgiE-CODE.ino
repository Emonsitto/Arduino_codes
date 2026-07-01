
// date: 6/30/2026
// 2-thgil_ot_evitisnes_era_taht_sDEL_thgiE by: Arz0n (It's inverted :o)

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
  int numLEDSLit = map(reading, 100, 460, 8, 0); // Automatically invert and perfectly scale my room's actual light levels.

  if (numLEDSLit > 8 ) numLEDSLit = 8;   // Cap the value to prevent bit-shifting past 8 bits
  if (numLEDSLit < 0 ) numLEDSLit = 0;   // Cap the value to prevent bit-shifting past 0 bits
  
  leds = 0;   // Reset pattern
  
  for (int i = 0; i < numLEDSLit; i++)
  {
    leds = leds + (1 << i);  
  }
  
  updateShiftRegister();
}

//code inspired from the elegoo super starter kit
