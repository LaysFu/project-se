#include "Robot.h"

Robot::Robot() : gameOn(false), gameOver(true){}

void Robot::main(){
    if (gameOver){
        Serial.println("Handbediening");
    }
    if (!gameOver){
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
}

