#ifndef WEATHER_SENSOR_H
#define WEATHER_SENSOR_H
#include "Wire.h"
#include "SHTSensor.h"
#include "weather.h"

class WeatherSensor {
    public:
        void begin();
        float getTemperature();
        float getHumidity();
        weather_t getWeather();
        bool isFreezing();

    private:
        SHTSensor sensor;
};

#endif