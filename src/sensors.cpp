#include "sensors.h"
#include "display.h"

Adafruit_BMP085 bmp;
HX711 load(HX711_DATA, HX711_CLK);

void sensorsSetup() {
  Wire.begin(SDA, SCL);
  bmp.begin();
  sensorsRead();
}

void sensorsRead() {
  temperature = bmp.readTemperature();
  pressure = bmp.readPressure();
  weight = load.read_average();
}
