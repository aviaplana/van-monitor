#ifndef EXTERNAL_WEATHER_SENSOR_H
#define EXTERNAL_WEATHER_SENSOR_H

#include "Wire.h"
#include "SHTSensor.h"
#include "weather_sensor.h"

class ExternalWeatherSensor: public WeatherSensor {
    public:
        void begin();
        float getTemperature();
        float getHumidity();

    private:
        SHTSensor sensor;
};

#endif