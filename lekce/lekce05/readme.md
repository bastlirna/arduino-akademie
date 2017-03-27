# Lekce 5

## Osnova

- Otázky z minula?
- I2C & display
- 7-segment display a jeho řízení
- Stopky

## I2C

### Trocha teorie

- ?

## 7-segment dipslay

### Trocha terie

- Rozložení segmentů
- Multiplexní řízení
- Co je driver displeje
- ATTiny2313

```arduino
const byte NUMBER_FONT[] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111, // 9
  0b01110111, // A
  0b01111100, // B
  0b00111001, // C
  0b01011110, // D
  0b01111001, // E
  0b01110001  // F
}; 
```

### Úkola: Zobrazte text `AHOJ`

## Stopky

### Úkol: Naprogramujte jednoduché stopy

- Zařízení budě meřit uběhnutý čas a zobrazovat ho na displeji
- Krátkým stiskem dojde ke spuštění/pozastavení měření
- Při opakovaném stisku tlačítka se pokračuje v předešlém měření
- Dlouhám stiskem dojde k zastavení a nastavení času 0
- Na display se zobrazuje ve formátu `ss.aa`, kde `ss` jsou vteřiny `aa` setiny vteřin.
- Stopky se zastaví po dosažení 99.99 s.
