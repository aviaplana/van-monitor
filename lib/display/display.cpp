#include <display.h>
#include <stdlib.h>

Display::Display(int width, int height) {
    oled_display = Adafruit_SSD1306(width, height, &Wire);
}

void Display::begin() {
  oled_display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  clear();
}

void Display::printLevel(int level) {
  oled_display.drawChar(0, 54, '0', WHITE, BLACK, 1);
  oled_display.drawLine(0, 47, 0, 52, INVERSE);

  oled_display.setTextColor(WHITE);
  oled_display.setCursor(60, 54);
  oled_display.setTextSize(1);
  oled_display.print("50");
  oled_display.drawLine(64, 47, 64, 52, INVERSE);

  oled_display.setCursor(110, 54);
  oled_display.print("100");
  oled_display.drawLine(127, 47, 127, 52, INVERSE);

  int mapped_level = map(level, 0, 10, 0, 127);
  oled_display.fillRect(0, 277, mapped_level, 15, INVERSE);
}

void Display::clear() {
    oled_display.clearDisplay();
}

void Display::display() {
    oled_display.display();
}

void Display::printFreshLevel(int level) {
  oled_display.setTextSize(2);
  oled_display.setCursor(0, 0);
  oled_display.print("FRESH TANK");
  printLevel(level);
}

void Display::printGrayLevel(int level) {
  oled_display.setTextSize(2);
  oled_display.setCursor(0, 0);
  oled_display.print("GRAY TANK");
  printLevel(level);
}

void Display::printWeather(float temperature, float humidity, int x) {
  int text_x = x + ICON_SIZE + 2;

  char char_temperature[6];
  dtostrf(temperature, 2, 1, char_temperature);

  char char_humidity[6];
  //gcvt(humidity, 4, char_humidity);
  dtostrf(humidity, 2, 1, char_humidity);

  oled_display.drawXBitmap(x, 17,  icon_thermometer, ICON_SIZE, ICON_SIZE, WHITE);
  oled_display.setTextSize(2);
  oled_display.setTextColor(WHITE);
  oled_display.setCursor(text_x, 22);
  oled_display.print(char_temperature);

  oled_display.drawXBitmap(x, 42,  icon_humidity, ICON_SIZE, ICON_SIZE, WHITE);
  oled_display.setCursor(text_x, 46);
  oled_display.print(char_humidity);

  oled_display.drawLine(74, 0, 74, 64, INVERSE);

  oled_display.drawLine(0, 40, 127, 40, INVERSE);

  text_x = 78;
  oled_display.setCursor(text_x, 24);
  oled_display.print(char_temperature);

  oled_display.setCursor(text_x, 46);
  oled_display.print(char_humidity);
}

void Display::printExternalWeather(float temperature, float humidity) {
  oled_display.setTextSize(2);
  oled_display.setCursor(0, 0);
  oled_display.print("Out");

  oled_display.setCursor(76, 0);
  oled_display.print("In");
  printWeather(temperature, humidity, 0);
}

void Display::printInternalWeather(float temperature, float humidity) {
  oled_display.setTextSize(2);
  oled_display.setTextColor(WHITE);
  oled_display.setCursor(64, 0);
  oled_display.print("In");
  printWeather(temperature, humidity, 64);
}