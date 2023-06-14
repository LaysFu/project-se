#include "Robot.h"

Robot::Robot(readLine& rl, LineFollower& fl, Block& B) : rl(rl), LF(fl), blocky(B), gameOn(false), gameOver(true), setupDone(true){
  Block blocky(rl);

}

void Robot::main(){
    if (gameOver){
        setupDone = Cont.Controller();
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
            blocky.pushBlock();
            gameOver = blocky.checkWin();
            if(gameOver){ return; }
        }
    }
}

