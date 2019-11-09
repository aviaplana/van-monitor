#include "display.h"

void Display::begin() {
    Adafruit_SSD1306::begin(SSD1306_SWITCHCAPVCC, 0x3C);
    clearDisplay();
    display();
}

void Display::clear() {
    clearDisplay();
}