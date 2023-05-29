#ifndef LineFollower_h
#define LineFollower_h

#include <Zumo32U4.h>
#include "ReadLine.h"
#include "Gyro.h"
#include "Block.h"

class LineFollower {
private:
  Zumo32U4Motors motors;
  ReadLine readline;
  Gyro gyro;
  Block block;
  const int maxSpeed = 400;
  bool onGreenLine = false;
  bool pauseMovement = false;
  int lastError = 0;

public:
  void followLine();

private:
  bool isBrownLineDetected(Color lineSensorValues[3]);
  bool isGrayLinesDetected(Color lineSensorValues[3]);
  bool isPitchBelowZero();
  void pauseMovement();
  void turnLeft();
  void turnRight();
  void updateOnGreenLine(Color lineSensorValues[3]);
  int calculateLinePosition(Color lineSensorValues[3]);
  Color getColor();
  int calculateSpeedDifference(int error);
  void setMotorSpeeds(int leftSpeed, int rightSpeed);
};

#endif