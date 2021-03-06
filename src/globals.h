#include <IPAddress.h>

#ifndef GLOBALS_H
#define GLOBALS_H

#define SDA 12
#define SCL 14
#define HX711_DATA 2
#define HX711_CLK 13
#define BUTTON 18

extern bool wifiAP;
extern const char *wifiSSID;
extern const char *wifiPassword;
extern const char *adminPassword;
extern const char *serverName;

extern int takeReadingsEvery;

extern bool buttonPressed;

extern IPAddress graphiteServer;
extern int graphitePort;
extern const char *graphiteMetric;

extern float temperature;
extern int pressure;
extern float weight;

#endif
