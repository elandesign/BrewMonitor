#include "Arduino.h"
#include "config.h"
#include "button.h"
#include "display.h"

void configSetup() {
  if(buttonPressed()) {
    delay(2000); // Ideally we should monitor for pin changes, but this will do for now
    if(buttonPressed()) {
      configReset();
    }
  }
  
  configLoad();
}

bool configLoad() {
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
    if(json.containsKey(CONFIGURATION_WIFI_AP))
      wifiAP = json[CONFIGURATION_WIFI_AP];

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

void configReset() {
  if(SPIFFS.exists(CONFIGURATION))
    SPIFFS.remove(CONFIGURATION);
}
