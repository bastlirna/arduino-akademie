#include <Wire.h>
#define ADDR 0x27

void setup() {
  Wire.begin();
}

void loop() {
  digit(0, 0b00101101);
  digit(1, 0b00101101);
  digit(2, 0b00101101);
  digit(3, 0b00101101);
  delay(1000);
}

void digit(byte n, byte s) {
  Wire.beginTransmission(ADDR);
  Wire.write(n); // <- pozice
  Wire.write(s); // <- segmenty
  Wire.endTransmission();
}

