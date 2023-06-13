#ifndef MOTORS_H
#define MOTORS_H

#include <Zumo32U4Motors.h>

class Motors : public Zumo32U4Motors {
    private: 
        int error, lastError = 0;
        int leftSpeed, rightSpeed;

        int calculateSpeedDifference(int);
        void motorCalculations();

    public:
        void setMotorSpeeds();
        void turnLeft();
        void turnRight();
}

#endif // MOTORS_H