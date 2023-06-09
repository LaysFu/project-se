#include "Arduino.h"
#include "USBAPI.h"
#include "LineFollower.h"
#include "Zumo32U4Buttons.h"

LineFollower::LineFollower() : gameOn(true){
  Serial.println("Linefollower created!");
}

void LineFollower::followLine() {

  gyro.init(); // Initialize gyro
  

  while (gameOn) {
    rl.identifyColor(); // Identify sensor colors

    // if (rl.color2 == "White"){
    //    while(rl.color2 == "White"){
    //      rl.identifyColor();
    //      motors.setSpeeds(400,-350);
    //     }
    //     rl.whiteCount = 0;
    //     rl.color2 = "";
      
    // } 


    if (rl.color8 == "Gray" && rl.brownCount == 0) {
      setMotorSpeeds(0, 0);
      delay(1500);
      
      // while (true) {
      //    pauseMovement();
      //    if (!isPitchBelowZero()){
      //      break;
      //    }
      // }
      rl.color8 = "";
      rl.brownCount++;
    }
    if (rl.color8 == "Gray" && rl.brownCount > 0) {
      Serial.println("Ik ga naar block");
      motors.setSpeeds(100,100);
      delay(2000);
      motors.setSpeeds(0,0);
      delay(5000);
      rl.color8 = "";
      rl.brownCount = 0;
    }
        
  








    if (rl.color4 == "Gray" && rl.color8 == "Black"){ //&& rl.color4 == "White"){
        Serial.println("Ik ga Rechts");
        turnRight();
    }
    if (rl.color0 == "Gray" && rl.color8 == "Black"){ //&& rl.color4 == "White"){
        Serial.println("Ik ga Links");
        turnLeft();
    }

  
    int error = rl.position - 2000;
    int leftSpeed, rightSpeed;
    leftSpeed = maxSpeed + calculateSpeedDifference(error);
    rightSpeed = maxSpeed - calculateSpeedDifference(error);
    lastError = error;

    if (rl.color2 == "Green") {
      setMotorSpeeds((leftSpeed/2), (rightSpeed/2));
     }
    else {
      setMotorSpeeds(leftSpeed, rightSpeed);
    }
  }
}


bool LineFollower::isPitchBelowZero() {
  double pitch = gyro.calculatePitch();
  return (pitch < 0);
}

void LineFollower::pauseMovement() {
  motors.setSpeeds(0, 0); // Pause movement
}

void LineFollower::turnLeft() {

    Serial.println("BIDEN");
    
    motors.setSpeeds(-100, 200);
    delay(500);
    rl.color4 = "";
    rl.color8 = "";

}

void LineFollower::turnRight() {
    Serial.println("TRUMP");

    motors.setSpeeds(200, -100);
    delay(500);
    rl.color4 = "";
    rl.color8 = "";
}

void LineFollower::updateOnGreenLine() {
  onGreenLine = (rl.color2 == "Green");
}


String LineFollower::getColor() {
  return (onGreenLine ? "Green" : "Black");
}

int LineFollower::calculateSpeedDifference(int error) {
  return error + 3 * (error - lastError);
}

void LineFollower::setMotorSpeeds(int leftSpeed, int rightSpeed) {
  leftSpeed = constrain(leftSpeed, 0, maxSpeed);
  rightSpeed = constrain(rightSpeed, 0, maxSpeed);
  motors.setSpeeds(leftSpeed, rightSpeed);
}