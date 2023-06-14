#include "Motors.h"

Motors::Motors(){}

void Motors::motorCalculations(){
  	error = rl.position - 1500;

    leftSpeed = maxSpeed + calculateSpeedDifference(error);
    rightSpeed = maxSpeed - calculateSpeedDifference(error);
    lastError = error;
}

void Motors::setMotorSpeeds(int i) {
    motorCalculations();

    leftSpeed = constrain(leftSpeed, -200, maxSpeed);
    rightSpeed = constrain(rightSpeed, -200, maxSpeed);
    motors.setSpeeds((leftSpeed/i), (rightSpeed/i));
}

void Motors::calculateSpeedDifference(int error) {
    return error / 4 + 6 * (error - lastError);
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
    buzzer.playFromProgramSpace(CrabRaveSong::song);
}

void Motors::stopSong() {
    buzzer.stopPlaying();
}
