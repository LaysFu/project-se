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
  uint16_t lineSensorPos[NUM_SENSORS];
  String getSideColor(int);
  String getMidColor(int);
  void calibrateLineSensors();

public:
  readLine();
  int16_t position;

  int rightGreyCount = 0;
  int rightBlackCount = 0;
  int leftGreyCount = 0;
  int leftBlackCount = 0;
  String last0color = "White";
  String last4color = "White";
  int count0 = 0;
  int count4 = 0;
  String color0;
  String color2;
  String color4;
  String color8;
  void identifyColor();
};

#endif
