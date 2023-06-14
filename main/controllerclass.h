#ifndef CONTROLLERCLASS_H
#define CONTROLLERCLASS_H

#include <Arduino.h>
#include <Wire.h>
#include "motors.h"
#include "buzzer.h"

class ControllerClass {

private:
    Buzzer& player;
    Motors motor;

public:
    ControllerClass(Buzzer&);
    bool Controller();
};

#endif