#include "Arduino.h"
#include "mdns.h"
#include "globals.h"

MDNSResponder mdns;

void mdnsSetup() {
  if(!mdns.begin(serverName, WiFi.localIP())) {
    Serial.println("Error setting up MDNS responder!");
    while(1) { 
      delay(1000);
    }
  }
  Serial.println("mDNS responder started");  
}
