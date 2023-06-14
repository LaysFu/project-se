#include "Robot.h"

Robot::Robot(readLine& rl) : rl(rl), gameOn(false), gameOver(true), setupDone(true){
    LineFollower LF(rl);
    ControllerClass CR(player);
    Block blocky(rl);
}

void Robot::main(){
    if (gameOver){
        setupDone = CR.Controller();       
    }
    if (!setupDone) { 
        rl.setup(); 
        setupDone = true;
        gameOver = false;
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

