#include <ESP8266WiFi.h>
#include "config.h"

#define AP_SSID "BREWMONITOR"

#ifndef WIFI_H
#define WIFI_H

void wifiSetup();
void wifiSetupAP();

#endif
