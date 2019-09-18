#ifndef FLOATER_SWITCH_H
#define FLOATER_SWITCH_H

class FloaterSwitch {
    public:
        FloaterSwitch(int);
        bool state();
        void begin();

    private:
        int pin;
};

#endif