// #include "Arduino.h"
// #include "USBAPI.h"
#include "LineFollower.h"

LineFollower::LineFollower(readLine& readline) : rl(readline){
  gyro.init(); // Initialize gyro
  Serial.println("Linefollower created!");
}

bool LineFollower::followLine() {
    try{
      rl.identifyColor(); // Identify sensor colors
    }
    catch(...){
      motors.setSpeeds(200,200);
      delay(2000);
      motors.setSpeeds(0,0);
      delay(5000);
      return false;
    }

    position = rl.lineRider();

    if (rl.color4 == "Gray" && rl.color8 == "Black"){
        motors.turnRight();
        rl.color4 = "";
        rl.color8 = "";
    }
    if (rl.color0 == "Gray" && rl.color8 == "Black"){ 
        motors.turnLeft();
        rl.color0 = "";
        rl.color8 = "";
    }
    
    if (rl.color2 == "Green"){ 
      motor.setMotorSpeeds(2); 
    } else {
      motor.setMotorSpeeds(1); 
    }


    return true;
}