#include <stdint.h>
#ifndef READLINE_H
#define READLINE_H

#include <Arduino.h>
#include <Zumo32U4LineSensors.h>
#include "Zumo32U4Motors.h"
#include "colorVariables.h"
#include <Zumo32U4Buttons.h>

#define NUM_SENSORS 5 

class readLine {
  
private:
  Zumo32U4LineSensors lineSensors;
  Zumo32U4ButtonB bB;
  
  uint16_t lineSensorPos[NUM_SENSORS];
  String getSideColor(int);
  String getMidColor(int);
  void calibrateLineSensors();

public:
  readLine();
  int16_t position;
  uint16_t lineSensorValues[NUM_SENSORS];
  int rightGreyCount = 0;
  int rightBlackCount = 0;
  int leftGreyCount = 0;
  int leftBlackCount = 0;
  int brownCount = 0;
  int whiteCount =0;
  int greyCount = 0;
  void setup();
  int count0 = 0;
  int count4 = 0;
  String color0;
  String color2;
  String color4;
  String color8;
  String color9;
  void identifyColor();
  int Grey;
  int Brown;
};

#endif
