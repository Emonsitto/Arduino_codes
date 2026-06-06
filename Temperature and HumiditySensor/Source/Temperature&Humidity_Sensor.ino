
// date: 6/5/2026
// Temperature and HumiditySensor by: Armanz0n

#include <dht_nonblocking.h>
#define DHT_SENSOR_TYPE DHT_TYPE_11

static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );

void setup( )
{
  Serial.begin( 9600);
}

static bool measure_environment( float *temperature, float *humidity ) // Returns true when time interval lapses and updates temp/humidity via pointers
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
  if( millis( ) - measurement_timestamp > 3000ul )
  {
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }

  return( false );
}

void loop( )
{
  float temperature; //initialize the variable Temperature
  float humidity; //initialize the variable Humidity

  // Measure temperature and humidity.  If the functions returns true, then a measurement is available. 
  if( measure_environment( &temperature, &humidity ) == true )
  {
    Serial.print( "Temperature = " );
    Serial.print( temperature, 1 );
    Serial.print( " Celsius, Humidity = " );
    Serial.print( humidity, 1 );
    Serial.println( "%" );
  }
}

//code inspired from the elegoo super starter kit
