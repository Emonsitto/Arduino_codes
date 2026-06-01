
// date: 5/12/2026
// Lights on and off / LED switch by: Armanz0n

#include "pitches.h" //a library made by Brett Hagman (all credits to them), to install the library, you need to click 'sketch', 'include library', 'add .zip library', go to wherever the downloaded file from github is and select the .zip file called 'pitches.zip'  
 
// notes in the melody:
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6}; //creating a list with all the notes (from the library and yes, it has way more than these 8)
 
void setup() 
{
  pinMode(13, OUTPUT); //make pin 13 an output (because it is a buzzer)
}
 
void loop() {  
  for (int Note = 0; Note < 8; Note++) { //because there's eight notes, they will go higher in pitch every half second (Note++ means the variable Note will increase 1 every iteration of the loop)
    // pin13 will output the sound, every note is 0.5 sencond
    tone(13, melody[Note], 500);
     
    // Output the sound after one second, if this is not done, it sounds like a scream (Try it!)
    delay(1000);
  }

}

//code inspired from the elegoo super starter kit
