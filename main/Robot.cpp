#include "Robot.h"

Robot::Robot(readLine& rl, LineFollower& fl, Block& B) : rl(rl), LF(fl), blocky(B), gameOn(true), gameOver(true), setupDone(false){
  Block blocky(rl);

}

void Robot::main(){
    // if (gameOver){
    //     setupDone = Cont.Controller();
    // }
    if (!setupDone) { 
        Serial.println("Doing setup");
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

