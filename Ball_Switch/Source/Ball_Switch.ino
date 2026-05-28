
// date: 5/26/2026
// Ball switch by: Armanz0n

void setup()
  { 
    pinMode(13,OUTPUT);//initializing the built-in LED (ledPin), which is pin 13, as an output
    pinMode(12,INPUT); //initializing the tilt ball switch connected to pin 12 as an input 
    digitalWrite(12, HIGH); //setting the tilt ball switch to HIGH, meaning it is on. The thing is, if the ball switch is tilted less than 90 degrees, an internal circuit opens, and open = broken, so it's as if it is turned off.
  } 

void loop() 
  {  
    if(HIGH == digitalRead(12)) //this uses the if function to check if the variable 2 (the pin)
      {
        digitalWrite(13,LOW);//turn the LED off
      }
    else //this uses the else function as a continuation to the if function, meaning that if variable 2 isn't HIGH (on), then somethin' will happen (that something being the internal ledPin turning on)
      {
        digitalWrite(13,HIGH);//turn the LED on 
      }
  }

//code inspired from the elegoo super starter kit
