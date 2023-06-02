#ifndef READLINE_H
#define READLINE_H

#include <Arduino.h>
#include "Zumo32U4.h"

class readLine {
private:
  const uint16_t* lineSensorValues;
  
public:
  LineSensorColors(const uint16_t* sensorValues);
  String getColor1();
  String getColor2();
  String getColor3();
  String getColor4();
  String getColor5();
  String color1;
  String color2;
  String color3;
  String color4;
  String color5;
  void calibrateLineSensors();
  void identifyColor();
};

#endif
