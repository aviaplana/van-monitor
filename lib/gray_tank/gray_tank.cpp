#include <gray_tank.h>
#include <stdlib.h>

GrayTank::GrayTank(int _num_switches, TankFloaterSwitch* _switches) {
    num_switches = _num_switches;
    switches = _switches;
}

int compare (const void * a, const void * b) {
  return ( (*(TankFloaterSwitch*)a).level - (*(TankFloaterSwitch*)b).level );
}

void GrayTank::begin() {
      qsort (switches, num_switches, sizeof(int), compare);

      for (int count = 0; count < num_switches; count++) {
          switches[count].floater_switch.begin();
      }
}

int GrayTank::getLevel() {
  return 100;
}
