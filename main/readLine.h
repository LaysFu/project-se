#ifndef READLINE_H
#define READLINE_H

#include <stdint.h>
#include <Arduino.h>
#include <Zumo32U4LineSensors.h>


#define NUM_SENSORS 5 
#define HISTORY 50
#define RANGE 50 
#define INTERVAL 50

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
  // calibrated colors
  int GreyL, BrownL, Black;
  int GreyR, BrownR;
  // Voor timer
  unsigned long previousMillis = 0;
  // calibrate sensors, only at start of program
  void calibrateLineSensors();
  // checks history of er een kleur is die in RANGE valt
  void inRangeCheck(int, int);


public:
  readLine();
  void identifyColor();
  uint16_t lineRider();
  void checkHistory();
  int checkGreen();
  bool checkBlack();
  void setup();
  void resetSeen();

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
