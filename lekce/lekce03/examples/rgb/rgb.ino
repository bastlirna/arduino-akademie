#define RGB_R 9
#define RGB_G 5
#define RGB_B 6

void setup () {
  setupLed(RGB_R);
  setupLed(RGB_G);
  setupLed(RGB_B);

  Serial.begin(9600);
}

void setupLed(byte pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
}

void loop () {
  for(int i = 0; i <= 7; i++) {
    bool r = i & 1;
    bool g = i & 2;
    bool b = i & 4;

    color(0, 0, 0);
    delay(300);
    color(r, g, b);
    delay(1000);
  }
}

void color(bool r, bool g, bool b) {
  digitalWrite(RGB_R, !r);
  digitalWrite(RGB_G, !g);
  digitalWrite(RGB_B, !b);
}

