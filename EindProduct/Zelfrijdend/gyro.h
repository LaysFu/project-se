#ifndef GYRO_H
#define GYRO_H

#include <Wire.h>
#include <Zumo32U4IMU.h>

class Gyro {
public:
  void init();
  double calculatePitch();
private:
  Zumo32U4IMU imu;
};

#endif