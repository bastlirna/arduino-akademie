#define LEDR 16
#define LEDO 17
#define LEDG 13

void setup() {
  pinMode(LEDR, OUTPUT);
  pinMode(LEDO, OUTPUT);
  pinMode(LEDG, OUTPUT);
  Serial.begin(9600);
}

byte state = 0;
unsigned long last, interval = 1;

void semafor(bool red, bool orange, bool green) {
  digitalWrite(LEDR, red);
  digitalWrite(LEDO, orange);
  digitalWrite(LEDG, green);
}

void loop() {
  unsigned long now = millis();

  if (now - last >= interval * 1000) {
    switch (state) {
      case 0:
        Serial.println("RED");
        semafor(1, 0, 0);
        interval = 10;
        break;
      case 1:
        Serial.println("RED+ORANGE");
        semafor(1, 1, 0);
        interval = 1;
        break;
      case 2:
        Serial.println("GREEN");
        semafor(0, 0, 1);
        interval = 10;
        break;
      case 3:
        Serial.println("ORANGE");
        semafor(0, 1, 0);
        interval = 1;
        break;
    }

    state = state + 1;
    if (state > 3) state = 0;
    last = now;
  }
}
