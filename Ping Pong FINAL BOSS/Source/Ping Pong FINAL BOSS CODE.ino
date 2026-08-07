
//date: 8/3/2026
//Ping pong final boss by: Arz0n

#include <Elegoo_GFX.h>
#include <Elegoo_TFTLCD.h>
#include <TouchScreen.h>

#define YP A3
#define XM A2
#define YM 9
#define XP 8

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

float x;
int y;
float dx = 2;
int dy = 5;
int x2;
int y2;
int dx2 = -1;
int dy2 = 3;
int bounce;

Elegoo_TFTLCD tft(A3, A2, A1, A0, A4);

void setup() {
  tft.reset();
  tft.begin(0x9341);
  tft.setRotation(2);
  tft.fillScreen(0x0000);
  Serial.begin(9600);

  randomSeed(analogRead(A5));

  x = random(25, 210);
  y = random(25, 290);
  x2 = random(25, 210);
  y2 = random(25, 290);
}
bool deadlywalls = false;
bool doubleBall = false;
bool teleporterwalls = false;
bool effects = false;
bool inverted = false;
int ballRadius = 10;
unsigned long effectTimer = 0;
const long effectDuration = 2500; 
int currentEffect = 0;
int rectx = 85;
int recty = 310;
int rectx2 = 85;
int recty2 = 0;
int topwidth = 67;
int bottomwidth = 67;
int topspeed = 2;

uint16_t color = 0xFFFF;
uint16_t paddlecolor = 0xFFFF;
bool victory = false;

void gameover() {
  tft.fillCircle(x, y, 10, 0xF800);
  tft.setCursor(0, 80);
  tft.setTextSize(10);
  tft.setTextColor(0xF800);
  tft.println("GAMEOVER");
  delay(1000);
  tft.fillScreen(0x0000);
  x = 120;
  y = 160;
  x2 = 120;
  y2 = 160;
  dy = -dy;
  dx = -dx;
  rectx = 85;
  recty = 310;
  rectx2 = 85;
  recty2 = 0;
  tft.fillRect(rectx, recty, 67, 10, 0xFFFF);
  tft.fillRect(rectx2, recty2, 67, 10, 0xFFFF);
  bounce = 0;
  dx = 2;
  dy = 6;
  paddlecolor = 0xFFFF;
  topwidth = 67;
  bottomwidth = 67;
  color = 0xFFFF;
  deadlywalls = false;
  doubleBall = false;
  teleporterwalls = false;
  effects = false;
  ballRadius = 10;
  currentEffect = 0;
  inverted = false;
}
void phase1() {
  bounce = 10;
  tft.fillCircle(x, y, 10, 0xbf9f);
  paddlecolor = 0xbf9f;
  tft.setCursor(0, 80);
  tft.setTextSize(8);
  tft.setTextColor(0xbf9f);
  tft.println("PHASE  1");
  delay(1000);
  dx = 3;
  dy = 7;
  bounce = 11;
  color = 0xFFFF;
}
void phase2() {
  bounce = 25;
  tft.fillCircle(x, y, 10, 0xffe6);
  paddlecolor = 0xffe6;
  tft.setCursor(0, 80);
  tft.setTextSize(8);
  tft.setTextColor(0xffe6);
  tft.println("PHASE  2");
  delay(1000);
  topwidth = 90;
  topspeed = 3;
  bounce = 22;
  color = 0xFFFF;
}
void phase3() {
  bounce = 40;
  tft.fillCircle(x, y, 10, 0xf800);
  paddlecolor = 0xf800;
  tft.setCursor(0, 80);
  tft.setTextSize(8);
  tft.setTextColor(0xf800);
  tft.println("PHASE  3");
  delay(1000);
  deadlywalls = true;
}
void phase4() {
  bounce = 50;
  tft.fillCircle(x, y, 10, 0xf81f);
  paddlecolor = 0xf81f;

  tft.setCursor(0, 80);
  tft.setTextSize(8);
  tft.setTextColor(0xf81f);
  tft.println("PHASE 4");

  delay(1000);
  tft.fillScreen(0x0000);

  doubleBall = true;
}
void phase5() {
  tft.fillCircle(x, y, 10, 0x081f);
  paddlecolor = 0x081f;
  bounce = 57;
  doubleBall = false;
  deadlywalls = false;
  teleporterwalls = true;
  tft.setCursor(0, 80);
  tft.setTextSize(8);
  tft.setTextColor(0x081f);
  tft.println("PHASE 5");
  delay(1000);
  tft.fillScreen(0x0000);
  tft.fillRect(0, 0, 10, 320, 0x081f);
  tft.fillRect(230, 0, 10, 320, 0x081f);
}
void phase6() {
  tft.fillCircle(x, y, 10, 0xFFFF);
  tft.setCursor(0, 80);
  tft.setTextSize(8);
  tft.setTextColor(0x081f);
  tft.println("PHASE 6");
  delay(1000);
  tft.fillScreen(0x0000);
  tft.fillRect(0, 0, 10, 320, 0x081f);
  tft.fillRect(230, 0, 10, 320, 0x081f);
  bounce = 68;
  bottomwidth = 45;
  topwidth = 90;
  topspeed = 4;
  teleporterwalls = true;
}
void phase7() {
  effects = true;
  tft.fillCircle(x, y, ballRadius, 0x07FF);
  paddlecolor = 0x07FF;
  tft.setCursor(0, 80);
  tft.setTextSize(8);
  tft.setTextColor(0x07FF);
  tft.println("PHASE  7");
  delay(1000);
  tft.fillScreen(0x0000);
  bounce = 81;
}
void phase8() {
  tft.fillCircle(x, y, ballRadius, 0xF81F);
  paddlecolor = 0xF81F;
  tft.setCursor(0, 80);
  tft.setTextSize(8);
  tft.setTextColor(0xF81F);
  tft.println("PHASE 8");
  delay(1000);
  tft.fillScreen(0x0000);
  bounce = 92;
  inverted = true;
}
void phase9() {
  tft.fillCircle(x, y, ballRadius, 0xF800);
  paddlecolor = 0xF800;
  tft.setCursor(0, 80);
  tft.setTextSize(8);
  tft.setTextColor(0xF800);
  tft.println("PHASE 9");
  tft.setCursor(0, 160);
  delay(1500);
  tft.fillScreen(0x0000);
  
  bounce = 97;          
  
  dx = 4;               
  dy = 8;
  topwidth = 95;       
  topspeed = 4;         
  bottomwidth = 45;
  
  deadlywalls = true;
  teleporterwalls = true; 
  
  tft.fillRect(0, 0, 10, 320, 0x081F);
  tft.fillRect(230, 0, 10, 320, 0xF800);


  doubleBall = true;      
  x2 = random(25, 210);
  y2 = random(25, 160);
  dx2 = -2;
  dy2 = 5;

  effects = true;         
  effectTimer = millis(); 
  
  inverted = true;       
}


