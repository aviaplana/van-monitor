#include <button_interrupt.h>
#include <Arduino.h>


ButtonInterrupt::ButtonInterrupt(int _pin) {
    pin = _pin;
}

int ButtonInterrupt::getPin() {
    return pin;
}

void ButtonInterrupt::begin() {
    pinMode(pin, INPUT_PULLUP);
}   

void ButtonInterrupt::interruptionRoutine() {
    if (millis() > 1000 && millis() - last_interruption >= interruption_interval) {
        last_interruption = millis();
        interruption_flag = true;
    }
}

void ButtonInterrupt::clearInterruption() {
    interruption_flag = false;
}

bool ButtonInterrupt::hasInterruption() {
    return interruption_flag;
}