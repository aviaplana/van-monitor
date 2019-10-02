#ifndef DISPLAY_H
#define DISPLAY_H
#include <Adafruit_SSD1306.h>
#include <Wire.h>

class Display: public Adafruit_SSD1306 {
    public:
        Display(int width, int height);
        void begin();
        void clear();
        void displayBuffer();
    
    private:
        Adafruit_SSD1306 display;
};

#endif