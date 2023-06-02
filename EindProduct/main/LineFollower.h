#ifndef LineFollower_h
#define LineFollower_h

#include <Zumo32U4.h>
#include "readLine.h"
#include "gyro.h"
#include "Block.h"

class LineFollower {
private:
  Zumo32U4Motors motors;
  readLine lineread;
  Gyro gyro;
  Block block;
  const int maxSpeed = 400;
  bool onGreenLine = false;
  bool pause = false;
  int lastError = 0;

public:
  void followLine();

private:
  bool isBrownLineDetected(String sensorColors[5]);
  bool isGrayLinesDetected(String sensorColors[5]);
  bool isPitchBelowZero();
  void pauseMovement();
  void turnLeft();
  void turnRight();
  void updateOnGreenLine(String sensorColors[5]);
  int calculateLinePosition(String sensorColors[5]);
  void getColor();
  int calculateSpeedDifference(int error);
  void setMotorSpeeds(int leftSpeed, int rightSpeed);
};

#endif