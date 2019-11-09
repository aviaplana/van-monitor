#include "internal_weather_sensor.h"

void InternalWeatherSensor::begin() {
    dht.begin();
}

float InternalWeatherSensor::getHumidity() {
    return dht.readHumidity();
}

float InternalWeatherSensor::getTemperature() {
    return dht.readTemperature();
}
