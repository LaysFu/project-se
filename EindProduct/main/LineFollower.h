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
  bool pauseMovement = false;
  int lastError = 0;

public:
  void followLine();

private:
  bool isBrownLineDetected(Color lineSensorValues[5]);
  bool isGrayLinesDetected(Color lineSensorValues[5]);
  bool isPitchBelowZero();
  void pauseMovement();
  void turnLeft();
  void turnRight();
  void updateOnGreenLine(Color lineSensorValues[5]);
  int calculateLinePosition(Color lineSensorValues[5]);
  void getColor();
  int calculateSpeedDifference(int error);
  void setMotorSpeeds(int leftSpeed, int rightSpeed);
};

#endif