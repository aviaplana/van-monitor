
|-| **button_interrupt:**
| |-*button_interrupt.h:*The name is self-explainatory; it is a simple library that takes care of the interruptions fired by a push button.
|
|-| **display:**
| |- *display.h:* This is an abstraction of the "Adafruit_SSD1306". Will make things easier if I decide to change the display in the future.
|
|-| **tank:**
| |- *tank.h:* Abstraction of the tanks libraries. Since each tank has different sensors, I use this interface to interact with both tanks the same way.
|
|-| **fresh_tank:**
| |- *fresh_tank.h:* This tank contains the fresh water. Located inside the van.
| |- *level_sensor.h:* This sensor has a floater that outputs a different resistance depending in the current position. 
|
|-| **gray_tank:**
| |- *gray_tank.h:* This tank holds the dirty water. Located outside the van.
| |- *floater_switch.h:* Simple on/off switch that is triggered by a floater.
|
|-| **ui:**
| |- *ui.h:* Takes care of 
|
|-| **weather:**
| |- *weather_sensor.h:* Abstraction of the SHTSensor.
| |- *weather.h:* Struct that holds temperature and humidity values.



