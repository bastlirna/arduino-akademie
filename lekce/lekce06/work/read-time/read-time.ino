#include <Wire.h>

#define ADDR 0x68

void write_reg(byte addr, byte data) {
  Wire.beginTransmission(ADDR);
  Wire.write(addr);
  Wire.write(data);
  Wire.endTransmission();
}

byte read_reg(byte addr) {
  Wire.beginTransmission(ADDR);
  Wire.write(addr);
  Wire.endTransmission();
  
  Wire.requestFrom(ADDR, (byte)1);
  return Wire.read();
}

void setup() {
  Wire.begin();
  Serial.begin(9600);
  write_reg(0,0);
}

void loop() {
  byte s = read_reg(0);
  byte m = read_reg(1);
  byte h = read_reg(2);
  
  Serial.print(h, HEX);
  Serial.print(":");
  Serial.print(m, HEX);
  Serial.print(":");
  Serial.println(s, HEX);
  

  delay(1000);
}
