// Pin assignments based on schematic
const int BUT1 = 26; // GPIO26
const int BUT2 = 27; // GPIO27
const int BUT3 = 28; // GPIO28

const int LED1 = 29; // GPIO29
const int LED2 = 6;  // GPIO6
const int LED3 = 7;  // GPIO7

long but1time;
long but2time;
long but3time = 0;

void setup() {
  // Buttons as inputs with pull-up resistors
  pinMode(BUT1, INPUT_PULLUP);
  pinMode(BUT2, INPUT_PULLUP);
  pinMode(BUT3, INPUT_PULLUP);

  // LEDs as outputs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  if (digitalRead(BUT1) == LOW) {
    but1time = millis();
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }

  if (digitalRead(BUT2) == LOW) {
    but2time = millis();
  }

  if (abs(but2time - but1time) <= 2000) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }

  if (digitalRead(BUT3) == LOW) {
    but3time++;
  } else {
    but3time = 0;
  }

  if (but3time >= 800) {
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }

  delay(1); // smooth looping
}

