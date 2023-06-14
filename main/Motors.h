#ifndef MOTORS_H
#define MOTORS_H

#include <Zumo32U4Motors.h>
#include "buzzer.h"

class Motors : public Zumo32U4Motors {
    private: 
        Buzzer buzzer;
        int error, lastError = 0;
        int leftSpeed, rightSpeed;
        const int maxSpeed = 350;

        // Voor PID controller
        int calculateSpeedDifference(int);
        void motorCalculations();

    public:
        Motors();
        ~Motors() = default;

        // PID controller
        void setMotorSpeeds(int);
        // Grey bochten
        void turnLeft();
        void turnRight();

        // Handbediening
        void forward() 
        void backward()
        void left() 
        void right() 
        void bLeft() 
        void bRight() 
        void stop() 
        void playSong() 
        void stopSong() 
}

#endif // MOTORS_Hclass ZumoMotors {



