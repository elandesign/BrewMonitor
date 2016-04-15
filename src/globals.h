#ifndef GLOBALS_H
#define GLOBALS_H

#define SDA 12
#define SCL 14

#define HX711_DATA 13
#define HX711_CLK 2

extern bool wifiAP;
extern const char *wifiSSID;
extern const char *wifiPassword;
extern const char *adminPassword;
extern const char *serverName;

extern int takeReadingsEvery;

extern float temperature;
extern int pressure;
extern float weight;

#endif
