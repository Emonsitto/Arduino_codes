
// date: 5/26/2026
// MicroServo Motor by: ArZon

#include <Servo.h> //cool library btw

Servo myservo;  // create servo object to control a servo

int ang = 0;    // variable to store the servo angle/position

void setup() {
//  Serial.begin(9600); //initializes serial communication between the Arduino board and the computer at 9600 bits per second, this can be commented or uncommented, it doesn't really matter
  myservo.attach(9);  // make the servo object be attached to pin 9
}

void loop() {
  for (ang = 0; ang <= 180; ang += 2) { // goes from 0 degrees to 180 degrees in steps of 2 (can be changed)
    myservo.write(ang);              // servo goes to the degrees/angle/position of the variable 'ang'
    delay(10);                       // the time it takes (10 miliseconds by default)
  }
  for (ang = 180; ang >= 0; ang -= 2) { // goes from 180 degrees to 0 degrees in steps of 2 (can be changed)
    myservo.write(ang);              // servo goes to the degrees/angle/position of the variable 'ang'
    delay(10);                       // the time it takes (10 miliseconds by default)
  }
 
}

//code inspired from the elegoo super starter kit
