const int ledPin = 13;    // This constant variable stores the pin number for the LED.
const int buttonPin = 2;  // This constant variable stores the pin number for the button.

const char* morseCode[] = {
".-", // A
"-...", // B
"-.-.", // C
"-..", // D
".", // E
"..-.", // F
"--.", // G
"....", // H
"..", // I
".---", // J
"-.-", // K
".-..", // L
"--", // M
"-.", // N
"---", // O
".--.", // P
"--.-", // Q
".-.", // R
"...", // S
"-", // T
"..-", // U
"...-", // V
".--", // W
"-..-", // X
"-.--", // Y
"--.." // Z
};

const char* morseCodeForNikhil[] = { "N", "I", "K", "H", "I", "L" };  // This constant array stores the Morse code for the name "Nikhil".

void setup() {
  pinMode(ledPin, OUTPUT);    // This function sets the LED pin as an output.
  pinMode(buttonPin, INPUT);  // This function sets the button pin as an input.
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {                                                     // This if statement checks if the button is pressed.
    for (int i = 0; i < sizeof(morseCodeForNikhil) / sizeof(morseCodeForNikhil[0]); i++) {  // This for loop iterates through the Morse code array and blinks the LED for each character.
      char character = *morseCodeForNikhil[i];
      blink(morseCode[character - 'A']);
      blink(morseCodeForNikhil[i]);
    }
  }

  Serial.println(digitalRead(buttonPin));  // This line prints the value of the button pin to the serial monitor.
}

void blink(const char* morseCode) {              // This function blinks the LED for the specified Morse code character.
  for (int i = 0; i < strlen(morseCode); i++) {  // This for loop iterates through the Morse code character and blinks the LED for each dot or dash.
    if (morseCode[i] == '.') {
      digitalWrite(ledPin, HIGH);             // turn on led and buzzer
      Serial.print(".");                      // print on serial monitor
      delay(300);                             // pause of 0.3 seconds
      digitalWrite(ledPin, LOW);              // turn off led and buzzer
      delay(200);                             // pause of 0.2 seconds
    } else if (morseCode[i] == '-') {
      digitalWrite(ledPin, HIGH);             // turn on led and buzzer
      Serial.print("-");                      // print on serial monitor
      delay(600);                             // pause of 0.6 seconds
      digitalWrite(ledPin, LOW);              // turn off led and buzzer
      delay(200);                             // pause of 0.2 seconds
    }
  }
  Serial.println();   // blank line
  delay(1000);  // This line delays for 2000 milliseconds after blinking the LED.
}