#ifndef FRESH_TANK_H
#define FRESH_TANK_H
#include "level_sensor.h"
#include "tank.h"

class FreshTank: public Tank {
    public:
        FreshTank(int _pin): sensor(_pin) {};
        int getLevel();

    private:
        LevelSensor sensor;
};

#endif