#include <ArduinoJson.h>
#include "FS.h"
#include "globals.h"

#ifndef CONFIG_H
#define CONFIG_H

#define CONFIGURATION "/config.json"
#define CONFIGURATION_WIFI_AP "wifiAP"
#define CONFIGURATION_WIFI_SSID "wifiSSID"
#define CONFIGURATION_WIFI_PASSWORD "wifiPassword"
#define CONFIGURATION_SERVER_NAME "serverName"
#define CONFIGURATION_ADMIN_PASSWORD "adminPassword"

void configSetup();
bool configLoad();
void configReset();

#endif
