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
    if (value > 830) {
         value = 830.0;
    }
  
    double a = 330.0;   //Sensor value in position = 0
    double b = 0.08497663879;

    return log10(value / a) / (b * log10(M_E)); //Exponential growth
}