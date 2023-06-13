#ifndef CONTROLLERCLASS_H
#define CONTROLLERCLASS_H

#include <Arduino.h>
#include <Zumo32U4.h>
#include <Wire.h>
#include "motors.h"
#include "buzzer.h"

class ControllerClass {

private:

    Motors motor;
    Buzzer player;

public:

    void Controller();
};

#endif