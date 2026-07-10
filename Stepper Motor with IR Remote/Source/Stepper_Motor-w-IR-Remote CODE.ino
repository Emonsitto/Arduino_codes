
// date: 7/9/2026
// Stepper Motor With Remote by: Arz0n

//Libraries
#include "Stepper.h"
#include "IRremote.h"

#define STEPS 32   // Number of steps per revolution of Internal shaft
int  StepstoTake;  // Initialize the variable StepstoTake
int receiver = 12; // Signal Pin of IR receiver to Arduino Digital Pin 12

Stepper myStepper(STEPS, 8, 10, 9, 11);
IRrecv irrecv(receiver);
uint32_t last_decodedRawData = 0;//variable used to store the last decodedRawData
465xrcfeds
void setup()
{
    irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode()) 
  {
    if (irrecv.decodedIRData.flags)
    {
      //set the current decodedRawData to the last decodedRawData
      irrecv.decodedIRData.decodedRawData = last_decodedRawData;
    }
    switch (irrecv.decodedIRData.decodedRawData)
    {

      case 0xB946FF00: // If VOL+ button pressed
        myStepper.setSpeed(500); //Max seems to be 500
        StepstoTake  =  -2048;  // Rotate Stepper Motor 2048 steps to the left
        myStepper.step(StepstoTake);
        delay(2000);
        break;

      case 0xEA15FF00: // If VOL- button pressed
        myStepper.setSpeed(500);
        StepstoTake  =  2048;  // Rotate Stepper Motor 2048 steps
        myStepper.step(StepstoTake);
        delay(2000);
        break;

    }
    //store the last decodedRawData
    last_decodedRawData = irrecv.decodedIRData.decodedRawData;
    irrecv.resume(); // receive the next value
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }

}

//code inspired from the elegoo super starter kit
