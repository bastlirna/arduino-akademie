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

### Úkola: Zobrazte text `AHOJ`

## Stopky

### Úkol: Naprogramujte jednoduché stopy

- Zařízení budě meřit uběhnutý čas a zobrazovat ho na displeji
- Krátkým stiskem dojde ke spuštění/pozastavení měření
- Při opakovaném stisku tlačítka se pokračuje v předešlém měření
- Dlouhám stiskem dojde k zastavení a nastavení času 0
- Na display se zobrazuje ve formátu `ss.aa`, kde `ss` jsou vteřiny `aa` setiny vteřin.
- Stopky se zastaví po dosažení 99.99 s.
