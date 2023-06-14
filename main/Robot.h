#ifndef ROBOT_H
#define ROBOT_H

#include "readLine.h"
#include "LineFollower.h"
#include "Block.h"
#include "buzzer.h"
#include "controllerclass.h"

class Robot{
    private:
        readLine& rl;
        Buzzer player;
        Motors motor;
        ControllerClass Cont;
        LineFollower& LF;
        Block& blocky;

        void moveForward();

        bool gameOn; //start mainLoop
        bool gameOver; //stopt als gameOver
        bool setupDone;

    public:
        Robot(readLine&,LineFollower&, Block&);       
        void main();
  
};

#endif // ROBOT_H
