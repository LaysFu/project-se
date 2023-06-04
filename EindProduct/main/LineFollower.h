#ifndef LineFollower_h
#define LineFollower_h

#include <Zumo32U4Motors.h>
#include "readLine.h"
#include "gyro.h"

class LineFollower {
private:
  bool gameOn; //start followLine loop
  Zumo32U4Motors motors;
  readLine rl;
  Gyro gyro;
  const int maxSpeed = 400;
  bool onGreenLine = false;
  bool pause = false;
  int lastError = 0;
  int leftSpeed = 0;
  int rightSpeed = 0;

  // bool isBrownLineDetected(readLine&);
  // bool isGrayLinesDetected(readLine&);
  bool isPitchBelowZero();
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