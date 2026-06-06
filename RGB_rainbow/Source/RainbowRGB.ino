
// date: 5/5/2026
// Rainbow RBG by: ArZon

void setup() {
  #define blue 3
  #define red 5
  #define green 6
}

// Define variables:
int o3; // output 3 -> blue
int o5; // output 5 -> red
int o6; // output 6 -> green
int z;  // control variable for the for loop

//Main loop
void loop() {
  o3 = 255; 
  o5 = 0;
  o6 = 0;
  
  // changing from blue to red
  for(z = 0; z < 255; z += 1) {
    o3 -= 1;
    o5 += 1;
    analogWrite(blue, o3);
    analogWrite(red, o5);
    delay(10);
  }

  o3 = 0;
  o5 = 255;
  o6 = 0;
  
  // changing from red to green
  for(z = 0; z < 255; z += 1) {
    o5 -= 1;
    o6 += 1;
    analogWrite(red, o5);
    analogWrite(green, o6);
    delay(15);
  }

  o3 = 0;
  o5 = 0;
  o6 = 255;

  // changing from green to blue
  for(z = 0; z < 255; z += 1) {
    o6 -= 1;
    o3 += 1;
    analogWrite(green, o6);
    analogWrite(blue, o3);
    delay(10);
  }
  }
