
// date: 6/17/2026
// Blinking_SubscribeLCD by: Arz0n

// initialize the (veeeerrrryyyy cool) library with the numbers of the interface pins
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);   // set up the LCD's number of columns and rows
}

void loop() {
  lcd.setCursor(0, 0); // set the cursor to column 0, line 0 (line 0 is the first row, since it begins with 0)
  lcd.print("Subscribe to"); //print "Subscribe to", which when completed will say the phrase "Subscribe to Arzon", which you should do... NOW >:D 
  lcd.setCursor(0, 1); // set the cursor to column 0, line 0 (line 1 is the second row, since it begins with 0)
  lcd.print("Arzon!"); //print "Arzon!" to complete the phrase "Subscribe to Arzon!", which you should do ;-)
  delay(500); //wait half a second before continuing ;-;
  lcd.setCursor(0, 0); // set the cursor to column 0, line 0
  lcd.print("              "); //print empty spaces to give it the blink thing
  lcd.setCursor(0, 1); // set the cursor to column 0, line 1
  lcd.print("      "); //print empty spaces to give it the blink thing
  delay(500); //wait half a second before continuing ;-;
}
//code (kind of) inspired from the elegoo super starter kit
