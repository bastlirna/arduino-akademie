# Lekce 6

## Osnova

- Otázky z minula?
- Diskuze co dělat v dalších lekcích? 
- Binary a BCD reprezentace čísel
- Hodiny reálného času (co a proč)
- DS1307 + jak se čte datasheet
- I2C čtení a zápis

## Úkol: Vypiště obsah paměti RTC

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

## Úkol: Nastavte čas RTC

## Úkol: Naprogramujte hodiny
