#include <Arduino.h>
#include "display.h"
#include <gray_tank.h>
#include <fresh_tank.h>
#include <ui.h>
#include <internal_weather_sensor.h>
#include <external_weather_sensor.h>
#include <button_interrupt.h>

#define REFRESH_RATE 300
#define TIME_TO_IDLE 15000

#define PIN_FRESH_LEVEL A0
#define PIN_BUTTON_SELECT 2
#define PIN_FLOAT_SWITCH_1 4
#define PIN_FLOAT_SWITCH_2 5
#define PIN_FLOAT_SWITCH_3 6
#define PIN_FLOAT_SWITCH_4 7
#define PIN_INTERNAL_WEATHER_SENSOR 8
#define PIN_LED 10

TankFloaterSwitch listSwitches[] {
  { FloaterSwitch(PIN_FLOAT_SWITCH_1), 25 }, 
  { FloaterSwitch(PIN_FLOAT_SWITCH_2), 50 }, 
  { FloaterSwitch(PIN_FLOAT_SWITCH_3), 75 }, 
  { FloaterSwitch(PIN_FLOAT_SWITCH_4), 100 }
};

InternalWeatherSensor internal_weather(PIN_INTERNAL_WEATHER_SENSOR);
ExternalWeatherSensor external_weather;
GrayTank gray_tank = GrayTank(4, listSwitches);
FreshTank fresh_tank {PIN_FRESH_LEVEL};
ButtonInterrupt button_select {PIN_BUTTON_SELECT};
Display display{128, 64};
Ui ui { display };

unsigned long last_refresh = 0;

void interruptionRoutineSelect() {
  button_select.interruptionRoutine();
}

void initializeInterruptions() {
  button_select.begin();
  attachInterrupt(digitalPinToInterrupt(button_select.getPin()), interruptionRoutineSelect, FALLING);
}

void initializeLed() {
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
}

void setup() {
  Serial.begin(9600);
  
  initializeInterruptions();
  initializeLed();
  internal_weather.begin();
  external_weather.begin();
  ui.begin();
  gray_tank.begin();
}

void printGrayTank() {
  int level = gray_tank.getLevel();
  ui.printGrayTank(level);
}

void printFreshTank() {
  int level = fresh_tank.getLevel();
  ui.printFreshTank(level);
}

bool hasWarnings() {
  gray_tank.updateStatus();
  fresh_tank.updateStatus();
  bool ext_freezing = external_weather.isFreezing();
  bool int_freezing = internal_weather.isFreezing();

  return gray_tank.hasWarning() || fresh_tank.hasWarning() || ext_freezing || int_freezing;
}

void printWarnings() {
  TankStatus gray_status = gray_tank.getCurrentStatus();
  TankStatus fresh_status = fresh_tank.getCurrentStatus();
  bool ext_freezing = external_weather.isFreezing();
  bool int_freezing = internal_weather.isFreezing();

  ui.printWarnings(gray_status, fresh_status, int_freezing, ext_freezing);
}

void printWeather() {
  weather_t int_weather = internal_weather.getWeather();
  weather_t ext_weather = external_weather.getWeather();

  ui.printWeather(int_weather, ext_weather);
}

void refreshCurrentScreen() {
  switch (ui.getCurrentScreen()) {
      case Screen::FRESH_TANK:
        printFreshTank();
      break;

      case Screen::GRAY_TANK:
        printGrayTank();    
      break;

      case Screen::WARNING:
      Serial.println("Warning");
        if (hasWarnings()) {
          Serial.println("has Warnings");
          printWarnings();
        } else {
          Serial.println("no Warnings");
          ui.showIdle();
        }
      break;

      case Screen::WEATHER:
        printWeather();
      break;

      case Screen::IDLE:
        ui.printIdle();
      break;
    }
}

void refreshCurrentScreenIfNeeded() {
  if (millis() - last_refresh > REFRESH_RATE) {
    last_refresh = millis();
    refreshCurrentScreen();
  }
}

void changeScreenIfButtonPressed() {
  if (button_select.hasInterruption()) {
    button_select.clearInterruption();
    ui.nextScreen();
  }
}

void showIdleIfNoInteraction() {
  if ((millis() - button_select.getLastInterruption()) > TIME_TO_IDLE) {
    ui.showIdle();
  }
}

void turnOnLedIfFreshTankFull() {
  TankStatus fresh_status = fresh_tank.getCurrentStatus();
  int led_status = (fresh_status == TankStatus::FULL) ? HIGH : LOW;
  
  digitalWrite(PIN_LED, led_status);
}

void loop() {
  changeScreenIfButtonPressed();
  refreshCurrentScreenIfNeeded();
  showIdleIfNoInteraction();
  turnOnLedIfFreshTankFull();
}
