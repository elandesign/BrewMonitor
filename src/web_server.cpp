#include "Arduino.h"
#include "web_server.h"

ESP8266WebServer webServer(80);

void webServerSetup() {
  // simple HTTP server to see that DNS server is working
  webServer.onNotFound([]() {
    String message = "Hello World!\n\n";
    message += "URI: ";
    message += webServer.uri();

    webServer.send(200, "text/plain", message);
  });
  webServer.begin();
}

void webServerLoop() {
  webServer.handleClient();
}
