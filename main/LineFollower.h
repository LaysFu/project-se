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

    uint16_t position;
    bool isPitchBelowZero();

  public:
    LineFollower(readLine&);
    void followLine();   
};

#endif