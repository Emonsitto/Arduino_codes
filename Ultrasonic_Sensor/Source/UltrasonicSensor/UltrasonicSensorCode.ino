
// date: 6/3/2026
// by: ArZon

#include "SR04.h" //include library
#define TRIG_PIN 12 //intialize the pins
#define ECHO_PIN 11 //intialize the pins
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN); //setup the pins
long a; //initialize variable "a"

void setup() {
   // Serial.begin(9600); //optional, sets the data transmission speed (from the computer to the Arduino) to 9600 bits per second
   delay(1000); //wait one second
}

void loop() {
   a=sr04.Distance(); //variable "a" is the distance from the nearest object (or where the sound bounced off of) to the sensor
   Serial.print(a); //print the distance from the object to the sensor
   Serial.println("cm"); //print "cm" next to the distance
   delay(1000); //wait 1 second until repeating it again
}

//code inspired from the elegoo super starter kit
