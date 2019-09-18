#include <Arduino.h>
#include <gray_tank.h>
#include <fresh_tank.h>
#include <display.h>

#define PIN_FRESH_LEVEL A0
#define PIN_FLOAT_SWITCH_1 2
#define PIN_FLOAT_SWITCH_2 3
#define PIN_FLOAT_SWITCH_3 4
#define PIN_FLOAT_SWITCH_4 5

TankFloaterSwitch listSwitches[] {
  { FloaterSwitch(PIN_FLOAT_SWITCH_1), 25 }, 
  { FloaterSwitch(PIN_FLOAT_SWITCH_2), 50 }, 
  { FloaterSwitch(PIN_FLOAT_SWITCH_3), 75 }, 
  { FloaterSwitch(PIN_FLOAT_SWITCH_4), 100 }
};

GrayTank gray_tank = GrayTank(4, listSwitches);
FreshTank fresh_tank = FreshTank(PIN_FRESH_LEVEL);

Display display = Display(128, 64);

void setup() {
  Serial.begin(9600);

  gray_tank.begin();
  display.begin();
}

void loop() {
  int fresh_level = fresh_tank.getLevel();

  display.clear();
  //display.printFreshLevel(fresh_level);
  display.printExternalWeather(32.2, 83.0);
  display.display();

  delay(100);
}

