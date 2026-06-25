
// date: 6/23/2026
// Eight_LEDs_controlled_by_Serial_Monitor by: Arz0n

int latchPin = 11;    //Digital pin 11 from the Arduino goes to pin #12 of the 74HC595 shift register
int clockPin = 9;     //Digital pin 9 from the Arduino goes to pin #11 of the 74HC595 shift register
int dataPin = 12;     //Digital pin 12 from the Arduino goes to pin #14 of the 74HC595 shift register
byte leds = 0;        //Define variable 'leds' as type 'byte', which represents numbers using eight bits, and there's eight leds

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW); // Pull latch low to start data transmission
   shiftOut(dataPin, clockPin, LSBFIRST, leds); // Shift out the 'leds' byte (LSB first) using the defined Data and Clock pins
   digitalWrite(latchPin, HIGH); // Pull latch high to lock the data and update the outputs
}
void setup() 
{
  //set all pins as outputs
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);

  updateShiftRegister();
  Serial.begin(9600); //Start the serial monitor :p
  delay(1099); //wait 1099 ms so the weird squares don't appear because of the transmition mismatch
  Serial.println("Enter LED Number 1 to 8 once to turn that LED on or twice to turn it off. You can also enter 0 to turn 'em all off or 9 to turn 'em all on"); //print that big ol' text in the serial monitor
  
  //Turn off the LEDs (the first one turns on for... some reason so this has gotta be there so it turns off)
  leds = 0;
  updateShiftRegister();
}

void loop() 
{
  char read = Serial.read(); //Define variable 'read' as a char type (meaning it can only hold one character at a time), and it will contain whatever is entered into the Serial Monitor
  
  //Toggle on/off (meaning when you enter it once, it turns on, and if you do it again, it turns off) the LED number that has been entered if it's in the range 1-8 (cuz' there's eight LEDs) 
  if (read >= '1' && read <= '8') 
  {
    int led = read - '1';
    bitWrite(leds, led, !bitRead(leds, led)); //the main line of all this (which makes the toggling possible), it basically takes the variables 'leds' and 'led' and then inverts them (because of them being binary [1 or 0], if they're off or '0', they turn to 1 or 'on')
    updateShiftRegister(); //read the name of the function... 
  
    //print in the Serial monitor what LED was toggled
    Serial.print("Toggled LED ");
    Serial.println(read);
  }

  //Turn off all LEDs if the input is '0'
  if (read == '0')
  {
  leds = 0; //This turns all the LEDs off because it sends '0' (nothing) to the Shift Register, so it just doesn't do nothing
  updateShiftRegister(); //read the name of the function... 
  Serial.println("All LEDs have been turned off"); //Do I even have to explain this one?
  }

  //Turn on all LEDs if the input is '9'
  if (read == '9')
  {
  leds = 255; //This turns all the LEDs on because it sends '255' (maximum value, like Minecraft potion effects) to the Shift Register, so it turns all of them on, as it hasn't recieved any other instructions
  updateShiftRegister(); //read the name of the function... 
  Serial.println("All LEDs have been turned on"); //Another one that's self explanatory :v
  }
}

//code (kinda) inspired from the elegoo super starter kit
