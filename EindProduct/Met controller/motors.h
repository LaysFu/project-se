#include <Zumo32U4.h>
#include <Arduino.h>

#ifndef MOTORS_H
#define MOTORS_H

class Motors {

public:
    void forward();
    void backward();
    void left();
    void right();
    void bLeft();
    void bRight();
    void stop();

private:
    Zumo32U4Motors motors;
};