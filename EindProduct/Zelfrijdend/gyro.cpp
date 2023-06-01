#include "Gyro.h"

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