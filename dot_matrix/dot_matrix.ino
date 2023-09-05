#include <LedControl.h>

#define DIN 3
#define CS 4
#define CLK 5

#define DotMatrixSayisi 1

LedControl dotmatrix = LedControl(DIN, CLK, CS, DotMatrixSayisi);
int kalp[2][8] = {{
    0,
    B01100110,
    B11111111,
    B11111111,
    B01111110,
    B00111100,
    B00011000,
    0
  },
  { B00000000,
    B00000000,
    B00100100,
    B01111110,
    B00111100,
    B00011000,
    B00000000,
    B00000000
  }
};

void setup() {

  dotmatrix.shutdown(0, false);//shutdown modunu kapatıyoruz
  dotmatrix.setIntensity(0, 8);//parlaklığı 8. kademeye alıyoruz
  dotmatrix.clearDisplay(0);//dot matrixin bütün ledlerini söndürüyoruz
}

void loop() {
//aşağıdaki döngüde kalp ritmi görseli yapılıyor.
  for (int i = 0; i < 8; i++) {
    dotmatrix.setRow(0, i, kalp[0][i]);//büyük kalp görseli basılıyor.
    delay(2);
  }
  delay(500);//500msn'ye gecikme
  for (int i = 0; i < 8; i++) {
    dotmatrix.setRow(0, i, kalp[1][i]);//küçük kalp görseli basılıyor.
    delay(2);
  }
  delay(250);//250msn'ye gecikme
}
