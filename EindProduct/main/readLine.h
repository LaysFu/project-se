#ifndef READLINE_H
#define READLINE_H

#include <Arduino.h>
#include "Zumo32U4.h"

class readLine {
private:
  int lineSensorValues;
  String sensorColors[5];

public:
  readLine(int sensorValues);
  String getColor1();
  String getColor2();
  String getColor3();
  String getColor4();
  String getColor5();
  String* getSensorColors();
  void calibrateLineSensors();
  void identifyColor();
  void lineSensorColors(int lineSensorValues);
};

#endif
