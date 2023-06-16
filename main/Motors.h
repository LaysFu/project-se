#ifndef MOTORS_H
#define MOTORS_H

#include <Zumo32U4Motors.h>
#include "buzzer.h"

class Motors : public Zumo32U4Motors {
    private: 
        //Private attributen
        Buzzer buzzer;
        int error, lastError = 0;
        int leftSpeed, rightSpeed;
        const int maxSpeed = 350;

        //Declaraties voor PID controller
        int calculateSpeedDifference(int);
        void motorCalculations(uint16_t);

    public:
        ~Motors() = default;

        //PID controller
        void setMotorSpeeds(int, uint16_t);
        //Declaratie voor de bochten met grijs.
        void turnLeft();
        void turnRight();

        //Declaratie van de handbediening
        void forward();
        void backward();
        void left(); 
        void right(); 
        void bLeft(); 
        void bRight(); 
        void stop(); 
        void playSong(); 
        void stopSong(); 
};

#endif // MOTORS_Hclass ZumoMotors {



