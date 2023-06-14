#include "Block.h"

Block::Block(readLine& rl) : blockRL(rl), blockLinedUp(false) {  
    PS.initThreeSensors();
}

bool Block::findBlock(){
    // Draai tot block gevonden is
    if (PS.left() <= 1 && PS.right() <= 1) {
        motor.setSpeeds(100, -100);
        delay(1000);
    }
    motor.setSpeeds(0, 0);
}

void Block::pushBlock(){   
    if (PS.left() > 1 && PS.right() > 1) {
      motor.setSpeeds(200, 200);
      blockLinedUp = true;
    }
    else if (PS.left() >= 5 && PS.right() < 5) {
      motor.setSpeeds(-400, 300);
      blockLinedUp = true;
    }
    else if (PS.left() < 5 && PS.right() >= 5) {
      motor.setSpeeds(300, -400);
      blockLinedUp = true;
    }
    else { blockLinedUp = false; }
    delay(10);
}

bool Block::checkWin() {
    // check if blockLinedUp = true; if linesensor registreerd line, stop. 
    if (blockLinedUp){
        return blockRL.checkBlack();
    }
    return false;
}

void Block::readProxy(){
    PS.readProxySensors();
};
