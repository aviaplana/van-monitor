#include "ui.h"

Ui::Ui(Display* _display) {
    display = _display;
}

void Ui::printFreshTank(int level) {
    display.clear();
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print("FRESH TANK");
    printLevel(level);
    display.display();
}

void Ui::printGrayTank(int level) {
    display.clear();
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print("GRAY TANK");
    printLevel(level);
    display.display();
}

void Ui::printWeather(weather_t indoor, weather_t outdoor) {
    display.clear();
    int text_x = x + ICON_SIZE + 2;

  char char_temperature[6];
  dtostrf(indoor.temperature, 2, 1, char_temperature);

  char char_humidity[6];
  //gcvt(humidity, 4, char_humidity);
  dtostrf(indoor.humidity, 2, 1, char_humidity);

  oled_display.drawXBitmap(x, 17,  icon_thermometer, ICON_SIZE, ICON_SIZE, WHITE);
  oled_display.drawXBitmap(x, 42,  icon_humidity, ICON_SIZE, ICON_SIZE, WHITE);

  oled_display.drawLine(74, 0, 74, 64, INVERSE);
  oled_display.drawLine(0, 40, 127, 40, INVERSE);

  oled_display.setTextSize(2);
  oled_display.setTextColor(WHITE);

  oled_display.setCursor(text_x, 22);
  oled_display.print(char_temperature);

  oled_display.setCursor(text_x, 46);
  oled_display.print(char_humidity);

  text_x = 78;

  dtostrf(indoor.humidity, 2, 1, char_humidity);
  dtostrf(indoor.temperature, 2, 1, char_temperature);

  oled_display.setCursor(text_x, 24);
  oled_display.print(char_temperature);

  oled_display.setCursor(text_x, 46);
  oled_display.print(char_humidity);
    display.display();
}

void Ui::printWarnings(TankStatus fresh_status, TankStatus gray_status, bool ext_freezing, bool int_freezing) {
    display.clear();
    
    display.display();
}

void Ui::printIdle() {
    display.clear();

    display.display();
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
  display.drawChar(0, 54, '0', WHITE, BLACK, 1);
  display.drawLine(0, 47, 0, 52, INVERSE);

  display.setTextColor(WHITE);
  display.setCursor(60, 54);
  display.setTextSize(1);
  display.print("50");
  display.drawLine(64, 47, 64, 52, INVERSE);

  display.setCursor(110, 54);
  display.print("100");
  display.drawLine(127, 47, 127, 52, INVERSE);

  int mapped_level = map(level, 0, 10, 0, 127);
  display.fillRect(0, 277, mapped_level, 15, INVERSE);
}