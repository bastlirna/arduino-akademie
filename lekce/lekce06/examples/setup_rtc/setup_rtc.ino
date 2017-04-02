#include <Wire.h>
#define ADDR 0x68


char buffer[20+1] = {0};
int pos = 0;

void setup() {  
  Wire.begin();

  write_reg(0, 0);
  
  Serial.begin(9600);
  Serial.println("To set time send date and time in format of YYMMDDHHMMSS, eg 20170402120000");
}

void loop() {
  if (readTime()) {
    Serial.println(buffer);
    if (convert()){
      setTime();    
    } else {
      Serial.println("Invalid data");
    }
  }

  printTime();
  delay(1000);
  
}

bool convert() {
  if (strlen(buffer) != 12) {
    return false;
  }

  for(int i = 0; i < 12; i++) {
    buffer[i] -= '0';
    if (buffer[i] > 9) {
      return false;
    }
  }

  return true;
}

void printTime() {
  byte data[7];
  read_regs(0, 8, data);

  Serial.print("Time: ");
  Serial.print(data[6], HEX);
  Serial.print(".");
  Serial.print(data[5], HEX);
  Serial.print(".");
  Serial.print(data[4], HEX);
  
  Serial.print(" (");
  Serial.print(data[3], HEX); 
  Serial.print(") ");
  
  Serial.print(data[2], HEX);
  Serial.print(":");
  Serial.print(data[1], HEX);
  Serial.print(":");
  Serial.println(data[0], HEX);
}

void setTime() {
  byte d;
  
  // year
  d = (buffer[0] << 4) | buffer[1];
  write_reg(6, d);

  // month
  d = (buffer[2] << 4) | buffer[3];
  write_reg(5, d);

  // date
  d = (buffer[4] << 4) | buffer[5];
  write_reg(4, d);

  // hour
  d = (buffer[6] << 4) | buffer[7];
  write_reg(2, d);

  // min
  d = (buffer[8] << 4) | buffer[9];
  write_reg(1, d);

  // sec
  d = (buffer[10] << 4) | buffer[11];
  write_reg(0, d);

  Serial.println("Updated");
  
}

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

void read_regs(byte addr, byte len, byte* buffer) {
  Wire.beginTransmission(ADDR);
  Wire.write(addr);
  Wire.endTransmission();
  
  Wire.requestFrom(ADDR, (byte)len);
  for(int i = 0; i < len; i++) {
    buffer[i] = Wire.read();
  }
}

bool readTime() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n' || pos >= 20) {
      pos = 0;
      return true;
    }
    buffer[pos++] = c;
    buffer[pos] = 0;
  }
  return false;
}



