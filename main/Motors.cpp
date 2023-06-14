#include "Motors.h"


void Motors::motorCalculations(uint16_t pos){
  	error = pos - 1500;

    leftSpeed = maxSpeed + calculateSpeedDifference(error);
    rightSpeed = maxSpeed - calculateSpeedDifference(error);
    lastError = error;
}

void Motors::setMotorSpeeds(int i, uint16_t pos) {
    motorCalculations(pos);

    leftSpeed = constrain(leftSpeed, -200, maxSpeed);
    rightSpeed = constrain(rightSpeed, -200, maxSpeed);
    setSpeeds((leftSpeed/i), (rightSpeed/i));
}

int Motors::calculateSpeedDifference(int error) {
    return error / 2 + 3 * (error - lastError);
}

void Motors::turnLeft() {
    setSpeeds(-100, 300);
    delay(500);
}

void Motors::turnRight() {
    setSpeeds(300, -100);
    delay(500);
}


// Start handbediening methodes------------------------------------------------------------------------


void Motors::forward() {
    setSpeeds(200, 200); 
}

void Motors::backward() {
    setSpeeds(-200, -200);
}

void Motors::left() {
    setSpeeds(50, 300);
}

void Motors::right() {
    setSpeeds(300, 50);
}

void Motors::bLeft() {
    setSpeeds(-50, -300);
}

void Motors::bRight() {
    setSpeeds(-300, -50);
}

void Motors::stop() {
    setSpeeds(0, 0);
}

void Motors::playSong() {
    buzzer.playSong();
}

void Motors::stopSong() {
    buzzer.stopPlaying();
}
