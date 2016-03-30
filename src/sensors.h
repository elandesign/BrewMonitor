#include "Arduino.h"
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include "globals.h"

#ifndef SENSORS_H
#define SENSORS_H

void sensorsSetup();
void sensorsRead();

#endif
