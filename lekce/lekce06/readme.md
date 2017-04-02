# Lekce 5

## Osnova

- Otázky z minula?
- Diskuze co dìlat v dalších lekcích? 
- Binary a BCD reprezentace èísel
- Hodiny reálného èasu (co a proè)
- DS1307 + jak se ète datasheet
- I2C ètení a zápis

## Úkol: Vypištì obsah pamìti RTC

```arduino
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
```

## Úkol: Nastavte èas RTC

## Úkol: Naprogramujte hodiny
