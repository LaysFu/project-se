#include "Gyro.h"

Gyro::Gyro(){}

void Gyro::init() {
  Wire.begin();
  imu.init();
  imu.enableDefault();
}

double Gyro::calculatePitch() {
  imu.readAcc();
  double pitch = imu.a.x * 0.01;
  return pitch;
}

bool Gyro::isPitchBelowZero() {
  pitch = gyro.calculatePitch();
  return (pitch < 0);
}