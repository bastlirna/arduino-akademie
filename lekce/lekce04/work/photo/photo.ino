void setup() {
  Serial.begin(9600);
}

void loop() {
  float a = analogRead(A1) * (5.0 / 1024);
  Serial.println(a, DEC);
  delay(100);
}
