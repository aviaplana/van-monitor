#ifndef GRAY_TANK_H
#define GRAY_TANK_H
#include <tank.h>
#include <tank_floater_switch.h>

class GrayTank: public Tank {
    public: 
        GrayTank(int, TankFloaterSwitch*);
        void begin();
        int getLevel();
        bool hasWarning();
    
    private: 
        TankFloaterSwitch* switches;
        int num_switches;

};

#endif