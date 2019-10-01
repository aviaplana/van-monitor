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
        const float max_sensor_value = 830.0;
        const float min_sensor_value = 330.0;
};

#endif