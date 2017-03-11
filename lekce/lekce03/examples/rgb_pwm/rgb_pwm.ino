#define RGB_R 9
#define RGB_G 5
#define RGB_B 6

struct Color {
  byte R; byte G; byte B;
};

static const Color Red = {0xFF, 0, 0};
static const Color Green = {0, 0xFF, 0};
static const Color Blue = {0, 0, 0xFF};

void setup () {
  Serial.begin(9600);
  pinMode(RGB_R, OUTPUT);
  pinMode(RGB_G, OUTPUT);
  pinMode(RGB_B, OUTPUT);
  color(0,0,0);
}

void color(byte r, byte g, byte b) {
  analogWrite(RGB_R, 0xFF - r);
  analogWrite(RGB_G, 0xFF - g);
  analogWrite(RGB_B, 0xFF - b);
}

void color(Color c) {
  printColor(c);
  color(c.R, c.G, c.B);
}

Color brightnes(Color o, float f) {
  return { 
    o.R * f,
    o.G * f,
    o.B * f
  };
}


void loop () {
  /*color(Red);
  delay(1000);
  color(brightnes(Green, 10));
  delay(1000);
  color(Blue);
  delay(1000);
*/


  for(int h = 0; h < 360; h+= 5) {
    Color c = hsv2rgb(h, 255, 255);
    color(c);
    delay(100);
  }
}

void printColor(Color c)
{
  Serial.print("RGB ");
  Serial.print(c.R, DEC);
  Serial.print(", ");
  Serial.print(c.G, DEC);
  Serial.print(", ");
  Serial.println(c.B, DEC);
}

Color hsv2rgb(int hue, int sat, int val) {
  // http://www.kasperkamperman.com/blog/arduino/arduino-programming-hsb-to-rgb/
  
  Color result;
  int r;
  int g;
  int b;

  int base;

  if (sat == 0) { // Acromatic color (gray). Hue doesn't mind.
    result.R = val;
    result.G = val;
    result.B = val;
  } else  { 
    base = ((255 - sat) * val)>>8;

    switch(hue/60) {
    case 0:
        r = val;
        g = (((val-base)*hue)/60)+base;
        b = base;
    break;
    case 1:
        r = (((val-base)*(60-(hue%60)))/60)+base;
        g = val;
        b = base;
    break;
    case 2:
        r = base;
        g = val;
        b = (((val-base)*(hue%60))/60)+base;
    break;
    case 3:
        r = base;
        g = (((val-base)*(60-(hue%60)))/60)+base;
        b = val;
    break;
    case 4:
        r = (((val-base)*(hue%60))/60)+base;
        g = base;
        b = val;
    break;
    case 5:
        r = val;
        g = base;
        b = (((val-base)*(60-(hue%60)))/60)+base;
    break;
    }

    result.R = r;
    result.G = g;
    result.B = b;
  }   
  return result;
}