void loop() {
  String read = ""; 

  if (Serial.available() > 0) {
    read = Serial.readStringUntil('\n');
    read.trim();
    read.toLowerCase();
  }
  
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  if (p.z > 100 && p.z < 1000) {
    tft.fillRect(rectx, recty, bottomwidth, 10, 0x0000);
    if (inverted == false) { rectx = map(p.x, 120, 900, 150, 0); }
    else {rectx = map(p.x, 120, 900, 0, 150);}
    rectx = constrain(rectx, 0, 150);
  }
  tft.fillRect(rectx2, recty2, topwidth, 10, 0x0000);

  int target = x - topwidth/2;
  if (rectx2 < target) rectx2 += topspeed;
  if (rectx2 > target) rectx2 -= topspeed;

  rectx2 = constrain(rectx2, 0, 150);
  tft.fillRect(rectx2, recty2, topwidth, 10, paddlecolor);
  tft.fillRect(rectx, recty, bottomwidth, 10, paddlecolor);
  if (effects == true) {
    if (millis() - effectTimer >= effectDuration) {
      effectTimer = millis();
      
      ballRadius = 10;
      if (dy > 0) dy = 6; else dy = -6;

      currentEffect = random(1, 6);
      
      switch (currentEffect) {
        case 1: ballRadius = 4;   break; 
        case 2: ballRadius = 15;  break; 
        case 3: break;                   
        case 4: if (dy > 0) dy = 3; else dy = -3; break; 
        case 5: if (dy > 0) dy = 10; else dy = -10; break; 
      }
    }
  }

  tft.fillCircle(x, y, ballRadius, 0x0000); 

  x += dx;
  y += dy;
  if (doubleBall) {
    tft.fillCircle(x2, y2, 10, 0x0000);
    x2 += dx2;
    y2 += dy2;
    tft.fillCircle(x2, y2, 10, 0xf81f);
  }
  int randomcolor = random(0, 8);

  if (((x >= rectx && x <= rectx + bottomwidth && y + ballRadius >= recty && dy > 0) || x >= rectx2 && x <= rectx2 + topwidth && y - ballRadius <= recty2 + ballRadius && dy < 0) || ((x2 >= rectx && x2 <= rectx + bottomwidth && y2 + 10 >= recty && dy2 > 0) || x2 >= rectx2 && x2 <= rectx2 + topwidth && y2 - 10 <= recty2 + 10 && dy2 < 0)) {
    if (randomcolor == 0) {
      color = 0x07E0;
    }
    if (randomcolor == 1) {
      color = 0x001F;
    }
    if (randomcolor == 2) {
      color = 0xFFE0;
    }
    if (randomcolor == 3) {
      color = 0x07FF;
    }
    if (randomcolor == 4) {
      color = 0xF81F;
    }
    if (randomcolor == 5) {
      color = 0xFD20;
    }
    if (randomcolor == 6) {
      color = 0x8010;
    }
    if (randomcolor == 7) {
      color = 0xFB56;
    }
    if (randomcolor == 8) {
      color = 0x9E66;
    }
    if((x2 >= rectx && x2 <= rectx + bottomwidth && y2 + 10 >= recty && dy2 > 0) || (x2 >= rectx2 && x2 <= rectx2 + topwidth && y2 - 10 <= recty2 + 10 && dy2 < 0)) {
      dy2 = -dy2;
    }

    if(x >= rectx2 && x <= rectx2 + topwidth && y - ballRadius <= recty2 + ballRadius && dy < 0 && deadlywalls == true) {
      dx = 0; 
    } 
    else {
      dx = random(0, 4);
      if (random(0, 2) == 1) {
        dx = -dx;
      }
    }
    dy = -dy; 
    bounce = bounce + 1;
}

  bool wallHit = false;

  if (x <= 30) {
    wallHit = true;
    if (teleporterwalls == true) {
      x = random(40, 210); 
      y = random(25, 290);
    } else {
      dx = -dx; 
      bounce = bounce + 1;
    }
  }
  
    else if (x >= 230) {
    wallHit = true;
    if (deadlywalls == true) {
      gameover();
      return; 
    } else {
      dx = -dx; 
      bounce = bounce + 1;
    }
  }

  if (doubleBall && (x2 >= 210 || x2 <= 21)) {
    wallHit = true;
    if (deadlywalls == true && x2 >= 210) {
      gameover(); 
      return;
    }
    dx2 = -dx2;
  }

  if (wallHit) {
    if (randomcolor == 0) color = 0x001F;
    if (randomcolor == 1) color = 0xFFE0;
    if (randomcolor == 2) color = 0x07FF;
    if (randomcolor == 3) color = 0xF81F;
    if (randomcolor == 4) color = 0xFD20;
    if (randomcolor == 5) color = 0x8010;
    if (randomcolor == 6) color = 0xFB56;
    if (randomcolor == 7) color = 0x9E66;
  }

  if (y >= recty && (x < rectx || x > rectx + bottomwidth) || read == "gameover") {
    gameover();
  }
  if ((y <= recty2 && (x < rectx2 || x > rectx2 + topwidth)) || (y2 <= recty2 && (x < rectx2 || x2 > rectx2 + topwidth))|| victory == true || read == "victory") {
    tft.fillCircle(x, y, 10, 0x07E0);
    tft.setCursor(0, 80);
    tft.setTextSize(10);
    tft.setTextColor(0x07E0);
    tft.println("VICTORY");
    delay(1000);
    tft.fillScreen(0x0000);
    x = 120;
    y = 160;
    dy = -dy;
    dx = -dx;
    rectx = 85;
    recty = 310;
    rectx2 = 85;
    recty2 = 0;
    tft.fillRect(rectx, recty, 67, 10, 0xFFFF);
    tft.fillRect(rectx2, recty2, 67, 10, 0xFFFF);
    bounce = 0;
    dx = 2;
    dy = 6;
    paddlecolor = 0xFFFF;
    topwidth = 67;
    bottomwidth = 67;
    victory = false;
    color = 0xFFFF;
    deadlywalls = false;
    doubleBall = false;
    teleporterwalls = false;
    effects = false;
    ballRadius = 10;
    currentEffect = 0;
    inverted = false;

  }
  if (bounce == 10 || read == "phase 1") {
    phase1();
    tft.fillScreen(0x0000);
  }
  if (bounce == 25 || read == "phase 2") {
    phase2();
    tft.fillScreen(0x0000);
    bounce = 26;
  }
  if (bounce == 40 || read == "phase 3") {
    phase3();
    tft.fillScreen(0x0000);
    tft.fillRect(0, 0, 10, 320, 0xF800);
    tft.fillRect(230, 0, 10, 320, 0xF800);
    bounce = 41;
  }
  if (bounce == 50 || read == "phase 4") {
    phase4();
    tft.fillRect(0, 0, 10, 320, 0xF800);
    tft.fillRect(230, 0, 10, 320, 0xF800);
    bounce = 51;
  }
  if (bounce == 56 || read == "phase 5") {
    phase5();
  }
  if (bounce == 67 || read == "phase 6") {
    phase6();
  }
  if (bounce == 80 || read == "phase 7") {
    phase7();
  }
  if (bounce == 91 || read == "phase 8") {
    phase8();
  }
  if (bounce == 96 || read == "phase 9") {
    phase9();
  }
  if(bounce == 103) {
    victory = true;
  }
  if (bounce == 70 || bounce == 73 || bounce == 76 || bounce == 79 || bounce == 99 || bounce == 101) {
    tft.fillScreen(0x0000);
    bounce += 1;
  }
  if (read == "pause") {
    delay(10000);
  }
  tft.fillCircle(x, y, ballRadius, 0x0000); 

  x += dx;
  y += dy;

  if (currentEffect != 3) { 
    tft.fillCircle(x, y, ballRadius, color); 
  } else {
    tft.fillCircle(x, y, ballRadius, 0x0000);
  }
  delay(10);
}
