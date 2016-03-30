#include <ArduinoJson.h>
#include "FS.h"

#ifndef CONFIG_H
#define CONFIG_H

#define CONFIGURATION "/config.json"
#define CONFIGURATION_WIFI_SSID "wifiSSID"
#define CONFIGURATION_WIFI_PASSWORD "wifiPassword"
#define CONFIGURATION_SERVER_NAME "serverName"
#define CONFIGURATION_ADMIN_PASSWORD "adminPassword"

extern const char *wifiSSID;
extern const char *wifiPassword;
extern const char *adminPassword;
extern const char *serverName;

bool loadConfiguration();
void resetConfiguration();

#endif
