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


        bool gameOn; //start mainLoop
        bool gameOver; //stopt als gameOver
        bool setupDone;

    public:
        Robot(readLine&);       
        void main();
  
};

#endif // ROBOT_H
