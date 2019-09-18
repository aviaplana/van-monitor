#ifndef WEATHER_SENSOR_H
#define WEATHER_SENSOR_H
#include "Wire.h"
#include "SHTSensor.h"

class WeatherSensor {
    public:
        void begin();
        float getTemperature();
        float getHumidity();

    private:
        SHTSensor sensor;
};

#endif