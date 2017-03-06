# Lekce 2

## Osnova

- Seriová komunikace
- Neblokující programování 
- Stavový automat

## Seriová komunikace

### Trocha teorie

- Seriova vs Paraelni komunikace
- Synchroni vs Asynchroni komunikace
- Fullduplex vs halfduplex komunikace 
- UART
- Rychlost (boud rate)
- RS-232, RS-485, RS-422, ...
- Převodník USB - UART
- Kde se UART používá (AT příkazy, ...)


### Příklady

#### Kod hello world

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

#### Prijmuti znaku (zkouska kodu)

Napište kód, který přijmá znak `0` nebo `1` z PC a na základě něc rozsvítí/zhasne LED

```Arduino
#define LED 13

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Send: 1 ... ON, 0 ... OFF");
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    switch (c) {
      case '1':
        digitalWrite(LED, HIGH);
        Serial.println("ON");
        break;
      case '0':
        digitalWrite(LED, LOW);
        Serial.println("OFF");
        break;
      default:
        Serial.println("Unknown command");
    }
  }
}
```

Prozkoumejte další možnosti třídy [Stream](https://www.arduino.cc/en/Reference/Stream).

## Blokující a nebolkující kód  

### Trocha teorie

- Aktivní čekání
- Multitasking
- Blokující vs neblokující fce.

#### Blikání více LED

Napište kód, který bude blikat 3 LED s každou v jiném intervalu


## Stavový automat

### Trocha teorie

- Konečný stavový automat (FSM)

#### Semafor

Napište semafor

#### Na rámec

http://boredzo.org/pointers/


