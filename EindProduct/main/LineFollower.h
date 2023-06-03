#ifndef LineFollower_h
#define LineFollower_h

#include <Zumo32U4.h>
#include "readLine.h"
#include "gyro.h"
#include "Block.h"

class LineFollower {
private:
  Zumo32U4Motors motors;
  readLine readline;
  Gyro gyro;
  Block block;
  const int maxSpeed = 400;
  bool onGreenLine = false;
  bool pause = false;
  int lastError = 0;
  int leftSpeed = 0;
  int rightSpeed = 0;

public:
  void followLine(readLine&);

private:
  bool isBrownLineDetected(readLine&);
  bool isGrayLinesDetected(readLine&);
  bool isPitchBelowZero();
  void pauseMovement();
  void turnLeft();
  void turnRight();
  void updateOnGreenLine(readLine&);
  int calculateLinePosition(readLine&);
  String getColor();
  int calculateSpeedDifference(int error);
  void setMotorSpeeds(int leftSpeed, int rightSpeed);
};

#endif