#define RESISTOR_CONNECT_THERMISTOR  10000

/* Return: Temperature that range from -40 to 125 degrees.  */
float getTemperature(int a) {
  float temperature, resistance;
  resistance = (float)(1023-a)*RESISTOR_CONNECT_THERMISTOR/a; //Calculate the resistance of the thermistor
  int B = 3975;
  /*Calculate the temperature according to the following formula.*/
  temperature  = 1/(log(resistance/RESISTOR_CONNECT_THERMISTOR)/B+1/298.15)-273.15;
  return temperature;// the type convert from floating point to 8-bit integer
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  int a = analogRead(A1);
  float c = getTemperature(a);
  Serial.println(c, DEC);
  delay(100);
}
