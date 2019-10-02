#include "display.h"

Display::Display(int width, int height) {
    display = Adafruit_SSD1306(width, height, &Wire);
}

void Display::begin() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
}

void Display::clear() {
    display.clearDisplay();
}

void Display::displayBuffer() {
    display.display();
}