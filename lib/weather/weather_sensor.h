#ifndef WEATHER_SENSOR_H
#define WEATHER_SENSOR_H
#include "weather.h"

class WeatherSensor {
    public:
        virtual void begin() = 0;
        virtual float getTemperature() = 0;
        virtual float getHumidity() = 0;
        
        bool isFreezing() {
            return getTemperature() <= 0;
        }

        weather_t getWeather() {
            float temperature = getTemperature();
            float humidity = getHumidity();

            return weather_t{temperature, humidity};
        }
};

#endif