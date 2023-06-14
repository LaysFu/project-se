#ifndef GYRO_H
#define GYRO_H

#include <Wire.h>
#include <Zumo32U4IMU.h>

class Gyro {
  private:
    Zumo32U4IMU imu;
    double pitch;
    
  public:
    Gyro();
    void init();
    double calculatePitch();
    bool isPitchBelowZero();
  
};

#endif