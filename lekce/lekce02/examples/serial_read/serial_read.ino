#define LED 13

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Send: 1 ... ON, 0 ... OFF");
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();

    switch (c) {
      case '1':
        digitalWrite(LED, HIGH);
        Serial.println("ON");
        break;
      case '0':
        digitalWrite(LED, LOW);
        Serial.println("OFF");
        break;
      default:
        Serial.println("Unknown command");
    }
  }
}
