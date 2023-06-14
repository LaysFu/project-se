#ifndef LineFollower_h
#define LineFollower_h

#include "readLine.h"
#include "gyro.h"
#include "Motors.h"

class LineFollower {
  private:
    readLine& rl;
    Motors motors;
    Gyro gyro;

    uint16_t position;
    unsigned long previousMillis =0;

  public:
    LineFollower(readLine&);
    bool followLine();
    void checkGrey();   
};

#endif