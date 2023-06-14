#ifndef LineFollower_h
#define LineFollower_h

#include "readLine.h"
#include "gyro.h"

class LineFollower {
  private:
    readLine& rl;
    Gyro gyro;

    uint16_t position;

  public:
    LineFollower(readLine&);
    void followLine();
    void checkGrey();   
};

#endif