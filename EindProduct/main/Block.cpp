#include "Block.h"

Block::Block(){
    status = true;
    
    proxySensy.initThreeSensors();
    left_sensor = 0;
    right_sensor = 0;
}

void Block::readProxySensors(){
    proxySensy.read();
    left_sensor = proxySensy.countsFrontWithLeftLeds();
    right_sensor = proxySensy.countsFrontWithRightLeds();
};

bool Block::findBlock(){
    readProxySensors();
    if (left_sensor || right_sensor) {
        return true;
    }
    return false;
}

void Block::lineUpBlock(){
  // draai om te zorgen dat block in midden van zumo staat
  if (left_sensor <= 1 && right_sensor <= 1) {
    motor.setSpeeds(100, -100);
    delay(1000);
    motor.setSpeeds(0, 0);
  }
}

// void Block::avoidLine(){
//     // if blockLinedUp = false; and if linesensor registreerd line, move away
//     blockRL.identifyColor();
//     if (blockRL.color1 > 100) {
//         motor.setSpeeds(0,100);
//     }
//     if (blockRL.color2 > 100) {
//         motor.setSpeeds(-100,-50);
//     }
//     if (blockRL.color3 > 100) {
//         motor.setSpeeds(100,0);
//     }
// }

void Block::pushBlock(){
    
    if (left_sensor > 1 && right_sensor > 1) {
      motor.setSpeeds(300, 300);
      blockLinedUp = true;
    }
    else if (left_sensor >= 5 && right_sensor < 5) {
      motor.setSpeeds(150, 300);
      blockLinedUp = true;
    }
    else if (left_sensor < 5 && right_sensor >= 5) {
      motor.setSpeeds(300, 150);
      blockLinedUp = true;
    }

    delay(10);
}

// bool Block::checkWin() {
//     // check if blockLinedUp = true; if linesensor registreerd line, stop. 
//     if (blockLinedUp){
//         if (blockRL.color1 > 100 || blockRL.color2 > 100 || blockRL.color3 > 100 ) {
//           return true;
//         }
//     return false;
// }

