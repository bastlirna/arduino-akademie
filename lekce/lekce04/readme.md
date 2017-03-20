# Lekce 4

## Osnova

- Otázky z minula?
- Display jednoduše
- Měření světla
- Teploměr

## Display jednoduše

 - Jak si přidat knihovnu pro displej

```Arduino
#include <edushield.h>

void Display.number(unsigned int n);
```

### Úkol: Zobrazte na display číslo arduina

## Měření světla

```Arduino
int a = analogRead(A0);
// ...
```

### Úkol: Naměřit intensitu osvětlení a poslat po seriovce
### Úkol: Naměřit intensitu osvětlení a zobrazit na displej


## Teploměr

```Arduino
#define RESISTOR_CONNECT_THERMISTOR  10000

/* Return:int8_t,Temperature that range from -40 to 125 degrees.  */
int8_t getTemperature(int a)
{
  float temperature,resistance;
  resistance   = (float)(1023-a)*RESISTOR_CONNECT_THERMISTOR/a; //Calculate the resistance of the thermistor
  int B = 3975;
  /*Calculate the temperature according to the following formula.*/
  temperature  = 1/(log(resistance/RESISTOR_CONNECT_THERMISTOR)/B+1/298.15)-273.15;
  return (int8_t)temperature;// the type convert from floating point to 8-bit integer
}
```

### Úkol: Naměřit teplotu a vypsat po seriové lince
### Úkol: Naměřit teplotu a vypsat na displej
