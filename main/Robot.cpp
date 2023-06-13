#include "Robot.h"

Robot::Robot() : gameOn(true), gameOver(false){}

void Robot::main(){

    while(gameOn){
        gameOn = LF.followLine();       
    }
    if(!gameOn){
        blocky.readProxy();
        blocky.findBlock();
        blocky.lineUpBlock();
        blocky.pushBlock();
        gameOver = blocky.checkWin();
        if(gameOver){ return }
    }

}

