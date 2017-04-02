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

byte dump(byte addr, byte len){
  Wire.beginTransmission(ADDR);
  Wire.write(addr);
  Wire.endTransmission();
  
  Wire.requestFrom(ADDR, (byte)len);

  for(int i = 0; i <= len; i++){
    Serial.print(addr + i, HEX);
    Serial.print("\t");

    byte d = Wire.read();
    Serial.print(d, HEX);
    Serial.print(" [");
    Serial.print(d, BIN);
    Serial.println("]");
  }
}
  
void setup() {
  Serial.begin(9600);
  Wire.begin();

  // write_reg(0, 0);
}



void loop() {
  dump(0, 7);
  Serial.println("");
  delay(1000);
}

