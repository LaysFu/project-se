// #include "Arduino.h"
// #include "USBAPI.h"
#include "LineFollower.h"

LineFollower::LineFollower(readLine& rl) : rl(rl){
  gyro.init(); // Initialize gyro
  Serial.println("Linefollower created!");
}

bool LineFollower::followLine() {
    rl.identifyColor(); // Leest sensors in

    //try{
      rl.checkHistory(); // checkt per 1000ms History
    //}
    //catch(...){// als dubbel bruin is gevonden .... (Werkt blijkbaar niet met arduino)
    if (rl.BrownSeen[0] && rl.BrownSeen[1]){
      Serial.println("Brown gevonden");
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
    

    motors.setMotorSpeeds(rl.checkGreen(), position); 
    return true;
}

void LineFollower::checkGrey(){
  if (rl.GreySeen[0] && rl.GreySeen[1]) {
    motors.setSpeeds(0,0);
    while(!gyro.isPitchBelowZero()){
      Serial.println("Wip it real good!");
    }
    rl.resetSeen();
    return;
  }
  if ( (rl.GreySeen[0] && rl.BlackSeen[0]) && !rl.GreySeen[1]){
    motors.turnLeft();
    rl.resetSeen();
    return;
  }
  if ( (rl.GreySeen[1] && rl.BlackSeen[1]) && !rl.GreySeen[0]){
    motors.turnRight();
    rl.resetSeen();
    return;
  }
}
