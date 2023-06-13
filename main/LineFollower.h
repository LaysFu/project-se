#ifndef LineFollower_h
#define LineFollower_h

#include <Zumo32U4Motors.h>
#include "readLine.h"
#include <Zumo32U4Buttons.h>
//#include "gyro.h"

class LineFollower {
 private:
  bool gameOn; //start followLine loop
  Zumo32U4Motors motors;
  readLine rl;
  //Gyro gyro;
  const int maxSpeed = 200;
  bool onGreenLine = false;
  bool pause = false;
  int lastError = 0;
  int leftSpeed = 0;
  int rightSpeed = 0;
  int count = 0;
  Zumo32U4ButtonA bA;
  Zumo32U4ButtonB bB;

   // bool isBrownLineDetected(readLine&);
   // bool isGrayLinesDetected(readLine&);
   //bool isPitchBelowZero();
  void pauseMovement();
  void turnLeft();
  void turnRight();
  void updateOnGreenLine();
  int calculateLinePosition();
  String getColor();
  int calculateSpeedDifference(int);
  void setMotorSpeeds(int, int);

 public:
   LineFollower();
   void followLine();
};

#endif