#include <Arduino.h>

class InfluxDB_Data {
  public:
    InfluxDB_Data(String measurement) : m_measurement(measurement) {}

    void addTag(String tag_key, String tag_value)
    {
        m_tag += ",";        
        m_tag += tag_key + "=" + tag_value; 
    }

    void addField(String field_key, String field_value)
    {
        if(m_field == "")
        {
            m_field = " ";
        }
        else
        {
            m_field += ",";
        }
        
        m_field += field_key + "=" + field_value; 
    }

    void addField(String field_key, float field_value)
    {
        addField(field_key, String(field_value));
    }

    void clearField()
    {
        
        m_field       = "";
    }

    String  toString()
    {
        return String(m_measurement + m_tag + m_field);
    }

  private:
    String  m_measurement = "";
    String  m_tag = "";
    String  m_field = "";
};
