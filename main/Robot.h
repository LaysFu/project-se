#ifndef ROBOT_H
#define ROBOT_H

#include "readLine.h"
#include "LineFollower.h"
#include "Block.h"

class Robot{
    private:
        bool gameOn; //start mainLoop
        readLine RL;
        LineFollower LF;
        Block blocky

    public:
        Robot();       
        void main();
  
};

#endif // ROBOT_H
