#ifndef READLINE_H
#define READLINE_H

#include <stdint.h>
#include <Arduino.h>
#include <Zumo32U4LineSensors.h>


#define NUM_SENSORS 5 
#define HISTORY 50
#define RANGE 25 
#define INTERVAL 1000

class readLine {
  
private:
  Zumo32U4LineSensors lineSensors;
  
  // arrays for color
  uint16_t lineSensorValues[NUM_SENSORS];
  // arrays for position
  uint16_t lineSensorPos[NUM_SENSORS];
  // geschiedenis array voor kleuren (dit is een test)
  int leftAR[HISTORY], rightAR[HISTORY];
  // index voor array
  int index;
  // Green voor speedlimit. 1 = not Green, 2 = Green
  int Green;
  // calibrated colors
  int Grey, Brown, Black;
  // Voor timer
  unsigned long previousMillis = 0;
  // calibrate sensors, only at start of program
  void calibrateLineSensors();
  // checks history of er een kleur is die in RANGE valt
  void inRangeCheck(int, int);


public:
  readLine();
  void identifyColor();
  void lineRider();
  void checkHistory();
  int checkGreen();
  void setup();

  // seen colors
  bool GreySeen[2];
  bool BrownSeen[2];
  bool BlackSeen[2];

  // int doubleGrey, doubleBrown;
  // int rightGreyCount = 0;
  // int rightBlackCount = 0;
  // int leftGreyCount = 0;
  // int leftBlackCount = 0;
  // int brownCount = 0;
 
  // String color0 = "", color1 = "", color2 = "", color3 = "";


};

#endif
