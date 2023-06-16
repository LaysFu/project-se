#include "Gyro.h"

void Gyro::init() {
  Wire.begin();
  imu.init();  // Initialiseer de IMU
  imu.enableDefault();
}

double Gyro::calculatePitch() {
  imu.readAcc();  // Lees de accelerometergegevens uit
  double pitch = imu.a.x * 0.01;  // berekent de pitch 
  return pitch;
}
