#include "Arduino.h"
#include <Ticker.h>

#include "globals.h"
#include "config.h"
#include "button.h"
#include "display.h"
#include "wifi.h"
#include "web_server.h"
#include "mdns.h"
#include "sensors.h"

Ticker ticker;

bool takeReadingsNow = false;

void tick() {
  takeReadingsNow = true;
}

void setup() {

  delay(5000);
  Serial.begin(115200);

  buttonSetup();

  configSetup();
  
  if(wifiAP)
    wifiSetupAP();
  else {
    wifiSetup();
    mdnsSetup();
  }

  sensorsSetup();

  ticker.attach(takeReadingsEvery, tick);

  webServerSetup();
}

void loop() {
  buttonLoop();
  webServerLoop();

  if(takeReadingsNow) {
    takeReadingsNow = false;
    sensorsRead();
  }
}

