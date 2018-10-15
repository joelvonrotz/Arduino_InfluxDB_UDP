# Arduino InfluxDB UDP

An Arduino-library to interact with a InfluxDB via UDP. This library currently supports the ESP8266 and if I have enough time, I will try it with the ESP32 and maybe the Arduino UNO with the WiFi shield.

The library has two classes: the first one ```InfluxDB_UDP``` requires a UDP-object which can be created using the ```WiFiUdp```-library and then passed through as a parameter to the InfluxDB-object. Additionally it needs the IP-address and the port number of the InfluxDB Host. The second class ```InfluxDB_Data``` is a simple data package with a couple of commands. Instead of stitching the data together manually, the library does it for you.

```cpp
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <influxDB_udp.h>

WiFiUDP         udp;

InfluxDB_UDP    influx(udp, "IP_ADDRESS",PORT_NUMBER);
InfluxDB_Data   influx_data("NAME_OF_MEASUREMENT");

void setup()
{
    // connect to WiFi first

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
```

## influxDB_udp

### Public

```cpp
InfluxDB_UDP( WiFiUDP &udp, String host_ip, uint16_t port )
```

Constructor for creating InfluxDB-UDP instances. Requires an object from the ```WiFiUdp``` Arduino-library, the ip-address and the port number of the Influx host.

```cpp
bool write( InfluxDB_Data data_package )
```

By passing a ```InfluxDB_Data``` object, the data gets converted and directly sent to the host.

```cpp
bool write( String data_package_line )
```

Instead of sending a data package, it is possible to send a string directly. The user just needs to format the string before sending it off to the space and time continuum.

### Private

```cpp
WiFiUDP &m_udp
```

Reference object of a WiFiUDP class. This reference is required, so the code doesn't implode when initializing one WiFi UDP object outside of the library and one inside the library.

```cpp
uint16_t m_port
```

Member-variable for the port number of the Influx host.

```cpp
String m_ip
```

Member-variable for the IP-address of the Influx host.

## influxDB_Data

### Public

```cpp
InfluxDB_Data(String measurement)
```

When creating the object, the name of the measurement is required.

```cpp
void addTag( String tag_key, String tag_value )
```

Adds a new tag. For now, if for example a float number wants to be sent, it is required to convert it to a string before passing it through.

```cpp
void addField( String field_key, String field_value )
```

Adds a new field. For now, if for example a float number wants to be sent, it is required to convert it to a string before passing it through.

```cpp
void clear( InfluxDB_ClearType clear_type )
```

Clears the set string.

- ```ALL``` - to clear tags and fields
- ```FIELD``` - to clear fields only
- ```TAG``` - to clear tags only.

```cpp
String toString()
```

Turns the data package into a influx-protocol formatted string.

### Private

```cpp
String  m_measurement
```

Contains the measurement name.

```cpp
String  m_tag
```

Contains all tags in the influxDB-protocol format

```cpp
String  m_field
```

Contains all fields in the influxDB-protocol format

## To-Do

- [ ] Add edit-function to edit tags and fields instead of constantly clearing them
- [ ] Replace Strings with Lists -> edit function could work a lot better.

## Changelog

### 15.10.2018 - First _real_ Release

- Coding Monkey added:
  - InfluxDB_UDP
  - write
  - InfluxDB_Data
  - addTag
  - addField
  - clear
  - toString
- ate cookies
