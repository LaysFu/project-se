#include "Motors.h"

void Motors::motorCalculations(){
  	error = rl.position - 2000;

    leftSpeed = maxSpeed + calculateSpeedDifference(error);
    rightSpeed = maxSpeed - calculateSpeedDifference(error);
    lastError = error;
}

void Motors::setMotorSpeeds() {
    motorCalculations();

    leftSpeed = constrain(leftSpeed, 0, maxSpeed);
    rightSpeed = constrain(rightSpeed, 0, maxSpeed);
    motors.setSpeeds(leftSpeed, rightSpeed);
}

void Motors::calculateSpeedDifference(int error) {
    return error / 4 + 6 * (error - lastError);
}
