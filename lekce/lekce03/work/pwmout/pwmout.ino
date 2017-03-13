void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

void loop() {

  for(int i = 0; i <= 0xFF; i++)
  {
    Serial.println(i, DEC);
    analogWrite(10, i);
    delay(100);
  }

}
