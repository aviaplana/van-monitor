#ifndef TANK_H
#define TANK_H

class Tank {
    public:
        virtual int getLevel() = 0;
        bool isFull() {
            return getLevel() == 100;
        };
};

#endif