#ifndef DISPLAY_H
#define DISPLAY_H
#include <Adafruit_SSD1306.h>
#include <Wire.h>

class Display: public Adafruit_SSD1306 {
    public:
        Display(int width, int height):  Adafruit_SSD1306(width, height, &Wire) { };
        void begin();
        void clear();   
};

#endif