# EduShiled

## Piny

| Pin     | Funkce  | Poznámka |
| ------- | ---- | ---- |
| 2       | [Tlačítko](#tlačítko) | Při stisku je `LOW` |
| 3       | [RTC](#rtc) SQW out | Výstup hodinového signálu z RTC |
| 4       | NC¹ |  |
| 5       | [RGB LED: G](#rgb-led) | Svítí v `LOW` |
| 6       | [RGB LED: B](#rgb-led) | Svítí v `LOW` |
| 7       | NC¹ |  |
| 8       | NC¹ |  |
| 9       | [RGB LED: R](#rgb-led) | Svítí v `LOW` |
| 10      | NC¹ |  |
| 11      | NC¹ |  |
| 12      | NC¹ |  |
| 13      | [Semafor: zelená](#led-semafor) | Svítí v `HIGH` |
| 14 (A0) | [Fotorezistor](#fotorezistror) |  |
| 15 (A1) | [Termistor](#termistor) |  |
| 16 (A2) | [Semafor: červená](#led-semafor) | Svítí v `HIGH` |
| 17 (A3) | [Semafor: oranžová](#led-semafor) | Svítí v `HIGH` |
| 18 (A4) | I2C² SDA |  |
| 19 (A5) | I2C² SCK |  |

¹ Not Connected. Tyto piny nejsou využity, jsou rezervovány pro [Ethernet Shield](https://www.arduino.cc/en/Main/ArduinoEthernetShieldV1).

² Na I2C sběrnici jsou připojeny dvě periferie: [Display](#display) (adresa **`0x27`**) a [RTC](#rtc) (adresa **`0x68`**).

## Funkční bloky

### LED (semafor)

Shield obsahuje 3 LED v barvách semaforu. LED jsou zapojeny proti zemi (**svítí při HIGH**).

| Pin | Funkce   |
| --- | --- |
| 13 | Semafor: zelená |
| 16 | Semafor: červená |
| 17 | Semafor: oranžová |

Užitečné funkce:
- [pinMode](https://www.arduino.cc/en/Reference/PinMode)
- [digitalWrite](https://www.arduino.cc/en/Reference/DigitalWrite)

### RGB LED 

Shield obsahuje jednu [RGB](https://en.wikipedia.org/wiki/RGB_color_model) Led, který je připojena na [PWM](https://en.wikipedia.org/wiki/Pulse-width_modulation) výstupy Arduina. Jedná se o zapojení se společnou anodou (**svítí při LOW**). 

| Pin | Funkce   |
| --- | --- |
| 5   | RGB LED: G |
| 6   | RGB LED: B |
| 9   | RGB LED: R |

Užitečné funkce:
- [pinMode](https://www.arduino.cc/en/Reference/PinMode)
- [digitalWrite](https://www.arduino.cc/en/Reference/DigitalWrite)
- [analogWrite](https://www.arduino.cc/en/Reference/AnalogWrite) (pro řízení jasu LED pomocí PWM)

### Tlačítko

Shield obsahuje jedno tlačítko. Je připojeno proti zemi (**při stisku je LOW**). 

| Pin | Funkce   |
| --- | --- |
| 2   | Tlačítko |

Užitečné funkce:
- [pinMode](https://www.arduino.cc/en/Reference/PinMode)
- [digitalRead](https://www.arduino.cc/en/Reference/DigitalRead)
- [attacheInterrupt](https://www.arduino.cc/en/Reference/AttachInterrupt) (pokud chcete využít [přerušení](https://en.wikipedia.org/wiki/Interrupt) procesoru)

Užitečné knihovny:
- [Bounce2](https://github.com/thomasfredericks/Bounce2) (pro řešení [zákmitů](https://en.wikipedia.org/wiki/Switch#Contact_bounce))

### Fotorezistror

[Fotorezistor](https://cs.wikipedia.org/wiki/Fotorezistor) je zapojený jako [napěťový dělič](https://cs.wikipedia.org/wiki/D%C4%9Bli%C4%8D_nap%C4%9Bt%C3%AD) a připojený k pinu **A0**. 

Fotorezistor je zapojený v horní polovině děliče, tzn. **víc světla ~ menší odpor ~ vyšší napětí**.

Užitečné funkce:
- [analogRead](https://www.arduino.cc/en/Reference/AnalogRead)

Odkazy:
- [datasheet (PDV-P8001)](https://github.com/bastlirna/arduino-akademie/raw/master/doc/datasheets/PDV-P8001.pdf)

### Termistor

[Termistor](https://cs.wikipedia.org/wiki/Termistor) je zapojený jako [napěťový dělič](https://cs.wikipedia.org/wiki/D%C4%9Bli%C4%8D_nap%C4%9Bt%C3%AD) a připojený k pinu **A1**. 

Termistor je zapojený v horní polovině děliče, tzn. **vyšší teplota ~ menší odpor ~ vyšší napětí**.

Užitečné funkce:
- [analogRead](https://www.arduino.cc/en/Reference/AnalogRead)

Odkazy:
- [datasheet (MF52A2103J3470)](https://github.com/bastlirna/arduino-akademie/raw/master/doc/datasheets/cantherm_mf52_1.pdf)
- [Převod odporu na stupně](http://www.cantherm.com/index.php/rt-characteristics)

### Display

Na desce je 4-místný 7-degmentový LED display. Display je připojen přes I2C sběrnici.

I2C Adresa: `0x27`

### RTC

Na desce je obvod hodin reálného času DS1307.

I2C Adresa: `0x68`

Odkazy:
- [datasheet (DS1307)](https://github.com/bastlirna/arduino-akademie/raw/master/doc/datasheets/DS1307.pdf)
