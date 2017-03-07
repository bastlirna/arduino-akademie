#define LED_G 13
#define LED_R 16
#define LED_O 17

#define BUTTON 2

#define SHORT_PAUSE 500
#define LONG_PAUSE 1000

byte state = 5;
unsigned int interval;
unsigned long last;

bool change;

void setup() {
  setupLed(LED_G);
  setupLed(LED_R);
  setupLed(LED_O);

  Serial.begin(9600);
}

void setupLed(byte pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}

void loop() {
  loopStates();
  loopButton();
}

void loopStates() {

  if (millis() - last >= interval) {
    switch (state) {
      
      // Červená
      case 0:
        leds(1,0,0);
        if (change) {
          state = 5; 
          interval = SHORT_PAUSE;
          change = false;
        } else {
          state = 1;
          interval = LONG_PAUSE;
        }
        break;
        
      case 1:
        leds(1,1,0);
        interval = SHORT_PAUSE;
        state = 2;
        break;
        
      case 2:
        leds(0,0,1);
        interval = LONG_PAUSE;
        state = 3;
        break;       
          
      case 3:
        leds(0,1,0);
        interval = SHORT_PAUSE;
        state = 0;
        break;  
        
      case 4:
        leds(0,0,0);
        interval = SHORT_PAUSE;    
        state = 5;
        break;
        
      case 5:
        leds(0,1,0);
        interval = SHORT_PAUSE;
        if (change) {
          state = 0; 
          change = false;
        } else {
          state = 4;
        }
        break;
   }

    Serial.print("interval state ");
    Serial.print(state);
    Serial.print(" in ");
    Serial.print(interval);
    Serial.println(" ms");

    last = millis();
  }

}

void loopButton() {
  if (digitalRead(BUTTON) == LOW && change == false) {
    Serial.println("BUTTON PRESSED");
    change = true;
  }
}

void leds(bool red, bool orange, bool green) {
  digitalWrite(LED_R, red);
  digitalWrite(LED_O, orange);
  digitalWrite(LED_G, green);
}

