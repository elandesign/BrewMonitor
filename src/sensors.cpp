#include "sensors.h"
#include "display.h"

Adafruit_BMP085 bmp;

void sensorsSetup() {
  Wire.begin(SDA, SCL);
  bmp.begin();
  sensorsRead();
}

void sensorsRead() {
  temperature = bmp.readTemperature();
  pressure = bmp.readPressure();
}
