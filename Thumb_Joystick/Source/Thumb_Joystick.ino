
// date: 6/9/2026 (what a date huh?)
// Thumb Joystick by: Arz0n

void setup() {
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  Serial.begin(9600); //optional, sets the data transmission speed (from the computer to the Arduino) to 9600 bits per second
  delay(1099); //Delay of 1099 ms between the serial.begin function and the serial.print function; if this wasn't here, the serial monitor would print some weird squares for some reason, probably because of different speeds of transmission.
}

void loop() {
  Serial.print("Switch:  "); // this line just... prints "Switch: "
  Serial.print(digitalRead(2)); //this line prints the position of the thumb joystick(1: not pressed, 0: pressed) right next to "Switch: ", so it says: "Switch: 1" or "Switch: 0"
  Serial.print("\n"); //jumps to the next line
  Serial.print("X-axis: "); // this line just... prints "X-axis: "
  Serial.print(analogRead(A0)); //this line prints the position of the thumb joystick's X-axis(can be 0-1024) right next to "X-axis: ", so it says: "X-Axis: (number from 0-1024)"
  Serial.print("\n"); //jumps to the next line
  Serial.print("Y-axis: "); // this line just... prints "Y-axis: "
  Serial.println(analogRead(A1)); //this line prints the position of the thumb joystick's Y-axis(can be 0-1024) right next to "Y-axis: ", so it says: "Y-Axis: (number from 0-1024)"
  Serial.print("\n"); //jumps to the next line
  delay(2000); //delay of 2 seconds until it checks again
}

//code inspired from the elegoo super starter kit
