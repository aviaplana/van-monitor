#include <gray_tank.h>
#include <stdlib.h>

GrayTank::GrayTank(int _num_switches, TankFloaterSwitch* _switches) {
    num_switches = _num_switches;
    switches = _switches;
}

int compare (const void * a, const void * b) {
  return (*(TankFloaterSwitch*)b).level - (*(TankFloaterSwitch*)a).level;
}

void GrayTank::begin() {
      qsort (switches, num_switches, sizeof(struct TankFloaterSwitch), compare);

      for (int count = 0; count < num_switches; count++) {
          switches[count].floater_switch.begin();
      }
}

int GrayTank::getLevel() {
  for (int count = 0; count < num_switches; count++) {
    if (switches[count].floater_switch.state() == 0) return switches[count].level;
  }

  return 0;
}

bool GrayTank::hasWarning() {
      return status == TankStatus::ALMOST_FULL || status == TankStatus::FULL;
}
