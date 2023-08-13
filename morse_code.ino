const int ledPin = 13;
const int buttonPin = 2;

const char* morseCodeForNikhil[] = {"-.", "..", "-.-", "....", "..", ".-.."};

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    for (int i = 0; i < sizeof(morseCodeForNikhil) / sizeof(morseCodeForNikhil[0]); i++) {
      blink(morseCodeForNikhil[i]);
    }
  }

  Serial.println(digitalRead(buttonPin));
}

void blink(const char* morseCode) {
  for (int i = 0; i < strlen(morseCode); i++) {
    if (morseCode[i] == '.') {
      digitalWrite(ledPin, HIGH);
      delay(300);
      digitalWrite(ledPin, LOW);
      delay(300);
    } else if (morseCode[i] == '-') {
      digitalWrite(ledPin, HIGH);
      delay(1000);
      digitalWrite(ledPin, LOW);
      delay(1000);
    }
  }
  delay(2000);
}