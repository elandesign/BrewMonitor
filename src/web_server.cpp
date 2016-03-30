#include "Arduino.h"
#include "web_server.h"
#include <ArduinoJson.h>
#include "globals.h"

ESP8266WebServer webServer(80);

void webServerSetup() {
  webServer.on("/status.json", handleStatus);
  webServer.onNotFound(handleNotFound);

  webServer.begin();
}

void webServerLoop() {
  webServer.handleClient();
}

void handleStatus() {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  String output;
  
  root["temperature"] = temperature;
  root["pressure"] = pressure;
  root["weight"] = weight;

  root.printTo(output);

  webServer.send(200, "application/json", output);
}

void handleNotFound() {
  webServer.send(404, "text/plain", "");
}
