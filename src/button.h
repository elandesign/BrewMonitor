#ifndef BUTTON_H
#define BUTTON_H
  
#define BUTTON_GPIO 2

void buttonSetup();
void buttonLoop();
bool buttonPressed();

#endif
