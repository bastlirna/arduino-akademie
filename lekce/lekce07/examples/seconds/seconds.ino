#include <Wire.h>
#define ADDR 0x68

volatile unsigned long tic_counter = 0;

void setup () {
  Sserial.begin(9600);
  Serial.println("Setup");

  Wire.begin();
  write_reg(0, 0); // enable RTC
  write_reg(7, 0b00010000); // enable RTC output @ 1 Hz

  attachInterrupt(digitalPinToInterrupt(3), tick, RISING);
}

void loop () {
  while(1) {
    Serial.print(digitalRead(3));
    Serial.print(" ");
    Serial.print(seconds());
    Serial.print(" ");
    Serial.println(millis());
  
    delay(100);
  }
}

void tick() {
  tic_counter++;
}

unsigned long seconds() {
  // TODO disable iir.
  return tic_counter;
  // TODO enable irr.
}

void write_reg(byte addr, byte data) {
  Wire.beginTransmission(ADDR);
  Wire.write(addr);
  Wire.write(data);
  Wire.endTransmission();
}

