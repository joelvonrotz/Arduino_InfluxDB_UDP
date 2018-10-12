#include <Arduino.h>
#include <influxDB_data.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>


class InfluxDB_UDP
{
  public:
    InfluxDB_UDP(WiFiUDP &udp, String host_ip, uint16_t port);

    bool    write(InfluxDB_Data data_package);
    bool    write(String data_package_line);

  private:
    WiFiUDP     &m_udp;
    uint16_t    m_port;
    String      m_ip = "";
};
