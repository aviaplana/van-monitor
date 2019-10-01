#include <Arduino.h>
#include "level_sensor.h"

LevelSensor::LevelSensor(int _pin) {
    pin = _pin;
}

void LevelSensor::begin() {

}

int LevelSensor::getLevel() {
    double read = analogRead(pin);

    return calculateExponential(read);
  }

int LevelSensor::calculateExponential(double value) {
    if (value > max_sensor_value) {
         value = max_sensor_value;
    }
  
    double a = min_sensor_value; 
    double b = 0.08497663879;

    return log10(value / a) / (b * log10(M_E)); //Exponential growth
}