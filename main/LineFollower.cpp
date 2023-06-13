#include "Arduino.h"
#include "USBAPI.h"
#include "LineFollower.h"

LineFollower::LineFollower(readLine& readline) : rl(readline){
  gyro.init(); // Initialize gyro
  Serial.println("Linefollower created!");
}

bool LineFollower::followLine() {

    rl.identifyColor(); // Identify sensor colors

    if (rl.color4 == "Gray" && rl.color8 == "Black"){
        Serial.println("Ik ga Rechts");
        turnRight();
        rl.color4 = "";
        rl.color8 = "";
    }
    if (rl.color0 == "Gray" && rl.color8 == "Black"){ 
        Serial.println("Ik ga Links");
        turnLeft();
        rl.color4 = "";
        rl.color8 = "";
    }
    if (rl.color8 == "Brown"){
        motors.setSpeeds(200,200);
        delay(2000);
        motors.setSpeeds(0,0);
        delay(5000);
        return false;
    }
    
    if (rl.color2 == "Green"){ setMotorSpeeds((leftSpeed/2), (rightSpeed/2)); }
    else { setMotorSpeeds(leftSpeed, rightSpeed); }
    return true;
}



bool LineFollower::isPitchBelowZero() {
  double pitch = gyro.calculatePitch();
  return (pitch < 0);
}


void LineFollower::turnLeft() {
    motors.setSpeeds(0, 200);
    delay(700);
    rl.color4 = "";
    rl.color8 = "";

}

void LineFollower::turnRight() {
    motors.setSpeeds(200, 0);
    delay(700);
    rl.color4 = "";
    rl.color8 = "";
}


