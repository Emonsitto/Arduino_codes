
// date: 5/12/2026
// Lights on and off / LED switch by: ArZon

void setup()
 {
  pinMode(5, OUTPUT); //pin5 will be the LED
  pinMode(8, INPUT_PULLUP);  //pin8 will be one of the buttons
  pinMode(9, INPUT_PULLUP);  //pin9 will be the other button

}

void loop()
 {

  if (digitalRead(9) == LOW) //if one button is pressed
    digitalWrite(5, HIGH); // the lights turn on
  if (digitalRead(8) == LOW) // if another button is pressed
    digitalWrite(5, LOW); // the lights turn off
}
