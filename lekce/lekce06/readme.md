# Lekce 5

## Osnova

- Ot�zky z minula?
- Diskuze co d�lat v dal��ch lekc�ch? 
- Binary a BCD reprezentace ��sel
- Hodiny re�ln�ho �asu (co a pro�)
- DS1307 + jak se �te datasheet
- I2C �ten� a z�pis

## �kol: Vypi�t� obsah pam�ti RTC

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

## �kol: Nastavte �as RTC

## �kol: Naprogramujte hodiny
