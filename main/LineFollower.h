#ifndef LineFollower_h
#define LineFollower_h

#include "Motors.h"
#include "readLine.h"
#include "gyro.h"

class LineFollower {
  private:
    Motors motor;
    readLine& rl;
    Gyro gyro;

    const int maxSpeed = 200;

    bool isPitchBelowZero();
    

  public:
    LineFollower(readLine&);
    void followLine();
    void setMotorSpeeds();
    void lineRider();
};

#endif