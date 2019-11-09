#include "external_weather_sensor.h"

void ExternalWeatherSensor::begin() {
    Wire.begin();
    sensor = SHTSensor();
    sensor.init();
    sensor.setAccuracy(SHTSensor::SHT_ACCURACY_MEDIUM);
}

float ExternalWeatherSensor::getHumidity() {
    return sensor.getHumidity();
}

float ExternalWeatherSensor::getTemperature() {
    return sensor.getTemperature();
}
