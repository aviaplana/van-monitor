
|-| **button_interrupt:** <br />
| |- *button_interrupt.h:* The name is self-explainatory; it is a simple library that takes care of the interruptions fired by a push button.<br />
|<br />
|-| **display:**<br />
| |- *display.h:* This is an abstraction of the "Adafruit_SSD1306". Will make things easier if I decide to change the display in the future.<br />
|<br />
|-| **tank:**<br />
| |- *tank.h:* Abstraction of the tanks libraries. Since each tank has different sensors, I use this interface to interact with both tanks the same way.<br />
|<br />
|-| **fresh_tank:**<br />
| |- *fresh_tank.h:* This tank contains the fresh water. Located inside the van.<br />
| |- *level_sensor.h:* This sensor has a floater that outputs a different resistance depending in the current position. <br />
|<br />
|-| **gray_tank:**<br />
| |- *gray_tank.h:* This tank holds the dirty water. Located outside the van.<br />
| |- *floater_switch.h:* Simple on/off switch that is triggered by a floater.<br />
|<br />
|-| **ui:**<br />
| |- *ui.h:* All the logic related with the ui can be found here. <br />
|<br />
|-| **weather:**<br />
| |- *weather_sensor.h:* Abstraction of the SHTSensor.<br />
| |- *weather.h:* Struct that holds temperature and humidity values.<br />



