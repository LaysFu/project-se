#include "USBAPI.h"
#include "LineFollower.h"


LineFollower::LineFollower() : gameOn(true){
  Serial.println("Linefollower created!");
}

void LineFollower::followLine() {
  bool goLeft = false;
  bool goRight = false;

  //gyro.init(); // Initialize gyro

  while (gameOn) {
    if(!(goLeft || goRight)) {rl.identifyColor();} // Identify sensor colors

  //   // if (rl.color1 == "Brown" || rl.color5 == "Brown" {
  //   //   gameOn = false;
  //   //   block.switchMode(); // Switch naar block mode
  //   //   break;
  //   // }

    if (rl.color0 == "Gray" && rl.color4 == "White"){
          Serial.println("Ik ga links");
          turnLeft();
    } 

    else if (rl.color4 == "Gray" && rl.color0 == "White") {
          Serial.println("Ik ga Rechts");
          turnRight();
          }
        }
      
      
      //-----------------------------
    // else if (rl.color0 == "Gray" && rl.color4 == "Gray") {
    //   pauseMovement();
    //   delay(750);
    //   goLeft = false;
    //   goRight = false;
    // } 

    // if (goLeft && !goRight) {
    //   if (rl.color0 == "Black") {
    //     Serial.println("LINKS");
        
    //     goLeft = false;
    //   }
    // }
    // if (goRight && !goLeft) {
    //   if (rl.color4 == "Black") {
    //     Serial.println("TRUMP");
    //     turnRight();
    //     goRight = false;
    //   }
    // }
    updateOnGreenLine();
     

    int error = rl.position - 2000;
    int leftSpeed, rightSpeed;
    leftSpeed = maxSpeed + calculateSpeedDifference(error);
    rightSpeed = maxSpeed - calculateSpeedDifference(error);
    lastError = error;
    setMotorSpeeds(leftSpeed, rightSpeed);
  


}
// bool LineFollower::isPitchBelowZero() {
//   double pitch = gyro.calculatePitch();
//   return (pitch < 0);
// }

void LineFollower::pauseMovement() {
  motors.setSpeeds(0, 0); // Pause movement
}
//-----------------------------------
void LineFollower::turnLeft() {
    
    Serial.println("LEFT");
    motors.setSpeeds(0, maxSpeed);
    
}

void LineFollower::turnRight() {

    Serial.println("RIGHT");
    motors.setSpeeds(maxSpeed, 0);
     
}
//--------------------------------------
void LineFollower::updateOnGreenLine() {
  onGreenLine = (rl.color2 == "Green");
}


String LineFollower::getColor() {
  return (onGreenLine ? "Green" : "Black");
}

int LineFollower::calculateSpeedDifference(int error) {
  return error / 4 + 6 * (error - lastError);
}

void LineFollower::setMotorSpeeds(int leftSpeed, int rightSpeed) {
  leftSpeed = constrain(leftSpeed, 0, maxSpeed);
  rightSpeed = constrain(rightSpeed, 0, maxSpeed);
  motors.setSpeeds(leftSpeed, rightSpeed);
}