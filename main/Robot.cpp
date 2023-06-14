#include "Robot.h"
#include <Zumo32U4.h>

Robot::Robot(readLine& rl, LineFollower& fl, Block& B) : rl(rl), LF(fl), blocky(B), gameOn(false), gameOver(true), setupDone(false){
  Block blocky(rl);

}

void Robot::main(){
    // if (gameOver){
    //     setupDone = Cont.Controller();
    // }
    if (!setupDone) { 
        rl.setup(); 
        Zumo32U4ButtonA bA;
        bA.waitForButton();
        player.melodyFour();
        delay(1300);
        moveForward();
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

void Robot :: moveForward()
{
  Motors motor;
  motor.setSpeeds(200, 200);
  delay(1200);
  motor.setSpeeds(0, 0);
}