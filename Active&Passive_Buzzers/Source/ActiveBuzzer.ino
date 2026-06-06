
// date: 5/26/2026
// Active buzza by: ArZon

void setup()
{
  pinMode(13, OUTPUT); //make pin 13 an output (because it is a buzzer)
}
void loop()
{
  int sd; //create the function sd (sound duration)
  for (int i = 0; i < 20; i++)
  {
    //use an if, else if, and else functions to shorten the sound
    if (i < 5)
    {
      sd = 250;
    } 
    else if (i < 10)
    {
      sd = 150;
    } 
    else if (i < 20)
    {
      sd = 50;
    }
    digitalWrite(13, HIGH); //turn the buzzer on
    delay(sd);
    digitalWrite(13, LOW); //turn the buzzer off
    delay(sd);
  }
}

//code inspired from the elegoo super starter kit
