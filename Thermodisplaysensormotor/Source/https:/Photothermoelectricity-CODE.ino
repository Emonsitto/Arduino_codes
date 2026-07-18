
// date: 7/17/2026
// Photothermoelectricity by: Arz0n

#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //set up the pins
#include <Servo.h> //cool library btw
Servo myservo;  // create servo object to control a servo
int ang = 0;    // variable to store the servo angle/position
static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );
void setup()
{
  lcd.begin(16, 2);
  myservo.attach(3);  // make the servo object be attached to pin 3
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
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
  float TC; //initialize the variable Temperature
  float humidity; //initialize the variable Humidity

  // Measure temperature and humidity.  If the functions returns true, then a measurement is available. 
  measure_environment( &TC, &humidity );
    float TF = (TC * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit

    //Display humidity
    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(humidity);
    lcd.print("%");

    // Display Temperature in Celsius
    lcd.setCursor(0, 0);
    lcd.print("Temp (F): ");
    lcd.print(TF);
    
    if (TF > 73.0) {
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
      digitalWrite(5, HIGH);
      digitalWrite(4, LOW);
      myservo.write(0);
    }
}

//code NOT inspired by the elegoo super starter kit (I will remove this soon)
