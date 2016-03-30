#include "Arduino.h"
#include "config.h"

bool loadConfiguration() {
  if(!SPIFFS.exists(CONFIGURATION))
    return false;

  File configFile = SPIFFS.open(CONFIGURATION, "r");

  if(!configFile)
    return false;

  size_t size = configFile.size();

  std::unique_ptr<char[]> buf(new char[size]);
  configFile.readBytes(buf.get(), size);

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());

  if (json.success()) {
    if(json.containsKey(CONFIGURATION_WIFI_SSID))
      wifiSSID = json[CONFIGURATION_WIFI_SSID];

    if(json.containsKey(CONFIGURATION_WIFI_PASSWORD))
      wifiPassword = json[CONFIGURATION_WIFI_PASSWORD];

    if(json.containsKey(CONFIGURATION_ADMIN_PASSWORD))
      adminPassword = json[CONFIGURATION_ADMIN_PASSWORD];

    if(json.containsKey(CONFIGURATION_SERVER_NAME))
      serverName = json[CONFIGURATION_SERVER_NAME];

    return true;
  }
  else
    return false;
}

void resetConfiguration() {
  if(SPIFFS.exists(CONFIGURATION))
    SPIFFS.remove(CONFIGURATION);
}
