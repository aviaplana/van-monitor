#include <weather_sensor.h>

void WeatherSensor::begin() {
    sensor = SHTSensor();
    sensor.setAccuracy(SHTSensor::SHT_ACCURACY_MEDIUM);
}

float WeatherSensor::getHumidity() {
    return 66.4;
    //return sensor.getHumidity();
}

float WeatherSensor::getTemperature() {
    return 30.4;
    //return sensor.getTemperature();
}

bool WeatherSensor::isFreezing() {
    return getTemperatire() <= 0;
}

weather_t WeatherSensor::getWeather() {
    float temperature = getTemperature();
    float humidity = getHumidity();

    return weather_t{temperature, humidity}
}
