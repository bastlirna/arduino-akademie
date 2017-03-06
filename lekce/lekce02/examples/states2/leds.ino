#define LED_G 13
#define LED_R 16
#define LED_O 17

void setupLeds(){
  setupLed(LED_G);
  setupLed(LED_R);
  setupLed(LED_O);
}

void setupLed(byte pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}

void leds(bool red, bool orange, bool green) {
  digitalWrite(LED_R, red);
  digitalWrite(LED_O, orange);
  digitalWrite(LED_G, green);
}
