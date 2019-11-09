#include <Arduino.h>
#include <floater_switch.h>

FloaterSwitch::FloaterSwitch(int _pin) {
        pin = _pin;
}

void FloaterSwitch::begin() {
    pinMode(pin, INPUT_PULLUP);
}

bool FloaterSwitch::state() {
    return digitalRead(pin);
}