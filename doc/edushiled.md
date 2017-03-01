# EduShiled

## Piny

| Pin | Funkce   |
| --- | --- |
| 2   | Tlačítko |
| 3   | RTC SQW out |
| 4   | --- |
| 5   | RGB LED: G |
| 6   | RGB LED: B |
| 7   | --- |
| 8   | --- |
| 9   | RGB LED: R |
| 10   | --- |
| 11   | --- |
| 12   | --- |
| 13 | Semafor: zelená |
| 14 (A0) | fotorezistor |
| 15 (A1) | termistor |
| 16 (A2) | Semafor: červená |
| 17 (A3) | Semafor: oranžová |
| 18 (A4) | I2C SDA |
| 19 (A5) | I2C SCK |

## Funkční bloky

### LED (semafor)

Shield obsahuje 3 LED v barvách semaforu. LED jsou zapojeny proti zemi (**svítí při HIGH**).

| Pin | Funkce   |
| --- | --- |
| 13 | Semafor: zelená |
| 16 | Semafor: cervená |
| 17 | Semafor: oranžová |

Potřebné fce:
- pinMode
- digitalWrite

### RGB LED 

Deska obsahuje jednu RGB Led, který je pripojena na PWM výstupy Arduina. Jedná se o zapojení se společnou anodou (**svítí při LOW**). 

| Pin | Funkce   |
| --- | --- |
| 5   | RGB LED: G |
| 6   | RGB LED: B |
| 9   | RGB LED: R |

Potrebné fce:
- pinMode
- digitalWrite
- analogWrite (pro rízení jasu LED)

### Tlačítko

Deska obsahuje jedno tlacítko. Je pripojeno proti zemi (**při stisku je LOW**). 

| Pin | Funkce   |
| --- | --- |
| 2   | Tlačítko |

Potřebné fce:
- pinMode
- digitalRead
- attacheInterrupt (pokud chcete využít přerušení procesoru)

Užitečná knihovna:
- debounce (pokud potřebujete řešit zákmity tlačítka)

### Fotorezistror

[Fotorezistor](https://cs.wikipedia.org/wiki/Fotorezistor) je zapojený jako [napěťový dělič](https://cs.wikipedia.org/wiki/D%C4%9Bli%C4%8D_nap%C4%9Bt%C3%AD) a připojený k pinu **A0**. 

Fotorezistor je zapojený v horní polovině děliče, tzn. **víc světla ~ měnší odpor ~ vyšší napětí**.

Potřebné fce:
- analogRead

TODO datasheet

- datasheet (PDV-P8001)

### Termistor

[Termistor](https://cs.wikipedia.org/wiki/Termistor) je zapojený jako [napěťový dělič](https://cs.wikipedia.org/wiki/D%C4%9Bli%C4%8D_nap%C4%9Bt%C3%AD) a připojený k pinu **A1**. 
Termistor je zapojený v horní polovině děliče, tzn. **vyšší teplota ~ měnší odpor ~ vyšší napětí**.

Potřebné fce:
- analogRead

TODO přepočet (aspoň přibližný) (http://www.cantherm.com/index.php/rt-characteristics)

Odkazy:

- datasheet (MF52A2103J3470)

### Display



### RTC








