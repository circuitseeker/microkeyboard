#include "Keyboard.h"

const int SHIFT_N_PIN = 4; // Combine Left Shift + 'n'
const int SPACE_PIN = 6;    // Space
const int SHIFT_P_PIN = 7;  // Combine Left Shift + 'p'

void setup() {
  // initialize control over the keyboard:
  Keyboard.begin();
  pinMode(SHIFT_N_PIN, INPUT_PULLUP);
  pinMode(SPACE_PIN, INPUT_PULLUP);
  pinMode(SHIFT_P_PIN, INPUT_PULLUP);
}

void loop() {
  // Check if Left Shift + 'n' button is pressed
  if (digitalRead(SHIFT_N_PIN) == LOW) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write('n');
    delay(100);
    Keyboard.releaseAll();
  }

  // Check if Space button is pressed
  if (digitalRead(SPACE_PIN) == LOW) {
    Keyboard.write(' ');
    delay(100);
  }

  // Check if Left Shift + 'p' button is pressed
  if (digitalRead(SHIFT_P_PIN) == LOW) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write('p');
    delay(100);
    Keyboard.releaseAll();
  }

  delay(50); // Add a small delay to avoid multiple rapid key presses
}
