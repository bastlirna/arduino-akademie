# Lekce 2

## Osnova

- Odkaz na materiály, nějaké otázky z minula?
- Sériová komunikace
- Neblokující programování 
- Stavový automat

## Seriová komunikace

### Trocha teorie

- Seriova vs paralelní komunikace
- Synchroni vs asynchroni komunikace
- Fullduplex vs halfduplex komunikace 
- UART
- Rychlost (boud rate)
- ASCII
- Převodník USB - UART
- Kde se UART používá (AT příkazy, ...)

### Úkol: Hello World

Napište kód, který posílá text z Arduina do PC

```Arduino
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Hallo World!");
  delay(1000);
}
```

### Úkol: Přijmutí znaku

Napište kód, který přijme znak `0` nebo `1` z PC a na základě něj rozsvítí/zhasne LED

[Ukázka řešení](examples/serial_read/serial_read.ino)

Prozkoumejte další možnosti třídy [Stream](https://www.arduino.cc/en/Reference/Stream).

## Blokující a neblokující kód  

### Trocha teorie

- Aktivní čekání
- Multitasking
- Blokující vs neblokující fce.

### Úkol: Blikání více LED

Napište kód, který bude blikat 3 LED s každou v jiném intervalu

**[Řešení napsané během hodiny](work/blink/blink.ino)** | [Řešení](examples/blink2/blink2.ino)

## Stavový automat

### Trocha teorie

- Konečný stavový automat (FSM)

### Úkol: Semafor

Napište semafor

**[Řešení napsané během hodiny](work/semafor/semafor.ino)** | [Řešení](examples/states/states.ino)

#### Na rámec

Řešení pomocí funkcí založené na [ukazatelích na funkce](http://boredzo.org/pointers/).

[Řešení](examples/states2/state)


