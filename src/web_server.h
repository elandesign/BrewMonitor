#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#ifndef WEB_SERVER_H
#define WEB_SERVER_H

void webServerSetup();
void webServerLoop();

// Request handlers
void handleStatus();
void handleNotFound();

#endif
