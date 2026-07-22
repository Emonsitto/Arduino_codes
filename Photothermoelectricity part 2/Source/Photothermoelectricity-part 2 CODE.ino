
// date: 7/20/2026
// Photothermoelectricity 2 by: Arz0n

#include "IRremote.h"
#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //set up the pins
#include <Servo.h> //cool library btw
Servo myservo;  // create servo object to control a servo
int ang = 0;    // variable to store the servo angle/position
static const int DHT_SENSOR_PIN = 2;
int digits[2];
int digitCount = 0;
int ID;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );
IRrecv irrecv(6);

void setup()
{
  lcd.begin(16, 2);
  myservo.attach(3);  // make the servo object be attached to pin 3
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
}

void addDigit(int digit)
{
    // Safety check: Prevent array overflow crashes
    if (digitCount >= 2) {
        digitCount = 0; 
    }

    digits[digitCount] = digit;
    digitCount++;

    if (digitCount == 2)
    {
    ID = digits[0] * 10 + digits[1];

    // Display Ideal Temperature
    lcd.setCursor(10, 1);
    lcd.print(ID);
    digitCount = 0; 
    }
}

void reset()
{
    digitCount = 0;
    digits[0] = 0;
    digits[1] = 0;
}

static bool measure_environment( float *TC, float *humidity ) // Returns true when time interval lapses and updates temp/humidity via pointers
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
  if( millis( ) - measurement_timestamp > 3000ul )
  {
    if( dht_sensor.measure( TC, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }

  return( false );
}

void loop()
{
  float TC; //initialize the variable TC
  float humidity; //initialize the variable Humidity
  if (irrecv.decode()) 
    {
      if (!(irrecv.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT))
      {
        switch (irrecv.decodedIRData.decodedRawData)
        {
          case 0xBA45FF00: // If Power is pressed
            reset();
            break;
          case 0xE916FF00: // If 0 is pressed
            addDigit(0);
            break;
          case 0xF30CFF00: // If 1 is pressed
            addDigit(1);
            break;
          case 0xE718FF00: // If 2 is pressed
            addDigit(2);
            break;
          case 0xA15EFF00: // If 3 is pressed
            addDigit(3);
            break;
          case 0xF708FF00: // If 4 is pressed
            addDigit(4);
            break;
          case 0xE31CFF00: // If 5 is pressed
            addDigit(5);
            break;
          case 0xA55AFF00: // If 6 is pressed
            addDigit(6);
            break;
          case 0xBD42FF00: // If 7 is pressed
            addDigit(7);
            break;
          case 0xAD52FF00: // If 8 is pressed
            addDigit(8);
            break;
          case 0xB54AFF00: // If 9 is pressed
            addDigit(9);
            break;
        }
      }
    }
    irrecv.resume();
  // Measure temperature and humidity.  If the functions returns true, then a measurement is available. 
  measure_environment(&TC, &humidity);
    int TF = (TC * 9)/ 5 + 32; // Convert Celcius to Fahrenheit

    // Display Ideal Temperature in Fahrenheit
    lcd.setCursor(0, 1);
    lcd.print("Id. Temp: ");

    // Display Temperature in Fahrenheit
    lcd.setCursor(0, 0);
    lcd.print("Temp (F): ");
    lcd.print(TF);
    
    if (TF > ID) {
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      for (ang = 0; ang <= 180; ang += 2) {
        myservo.write(ang);
        delay(5);
        }
      for (ang = 180; ang >= 0; ang -= 2) {
        myservo.write(ang);
        delay(5);
        }
      }
    else {
      if (TF == ID) {
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
      myservo.write(0);
      }
      else {
        digitalWrite(5, HIGH);
        digitalWrite(4, LOW);
        myservo.write(0);
      }
  }
} 
