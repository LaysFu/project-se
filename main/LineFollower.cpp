// #include "Arduino.h"
// #include "USBAPI.h"
#include "LineFollower.h"

LineFollower::LineFollower(readLine& rl) : rl(rl){
  gyro.init(); // Initialize gyro
  // Serial.println("Linefollower created!");
}

bool LineFollower::followLine() {
    rl.identifyColor(); // Leest sensors in

    //try{
      rl.checkHistory(); // checkt per 1000ms History
      Serial.println("History checked");
    //}
    //catch(...){// als dubbel bruin is gevonden .... (Werkt blijkbaar niet met arduino)
    // if (rl.BrownSeen[0] && rl.BrownSeen[1]){
    //   Serial.println("Brown gevonden");
    //   // Serial.println(rl.BrownSeen[0]);
    //   // Serial.println(rl.BrownSeen[1]);
    //   motors.setSpeeds(200,200);
    //   delay(2000);
    //   motors.setSpeeds(0,0);
    //   delay(5000);
    //   return false;
    // }

    position = rl.lineRider(); // Leest positie voor PID
    //Serial1.println(position);

   
      // Serial1.println("Grey?");
    if (rl.GreySeen[0] || rl.GreySeen[1]){
      Serial1.println("CheckGrey");
      checkGrey();
    }
    

    motors.setMotorSpeeds(rl.checkGreen(), position);
    //Serial1.println("Round"); 
    return true;
}

void LineFollower::checkGrey(){
  if (rl.GreySeen[0] && rl.GreySeen[1]) {
    motors.setSpeeds(0,0);
    delay(1000);
    // while(!gyro.isPitchBelowZero()){
    //   Serial1.println("Stop");
    // }
    rl.resetSeen();
    return;
  }
  if ( (rl.GreySeen[0] && rl.BlackSeen[0]) && !rl.GreySeen[1]){
    motors.turnLeft();
    Serial1.println("Biden");
    rl.resetSeen();
    return;
  }
  if ( (rl.GreySeen[1] && rl.BlackSeen[1]) && !rl.GreySeen[0]){
    motors.turnRight();
    Serial1.println("Trump");
    rl.resetSeen();
    return;
  }
}
