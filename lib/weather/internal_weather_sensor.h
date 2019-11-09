#ifndef INTERNAL_WEATHER_SENSOR_H
#define INTERNAL_WEATHER_SENSOR_H

#include <DHT.h>
#include <DHT_U.h>

#include "weather_sensor.h"

class InternalWeatherSensor: public WeatherSensor {
    public:
        InternalWeatherSensor(int _pin): dht(_pin, DHT22) { };
        void begin();
        float getTemperature();
        float getHumidity();

    private:
        DHT dht;  
};

#endif