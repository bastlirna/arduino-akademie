#define RGB_R 9
#define RGB_G 5
#define RGB_B 6

void setup() {
  pinMode(RGB_R, OUTPUT);
  analogWrite(RGB_R, 255);
}

void color(byte r, byte g, byte b) {
  analogWrite(RGB_R, 255 - r);
  analogWrite(RGB_G, 255 - g);
  analogWrite(RGB_B, 255 - b);
}

void loop() {
  for (int r = 0; r <= 255; r += 64) {
    for (int g = 0; g <= 255; g += 64) {
      for (int b = 0; b <= 255; b += 64) {
        color(r, g, b);
        delay(200);
      }
    }
  }
}
