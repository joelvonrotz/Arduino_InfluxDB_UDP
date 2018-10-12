#include <influxDB_udp.h>
#include <Arduino.h>

InfluxDB_UDP::InfluxDB_UDP(WiFiUDP& udp, String host_ip, uint16_t port) :
    m_ip(host_ip),
    m_port(port),
    m_udp(udp)
{

}

bool    InfluxDB_UDP::write(InfluxDB_Data data_package)
{
    write(data_package.toString());
}

bool    InfluxDB_UDP::write(String data_package_line)
{
    m_udp.beginPacket(m_ip.c_str(), m_port);
    m_udp.print(data_package_line);
    m_udp.endPacket();
}