#include "Arduino.h"
#include "button.h"
#include "globals.h"

void buttonSetup() {
  pinMode(BUTTON, INPUT_PULLUP);
  attachInterrupt(BUTTON, buttonInterrupt, FALLING);
}

void buttonLoop() {
  if(buttonPressed) {
    buttonPressed = false;
  }
}

void buttonInterrupt() {
  buttonPressed = true;
}
