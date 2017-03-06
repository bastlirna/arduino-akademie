#define LED_G 13
#define LED_R 16
#define LED_O 17

unsigned long lastG, lastR, lastO;

void setup() {
  setupLed(LED_G);
  setupLed(LED_R);
  setupLed(LED_O);
}

void setupLed(byte pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}

void loop() {
  /*
  if (millis() - lastG > 500) {
    invert(LED_G);
    lastG = millis();
  }

  if (millis() - lastR > 333) {
    invert(LED_R);
    lastR = millis();
  }

  if (millis() - lastO > 200) {
    invert(LED_O);
    lastO = millis();
  }*/

  blinkLoop(LED_G, 523, &lastG);
  blinkLoop(LED_O, 333, &lastO);
  blinkLoop(LED_R, 123, &lastR);
}

void invert(byte pin){
  digitalWrite(pin, ! digitalRead(pin));
}

void blinkLoop(byte pin, unsigned int interval, unsigned long *last) {
  if (millis() - *last >= interval) {
    invert(pin);
    *last = millis();
  }
}

