#include <WiFiUdp.h>
#include "graphite.h"
#include "globals.h"

WiFiUDP Udp;

void sendReadingsToGraphite() {
  Udp.beginPacket(graphiteServer, graphitePort);

  Udp.write(graphiteMetric);
  Udp.write(".temperature ");
  Udp.write(temperature);
  Udp.write("\n");

  Udp.write(graphiteMetric);
  Udp.write(".pressure ");
  Udp.write(pressure);
  Udp.write("\n");

  Udp.write(graphiteMetric);
  Udp.write(".weight ");
  Udp.write(weight);

  Udp.endPacket();
}
