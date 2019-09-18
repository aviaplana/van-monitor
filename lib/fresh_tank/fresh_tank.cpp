#include <fresh_tank.h>

FreshTank::FreshTank(int pin) : sensor(pin) {
    sensor = LevelSensor(pin);
}

int FreshTank::getLevel() {
    return sensor.getLevel();
}