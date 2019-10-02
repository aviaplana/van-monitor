#include "ui.h"

Ui::Ui(Display* _display) {
    display = _display;
}

void Ui::begin() {
    display->begin();
}

void Ui::printFreshTank(int level) {
    display->clear();
    display->setTextSize(2);
    display->setCursor(0, 0);
    display->print("FRESH TANK");
    printLevel(level);
    display->displayBuffer();
}

void Ui::printGrayTank(int level) {
    display->clear();
    display->setTextSize(2);
    display->setCursor(0, 0);
    display->print("GRAY TANK");
    printLevel(level);
    display->displayBuffer();
}

void Ui::printWeather(weather_t indoor, weather_t outdoor) {
    display->clear();
    printWeatherTemplate();

    int text_x = ICON_SIZE + 2;
    printZoneTemperature(&indoor, text_x);

    text_x = 78;
    printZoneTemperature(&outdoor, text_x);

    display->displayBuffer();
}

void Ui::printWeatherTemplate() {
    display->drawXBitmap(0, 17,  icon_thermometer, ICON_SIZE, ICON_SIZE, WHITE);
    display->drawXBitmap(0, 42,  icon_humidity, ICON_SIZE, ICON_SIZE, WHITE);

    display->drawLine(74, 0, 74, 64, INVERSE);
    display->drawLine(0, 40, 127, 40, INVERSE);
}

void Ui::printZoneTemperature(weather_t* zone, int x) {
    display->setTextSize(2);
    display->setTextColor(WHITE);

    char char_temperature[6];
    dtostrf(zone->temperature, 2, 1, char_temperature);

    char char_humidity[6];
    //gcvt(humidity, 4, char_humidity);
    dtostrf(zone->humidity, 2, 1, char_humidity);

    display->setCursor(x, 22);
    display->print(char_temperature);

    display->setCursor(x, 46);
    display->print(char_humidity);
}

void Ui::printWarnings(TankStatus fresh_status, TankStatus gray_status, bool ext_freezing, bool int_freezing) {
    display->clear();
    
    display->displayBuffer();
}

void Ui::printIdle() {
    display->clear();

    display->displayBuffer();
}

void Ui::showGrayTank() {
    current_screen = Screen::GRAY_TANK;
}

void Ui::showFreshTank() {
    current_screen = Screen::FRESH_TANK;
}

void Ui::showWeather() {
    current_screen = Screen::WEATHER;
}

void Ui::showWarnings() {
    current_screen = Screen::WARNING;
}

void Ui::showIdle() {
    current_screen = Screen::IDLE;
}

void Ui::nextScreen() {
    switch (current_screen) {
        case Screen::IDLE:
            showWeather();
            break;

        case Screen::WEATHER:
            showFreshTank();
            break;

        case Screen::FRESH_TANK:
            showGrayTank();
            break;

        case Screen::GRAY_TANK:
            showWeather();
            break;
        
        default:
            break;
    }
}

void Ui::printLevel(int level) {
  display->drawChar(0, 54, '0', WHITE, BLACK, 1);
  display->drawLine(0, 47, 0, 52, INVERSE);

  display->setTextColor(WHITE);
  display->setCursor(60, 54);
  display->setTextSize(1);
  display->print("50");
  display->drawLine(64, 47, 64, 52, INVERSE);

  display->setCursor(110, 54);
  display->print("100");
  display->drawLine(127, 47, 127, 52, INVERSE);

  int mapped_level = map(level, 0, 10, 0, 127);
  display->fillRect(0, 277, mapped_level, 15, INVERSE);
}