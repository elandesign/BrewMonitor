#include "wifi.h"
#include "display.h"

const char *wifiSSID = "";
const char *wifiPassword = "";

/*
 * Connect to the wifi network as specified in the settings
 */
void wifiSetup() {
  setStatus("Connecting to WiFi");

  WiFi.begin(wifiSSID, wifiPassword);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  setStatus("Connected");
  delay(500);
}

/*
 * Put the ESP8266 into AP mode to allow the user to configure settings
 * for connecting to their home network
 */
void wifiSetupAP() {
  IPAddress apIP(192, 168, 1, 1);

  setStatus("Setting up access point");
  
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(AP_SSID);
}
