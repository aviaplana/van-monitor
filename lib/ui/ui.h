#ifndef UI_H
#define UI_H
#include "display.h"

enum class Screen {
    GRAY_TANK,
    FRESH_TANK,
    WEATHER,
    WARNING,
    IDLE
};

class Ui {
    public: 
        Ui(Display* _display);
        void showIdle();
        void updateFreshTank(int level);
        void updateGrayTank(int level);
        void showGrayTank(int level);
        void showFreshTank(int level);
        void showWeather(); 
        void showWarning();
        bool isShowingIdle() { return current_screen == Screen::IDLE; }
        Screen getCurrentScreen() { return current_screen; };

    private:
        Display* display;
        Screen current_screen;
        void printLevel(int level);
};

#endif
