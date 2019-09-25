#include "ui.h"

Ui::Ui(Display* _display) {
    display = _display;
}

void Ui::showFreshTank(int level) {
    display.clear();
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