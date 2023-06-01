#ifndef LINE_SENSOR_COLORS_H
#define LINE_SENSOR_COLORS_H

#include <Arduino.h>
#include "Zumo32U4.h"

class LineSensorColors {
private:
  const uint16_t* lineSensorValues;
  
public:
  LineSensorColors(const uint16_t* sensorValues);
  String getColor1();
  String getColor2();
  String getColor3();
  String getColor4();
  String getColor5();
};

#endif
