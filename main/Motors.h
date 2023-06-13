#ifndef MOTORS_H
#define MOTORS_H

#include <Zumo32U4Motors.h>

class Motors : public Zumo32U4Motors {
    private: 
        int error, lastError = 0;
        int leftSpeed, rightSpeed;
        const int maxSpeed = 350;

        int calculateSpeedDifference(int);
        void motorCalculations();

    public:
        Motors();
        ~Motors() = default;

        void setMotorSpeeds(int);
        void turnLeft();
        void turnRight();
}

#endif // MOTORS_H