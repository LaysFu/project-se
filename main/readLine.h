#ifndef READLINE_H
#define READLINE_H

#include <stdint.h>
#include <Arduino.h>
#include <Zumo32U4Buttons.h>
#include <Zumo32U4LineSensors.h>


#define NUM_SENSORS 5 

class readLine {
  
private:
  Zumo32U4LineSensors lineSensors;
  uint16_t lineSensorValues[NUM_SENSORS];
  uint16_t lineSensorPos[NUM_SENSORS];
  
  void calibrateLineSensors();
  Zumo32U4ButtonA bA;
  Zumo32U4ButtonB bB;

public:
  readLine();
  uint16_t position;

  int doubleGrey;
  int doubleBrown;

  int rightGreyCount = 0;
  int rightBlackCount = 0;
  int leftGreyCount = 0;
  int leftBlackCount = 0;
  int brownCount = 0;
 
  String color0;
  String color2;
  String color4;
  String color8;
  void identifyColor();
};

#endif
