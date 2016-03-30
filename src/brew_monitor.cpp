#include "Arduino.h"
#include "display.h"
#include "wifi.h"
#include "web_server.h"
#include "config.h"

#define BUTTON 0

#define buttonPressed false

// Default Settings
const char *adminPassword = "admin";
const char *serverName = "brewmonitor";

// Define functions here
void setupGPIO();
void setupDataPush();

void setup() {
  delay(5000);
  Serial.begin(115200);

  setupGPIO();

  if(buttonPressed) {
    delay(2000); // Ideally we should monitor for pin changes, but this will do for now
    if(buttonPressed) {
      resetConfiguration();
    }
  }

  if(loadConfiguration()) {
    wifiSetup();
    setupDataPush();
  }
  else {
    wifiSetupAP();
  }

  webServerSetup();
}

void loop() {
  webServerLoop();
}

void setupGPIO() {
  pinMode(BUTTON, INPUT_PULLUP);
  SPIFFS.begin();
}

void setupDataPush() {

}


