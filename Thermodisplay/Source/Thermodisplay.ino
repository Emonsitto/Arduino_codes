
// date: 6/19/2026
// Thermodisplay by: Arz0n

#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //set up the pins
void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
  int tempReading = analogRead(A0); //Create a variable to store the temperature (pin A0)
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
  float tempC = tempK - 273.15;            // Convert Kelvin to Celcius
  float tempF = (tempC * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit

  lcd.setCursor(0, 1);
  lcd.print("By: Arzon");
  // Display Temperature in Celsius
  lcd.setCursor(0, 0);
  lcd.print("Temp:        C  ");
  lcd.setCursor(6, 0);
  lcd.print(tempC);
  delay(1000);
  
  //Blinky blink section
  lcd.setCursor(0, 0);
  lcd.print("               ");
  lcd.setCursor(6, 0);
  lcd.print("     ");
  delay(500);
  // Display Temperature in Fahrenheit
  lcd.setCursor(0, 0);
  lcd.print("Temp:        F  ");
  lcd.setCursor(6, 0);
  lcd.print(tempF);
  delay(1000);
  
  //Blinky blink section
  lcd.setCursor(0, 0);
  lcd.print("               ");
  lcd.setCursor(6, 0);
  lcd.print("     ");
  delay(500);
  // Display Temperature in Kelvin
  lcd.setCursor(0, 0);
  lcd.print("Temp:         K  ");
  lcd.setCursor(6, 0);
  lcd.print(tempK);
  delay(1000);

  //Blinky blink section
  lcd.setCursor(0, 0); 
  lcd.print("               ");
  lcd.setCursor(6, 0);
  lcd.print("     ");
  delay(500);
}

//code (kinda) inspired from the elegoo super starter kit
