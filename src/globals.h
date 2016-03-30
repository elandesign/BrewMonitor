#ifndef GLOBALS_H
#define GLOBALS_H

#define SDA 4
#define SCL 5

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
