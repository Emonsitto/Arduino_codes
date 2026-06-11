
// date: 6/11/2026
// LED & Buzzer triggered by Thumb Joystick (LnBtbTJ) by: Armanz0n

int Switch = 2;       // Digital pin connected to switch output
int X = A0;            // Analog pin connected to X output
int Y = A1;            // Analog pin connected to Y output
int ActiveBuzzer = 13;  // Digital pin connected to buzzer
int BlueLED = 6;
int RedLED = 9;

void setup() {
  pinMode(Switch, INPUT);
  digitalWrite(Switch, HIGH);  // Activates internal pull-up resistor
  
  pinMode(ActiveBuzzer, OUTPUT); //Set the buzzer as an output
  Serial.begin(9600); 
}

void loop() {
  //math part
  int Blue = analogRead(X)/4;
  int Red = analogRead(Y)/4;
  int BlueNRed = (Blue + Red)/2;
  analogWrite(BlueLED, BlueNRed);
  analogWrite(RedLED, BlueNRed);
  
  if (digitalRead(Switch) == 0) {
    digitalWrite(ActiveBuzzer, HIGH); // Turn buzzer on
    delay(100);
    digitalWrite(Switch, HIGH);
    digitalWrite(ActiveBuzzer, LOW);// Turn buzzer off
    delay(500);
  } 
  else {
    digitalWrite(ActiveBuzzer, LOW);  // Turn buzzer off when released
  }

}

//code NOT inspired from the elegoo super starter kit
