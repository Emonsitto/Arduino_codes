
// date: 7/10/2026
// Stepper Motor With Remote part 2 by: Arz0n

//Libraries
#include "Stepper.h"
#include "IRremote.h"
#include <avr/sleep.h>
#include <stdlib.h>

#define STEPS 32   // Number of steps per revolution of Internal shaft
int  StepstoTake;  // Initialize the variable StepstoTake
int receiver = 12; // Signal Pin of IR receiver to Arduino Digital Pin 12
int digits[3];
int digitCount = 0;
int speed = 500;
bool enabled = true;
bool KILL = false;

Stepper myStepper(STEPS, 8, 10, 9, 11);
IRrecv irrecv(receiver);

void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn(); // Start the receiver
}

void addDigit(int digit)
{
    // Safety check: Prevent array overflow crashes
    if (digitCount >= 3) {
        digitCount = 0; 
    }

    digits[digitCount] = digit;
    digitCount++;

    if (digitCount == 3)
    {
        StepstoTake = digits[0] * 100 + digits[1] * 10 + digits[2];

        myStepper.setSpeed(speed);
        myStepper.step(StepstoTake);

        digitCount = 0; 
    }
}

void reset()
{
    digitCount = 0;
    digits[0] = 0;
    digits[1] = 0;
    digits[2] = 0;
    speed = 500;
    StepstoTake = abs(StepstoTake);
}

void loop()
{
  if (KILL)
  {
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_cpu();
  }
  if (irrecv.decode()) 
  {
    if (!(irrecv.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT))
    {
        switch (irrecv.decodedIRData.decodedRawData)
        {
        case 0xF609FF00: // If up is pressed
          speed = speed + 100;
          break;
        case 0xF807FF00: // If down is pressed
          speed = speed - 100;
          break;
        case 0xB847FF00: // If Func/Stop is pressed
          KILL = true;
          break;          
        case 0xBA45FF00: // If Power is pressed
          enabled = !enabled;
          break;
        case 0xE916FF00: // If 0 is pressed
            if (enabled)
            {
              addDigit(0);
            }
          break;
        case 0xF30CFF00: // If 1 is pressed
          if (enabled)
            {
              addDigit(1);
            }
          break;
        case 0xE718FF00: // If 2 is pressed
          if (enabled)
            {
              addDigit(2);
            }
          break;
        case 0xA15EFF00: // If 3 is pressed
          if (enabled)
            {
              addDigit(3);
            }
          break;
        case 0xF708FF00: // If 4 is pressed
          if (enabled)
            {
              addDigit(4);
            }
          break;
        case 0xE31CFF00: // If 5 is pressed
          if (enabled)
            {
              addDigit(5);
            }
          break;
        case 0xA55AFF00: // If 6 is pressed
          if (enabled)
            {
              addDigit(6);
            }
          break;
        case 0xBD42FF00: // If 7 is pressed
          if (enabled)
            {
              addDigit(7);
            }
          break;
        case 0xAD52FF00: // If 8 is pressed
          if (enabled)
            {
              addDigit(8);
            }
          break;
        case 0xB54AFF00: // If 9 is pressed
          if (enabled)
            {
              addDigit(9);
            }
          break;
        case 0xF20DFF00: // If St/Rept is pressed
          reset();
          break;      
        }
    }

    irrecv.resume(); // receive the next value
    
    // Shut off stepper coils to prevent overheating
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}


//code (NOT) inspired from the elegoo super starter kit
