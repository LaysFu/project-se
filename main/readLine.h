#ifndef READLINE_H
#define READLINE_H

#include <stdint.h>
#include <Arduino.h>
#include <Zumo32U4Buttons.h>
#include <Zumo32U4LineSensors.h>


#define NUM_SENSORS 5 

class readLine {
  
private:
  Zumo32U4ButtonA bA;
  Zumo32U4ButtonB bB;
  Zumo32U4LineSensors lineSensors;

  // arrays for color
  uint16_t lineSensorValues[NUM_SENSORS];
  // arrays for position
  uint16_t lineSensorPos[NUM_SENSORS];

  // calibrate sensors, only at start of program
  void calibrateLineSensors();

public:
  readLine();

  int Grey;
  int Brown;
  int Black;

  int doubleGrey, doubleBrown;
  int rightGreyCount = 0;
  int rightBlackCount = 0;
  int leftGreyCount = 0;
  int leftBlackCount = 0;
  int brownCount = 0;
 
  String color0 = "", color2 = "", color4 = "", color8 = "";
  void identifyColor();
  void lineRider();
};

#endif
