#ifndef LEVEL_SENSOR_H
#define LEVEL_SENSOR_H

class LevelSensor {
    public:
        LevelSensor(int);
        void begin();
        int getLevel();

    private:
        int pin;
        int calculateExponential(double);
};

#endif