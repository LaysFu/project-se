#include "Robot.h"

Robot::Robot() : gameOn(true){}

void Robot::main(){

    while(gameOn){
        gameOn = LF.followLine();       
    }
    if(!gameOn){
        blocky.readProxy();
        blocky.findBlock();
        blocky.lineUpBlock();
        blocky.pushBlock();
        gameOver = blocky.gameOver();
        if(gameOver){ return }
    }

}

