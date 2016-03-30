#include "Arduino.h"
#include "button.h"

void buttonSetup() {
  pinMode(BUTTON_GPIO, INPUT_PULLUP);
}

void buttonLoop() {
  
}

bool buttonPressed() {
  return false;
}
