#include "motors.h"

void Motors::forward() {
    motors.setSpeeds(200, 200);
}

void Motors::backward() {
    motors.setSpeeds(-200, -200);
}

void Motors::leftAxis() {
    motors.setSpeeds(-200, 200);
}

void Motors::rightAxis() {
    motors.setSpeeds(200, -200);
}

void Motors::left() {
    motors.setSpeeds(50, 300);
}

void Motors::right() {
    motors.setSpeeds(300, 50);
}

void Motors::bLeft() {
    motors.setSpeeds(-300, -50);
}

void Motors::bRight() {
    motors.setSpeeds(-50, -300);
}

void Motors::stop() {
    motors.setSpeeds(0, 0);
}