#include <fresh_tank.h>

int FreshTank::getLevel() {
    return sensor.getLevel();
}

bool FreshTank::hasWarning() {
      return status == TankStatus::ALMOST_EMPTY || status == TankStatus::EMPTY;
}