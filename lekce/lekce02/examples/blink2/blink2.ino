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
  }
}

void invert(byte pin){
  digitalWrite(pin, ! digitalRead(pin));
}

