#include <Wire.h>

#define BTN_PIN 2

#define BTN_IDLE 0
#define BTN_SHORT_PRESS 1
#define BTN_LONG_PRESS 2

// --- Globální proměnné ------------------------------------------------------

// naměřený čas (zobrazuje se na displeji)
unsigned long time = 0;

// čas poslední aktualizace (absolutní čas z funkce millis)
unsigned long last_update = 0;

// stav stopek (běží/stojí)
bool running = false;

// aktuální stav tlačítka 
byte btn_event = BTN_IDLE;

// 7-segment font
const byte NUMBER_FONT[] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111, // 9
  0b01110111, // A
  0b01111100, // B
  0b00111001, // C
  0b01011110, // D
  0b01111001, // E
  0b01110001  // F
}; 

// --- Program ----------------------------------------------------------------

void setup() {
	Serial.begin(9600);
	Wire.begin();
	pinMode(BTN_PIN, INPUT);
}

void loop() {

	// zkontrolovat tlačítko
	btn_loop();
	
	// reakce na událost od tlačítka
	if (btn_event != BTN_IDLE) {

		if (btn_event == BTN_SHORT_PRESS) {
			running = ! running;
			last_update = millis();
		}

		if (btn_event == BTN_LONG_PRESS) {
			running = false;
			time = 0;
		}

		// událost tlačítka byla zpracování -> IDLE
		btn_event = BTN_IDLE;
	}

	if (running) {
		// aktualizace času
		unsigned long now = millis();
		time += now - last_update;
		last_update = now;
	}

	update_display();
}

// --- Pomocné funkce ---------------------------------------------------------


bool btn_state = false;
bool btn_processed = false;
unsigned long btn_change_time;

void btn_loop() {
	
	bool new_state = ! digitalRead(BTN_PIN);
	bool changed = new_state != btn_state;
	unsigned long dur = millis() - btn_change_time;

	if (changed && dur < 10) {
		// debounced
		btn_state = new_state;
		btn_change_time = millis();
		return;
	}

	if (btn_processed == false)	{
		if (btn_state == true && dur > 1000) {
			// long press
			Serial.println("LONG PRESS");
			btn_event = BTN_LONG_PRESS;
			btn_processed = true;
		}

		if (changed && new_state == false && dur > 50) {
			// short press
			Serial.println("SHORT PRESS");
			btn_event = BTN_SHORT_PRESS;
			btn_processed = true;
		}
	}

	if (changed) {
		if (new_state == false) {
			btn_processed = false;
		}

		btn_state = new_state;
		btn_change_time = millis();
	}
}

void update_display() {
	unsigned long t = min(time, 99990);

	byte a = t / 10000;
	t = t % 10000;

	byte b = t / 1000;
	t = t % 1000;

	byte c = t / 100;
	t = t % 100;

	byte d = t / 10;

	digit(0, NUMBER_FONT[a]);
	digit(1, NUMBER_FONT[b] | 0b10000000);
	digit(2, NUMBER_FONT[c]);
	digit(3, NUMBER_FONT[d]);		
}

byte current_digit[4];

void digit(byte n, byte v) {

	if (current_digit[n] == v) {
		return;
	}

	Wire.beginTransmission(0x27);
	Wire.write(n);
	Wire.write(v);
	Wire.endTransmission();

	current_digit[n] = v;
}