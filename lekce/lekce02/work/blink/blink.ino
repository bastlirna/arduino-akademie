#define LEDR 13
#define LEDO 16
#define LEDG 17

void setup() {
  pinMode(LEDR, OUTPUT);
  pinMode(LEDO, OUTPUT);
  pinMode(LEDG, OUTPUT);
  Serial.begin(9600);
}

unsigned long lastR = 0, lastO = 0, lastG = 0;

void loop() {
  unsigned long now = millis();

  if (now - lastR >= 1000) {
    Serial.println("blik Red");
    lastR = now;
  }

  if (now - lastO >= 3000) {
    Serial.println("blik Orange");
    lastO = now;
  }

  if (now - lastG >= 5000) {
    Serial.println("blik Green");
    lastG = now;
  }
}