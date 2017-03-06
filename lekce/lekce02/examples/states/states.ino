#define LED_G 13
#define LED_R 16
#define LED_O 17

byte state = 5;
unsigned int next;
unsigned long last;

bool change;

const int b = 500;

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

  if (millis() - last >= next) {

    switch (state) {
      
      case 0:
        leds(1,0,0);
        if (change) {
          state = 5; 
          next = b;
          change = false;
        } else {
          state = 1;
          next = 5*b;
        }
        break;
        
      case 1:
        leds(1,1,0);
        next = b;
        state = 2;
        break;
        
      case 2:
        leds(0,0,1);
        next = 5*b;
        state = 3;
        break;       
          
      case 3:
        leds(0,1,0);
        next = b;
        state = 0;
        break;  
        
      case 4:
        leds(0,0,0);
        next = b;    
        state = 5;
        break;
        
      case 5:
        leds(0,1,0);
        next = b;
        
        if (change) {
          state = 0; 
          change = false;
        } else {
          state = 4;
        }
        
        break;
   }

    Serial.print("Next state ");
    Serial.print(state);
    Serial.print(" in ");
    Serial.print(next);
    Serial.println(" ms");

   last = millis();
  }

  if (digitalRead(2) == LOW && change == false) {
    change = true;
    Serial.println("BUTTON");
    delay(100);
  }
}

void leds(bool red, bool orange, bool green) {
  digitalWrite(LED_R, red);
  digitalWrite(LED_O, orange);
  digitalWrite(LED_G, green);
}

