#define SHORT_PAUSE 500
#define LONG_PAUSE 1000

typedef void (*fn)(void);

fn state;
bool change;
unsigned long lastTime, nextTime;

void setup() {
  setupLeds();
  Serial.begin(9600);

  state = &standBy;
}

// states

void red() {
  leds(1,0,0);
  
  if (change) {
    next(&standBy, SHORT_PAUSE);
    change = false;
  } else {
    next(&redOrange, LONG_PAUSE);
  }
}

void redOrange() {
  leds(1,1,0);
  next(&green, SHORT_PAUSE);
}

void green() {
  leds(0,0,1);
  next(&orange, LONG_PAUSE);
}

void orange() {
  leds(0,1,0);
  next(&red, SHORT_PAUSE);
}

void standBy() {
  leds(0,1,0);

  if (change) {
    next(&red, SHORT_PAUSE);
    change = false;
  } else {
    next(&standByOff, SHORT_PAUSE);  
  }
}

void standByOff() {
  leds(0,0,0);
  next(&standBy, SHORT_PAUSE);
}

// ---

void loop() {
  if (millis() - lastTime >= nextTime) {
    state();
    lastTime = millis();
  }

  if (digitalRead(2) == LOW && change == false) {
    change = true;
    Serial.println("BUTTON");
    delay(100);
  }
}

void next(fn nextState, unsigned long t) {
  state = nextState;
  nextTime = t;
}


