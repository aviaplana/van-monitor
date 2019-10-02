#ifndef TANK_H
#define TANK_H

enum class TankStatus {
    FULL,
    OK,
    ALMOST_EMPTY,
    EMPTY
};

class Tank {
    public:
        virtual int getLevel() = 0;

        TankStatus getStatus() { return status; };

        TankStatus getCurrentStatus() {
            updateStatus();
            return getStatus();
        }

        bool hasWarning() {
            return status == TankStatus::ALMOST_EMPTY || status == TankStatus::EMPTY;
        }

        void updateStatus() {
            int level = getLevel();
            
            if (level >= 95) {
                status = TankStatus::FULL;
            } else if (level > 20) {
                status = TankStatus::OK;
            } else if (level > 5) {
                status = TankStatus::ALMOST_EMPTY;
            } else {
                status = TankStatus::EMPTY;
            }
        }

    private:
        TankStatus status;
};

#endif