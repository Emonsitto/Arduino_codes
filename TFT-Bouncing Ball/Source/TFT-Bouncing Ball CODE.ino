
//date: 7/30/2026
//TFT-Bouncing Ball by: Arz0n

#include <Elegoo_GFX.h>
#include <Elegoo_TFTLCD.h>

int x;
int y;

Elegoo_TFTLCD tft(A3, A2, A1, A0, A4); 
void setup() {
  tft.reset();
  tft.begin(0x9341); 
  tft.setRotation(2);
  tft.fillScreen(0x0000);

  randomSeed(analogRead(A5));

  x = random(25, 210);
  y = random(25, 290);
}

int dx = 2;
int dy = 3;

void loop() {
    tft.fillCircle(x, y, 10, 0x0000);
    x += dx;
    y += dy;

    if (x >= 220 || x <= 20) {
        dx = -dx;
    }
    if (y <= 20 || y >= 300) {
        dy = -dy;
    }

    tft.fillCircle(x, y, 10, 0xFFFF);

    delay(10);
}
