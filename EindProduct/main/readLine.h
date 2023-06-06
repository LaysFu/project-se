#include <stdint.h>
#ifndef READLINE_H
#define READLINE_H

#include <Arduino.h>
#include <Zumo32U4LineSensors.h>
#include "Zumo32U4Motors.h"
#include "colorVariables.h"

#define NUM_SENSORS 5 

class readLine {
  
private:
  Zumo32U4LineSensors lineSensors;
  uint16_t lineSensorValues[NUM_SENSORS];
  String getSideColor(int);
  String getMidColor(int);
  void calibrateLineSensors();

public:
  readLine();
  int16_t position;
  
  
  String last0color = "White";
  String last4color = "White";
  String color0;
  String color2;
  String color4;
  void identifyColor();
};

#endif
