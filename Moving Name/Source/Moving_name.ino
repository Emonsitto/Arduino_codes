
// date: 7/23/2026
// Moving_Name by: Arz0n

// initialize the (veeeerrrryyyy cool) library with the numbers of the interface pins
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int r = 0;
int t = 0;
int c = 0;
int s = 200;
bool interception = false;
bool enabled = false;

void setup() {
  lcd.begin(16, 2); 
  pinMode(13, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(13) == LOW) {
    enabled = true;
    while(enabled == true) {
      lcd.setCursor(0, 0);
      lcd.print("                        ");
      delay(10);
      lcd.setCursor(0, 1);
      lcd.print("                        ");
      delay(10);
      lcd.setCursor(r, c);
      lcd.print("Arzon");
      delay(s);
      if(s == 150 && r == 12) {
        r = 11;
        delay(2000);
        lcd.setCursor(r, c);
        lcd.print("Arzon");
        delay(s);
        lcd.setCursor(r, c);
        lcd.print("AArzo");
        delay(s);
        lcd.setCursor(r, c);
        lcd.print("ArArz");
        delay(s);
        lcd.setCursor(r, c);
        lcd.print("ArzAr");
        delay(s);
        lcd.setCursor(r, c);
        lcd.print("ArzoA");
        delay(s);
        lcd.setCursor(r, c);
        lcd.print("Arzon");
        delay(s);
        c = 1;
        s = 200;
        r = 0;
        enabled = false;
        bool appear = true;
        if(appear == true) {
          lcd.setCursor(0, 1);
          lcd.print("n");
          delay(200);
          lcd.setCursor(0, 1);
          lcd.print("on");
          delay(200);
          lcd.setCursor(0, 1);
          lcd.print("zon");
          delay(200);
          lcd.setCursor(0, 1);
          lcd.print("rzon");
          delay(200);
          lcd.setCursor(0, 1);
          lcd.print("Arzon");
          delay(200);
          appear = false;
          interception = true;
        }
        if(interception == true) {
          lcd.setCursor(0, 0);
          lcd.print("                     ");
          lcd.setCursor(11, 1);
          lcd.print("Arzon");
          delay(1000);
          lcd.setCursor(7, 1);
          lcd.print("--");
          delay(1000);
          bool minus = true;
          int q = 0;
          while(minus == true) {
            lcd.setCursor(q, 1);
            lcd.print(" ");
            delay(100);
            q += 1;
            if(q == 16) {
              minus = false;
              r = 0;
              t = 0;
              c = 0;
              s = 200;
              lcd.setCursor(0, 0);
              lcd.print("000000000000000000000");
              lcd.setCursor(0, 1);
              lcd.print("000000000000000000000");
              delay(10000);
            }
          }
        }
      }
      r = r + 1;
      if(r == 12 && c == 0 && s == 200) {
        lcd.setCursor(10, 0);
        lcd.print("Arzon ");
        delay(100);
        lcd.setCursor(9, 0);
        lcd.print("Arzon  ");
        delay(1000);
        enabled = true;
        r = 10;
        t = t + 1;
        if(t == 5) {
          lcd.setCursor(0, 0);
          lcd.print("                  ");
          lcd.setCursor(8, 0);
          lcd.print("  Arzon");
          delay(200);
          lcd.setCursor(9, 0);
          lcd.print("   Arzon");
          delay(200);
        }
      }
      while(t == 5) {
      r = r - 1;
      enabled = false;
      lcd.setCursor(0, 0);
      lcd.print("                        ");
      delay(10);
      lcd.setCursor(0, 1);
      lcd.print("                        ");
      delay(10);
      lcd.setCursor(r, 0);
      lcd.print("Arzon");
      delay(75);
      if(r == 0) {
        t = 0;
        r = 0;
        enabled = true;
        s = 150;
        }
      }
    }
    delay(1000);
  }
  else {
  lcd.setCursor(0, 0); 
  lcd.print("Arzon");
  }
}
