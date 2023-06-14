// #include "Arduino.h"
// #include "USBAPI.h"
#include "LineFollower.h"

LineFollower::LineFollower(readLine& readline) : rl(readline){
  gyro.init(); // Initialize gyro
  Serial.println("Linefollower created!");
}

bool LineFollower::followLine() {
    rl.identifyColor(); // Leest sensors in

    try{
      rl.checkHistory(); // checkt per 1000ms History
    }
    catch(...){// als dubbel bruin is gevonden
      Serial.println("Brown gevonden")
      motors.setSpeeds(200,200);
      delay(2000);
      motors.setSpeeds(0,0);
      delay(5000);
      return false;
    }

    position = rl.lineRider(); // Leest positie voor PID

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= 1000) {
      previousMillis = currentMillis;
      if (rl.GreySeen[0] || rl.GreySeen[1]){
        checkGrey();
      }
    }
    

    motor.setMotorSpeeds(rl.checkGreen()); 
    return true;
}

void LineFollower::checkGrey(){
  if (rl.GreySeen[0] && rl.GreySeen[1]) {
    motor.setSpeed(0,0);
    while(!gyro.isPitchBelowZero()){
      Serial.println("Wip it real good!");
    }
    rl.resetSeen();
    return
  }
  if ( (rl.GreySeen[0] && rl.BlackSeen[0]) && !rl.GreySeen[1]){
    motor.turnLeft();
    rl.resetSeen();
    return;
  }
  if ( (rl.GreySeen[1] && rl.BlackSeen[1]) && !rl.GreySeen[0]){
    motor.turnRight();
    rl.resetSeen();
    return;
  }
}