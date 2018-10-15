#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <influxDB_udp.h>

WiFiUDP         udp;

InfluxDB_UDP    influx(udp, "IP_ADDRESS",1234);
InfluxDB_Data   data("test");

float   randomNr;

const char* ssid     = "SSID";
const char* password = "PASSWORD";



void setup()
{
    Serial.begin(115200);
    // * Connecting to specified WiFi
    WiFi.begin(ssid, password);

    //WiFi.getNetworkInfo();
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("Wifi Connected to " + String(ssid));
    // * WiFi connection FIN

    data.addTag("location","china");
    data.addTag("room","hongkong");
    data.addField("data",String(1));

}

void loop()
{
    delay(1000);
    data.clear(InfluxDB_Data::FIELD);
    data.addField("data",String(random(10)));
    influx.write(data);
}