#include "globals.h"

bool wifiAP = true;
const char *wifiSSID = "BREWMONITOR";
const char *wifiPassword = "";
const char *serverName = "brewmonitor";
const char *adminPassword = "beerme";

int takeReadingsEvery = 60 * 5;

float temperature = -1;
int pressure = -1;
float weight = -1;
