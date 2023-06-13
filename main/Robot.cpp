#include "Robot.h"

Robot::Robot() : gameOn(true){}

void Robot::main(){

    while(gameOn){
        LF.lineRider();
        gameOn = LF.followLine();
        LF.setMotorSpeeds();        
    }
    if(!gameOn){
        blocky.findBlock();
        blocky.lineUpBlock();
        blocky.pushBlock();
        gameOver = blocky.gameOver();
        if(gameOver){ return }
    }

}

