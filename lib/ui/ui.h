#ifndef UI_H
#define UI_H
#include "display.h"
#include "weather_sensor.h"


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
        void printIdle();
        void printGrayTank(int level);
        void printFreshTank(int level);
        void printWeather(weather_t indoor, weather_t outdoor); 
        void printWarnings(TankStatus fresh_status, TankStatus gray_status, bool ext_freezing, bool int_freezing);
        void nextScreen();
        void showGrayTank();
        void showFreshTank();
        void showWeather();
        void showWarnings();
        void showIdle();
        bool isShowingIdle() { return current_screen == Screen::IDLE; }
        Screen getCurrentScreen() { return current_screen; };

    private:
        Display* display;
        Screen current_screen;
        void printLevel(int level);
};

#endif
