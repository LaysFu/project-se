#include "Block.h"

Block::Block(){
    status = true;
    proxySensy.initThreeSensors();
    linySensy.initThreeSensors();
    linySensy.emittersOn();
    for(int i = 0; i < 400; i++){
        linySensy.calibrate();
    }
}

void Block::readProxySensors(){
    proxySensy.read();
    cleft_sensor = proxySensy.countsFrontWithLeftLeds();
    left_sensor = proxySensy.countsLeftWithLeftLeds();
    cright_sensor = proxySensy.countsFrontWithRightLeds();
    right_sensor = proxySensy.countsRightWithRightLeds();
};

void Block::readLineSensors(){
    linySensy.read(line_sensor);
};

bool Block::findBlock(){
    readProxySensors();
    if (cleft_sensor || left_sensor || cright_sensor || right_sensor) {
        return true;
    }
    return false;
}

void Block::lineUpBlock(){
    // draai om te zorgen dat block in midden van zumo staat
};

void Block::avoidLine(){
    // if blockLinedUp = false; and if linesensor registreerd line, move away
    readLineSensors();
    if (line_sensor[0] > 100) {
        motor.setSpeeds(0,100);
    }
    if (line_sensor[1] > 100) {
        motor.setSpeeds(-100,-50);
    }
    if (line_sensor[2] > 100) {
        motor.setSpeeds(100,0);
    }
}

void Block::pushBlock(){
    // if blockLinedUp = true, push. blijf ook kijken of blockLinedUp en checkWin
    if (blockLinedUp && !checkWin()){
        motor.setSpeeds(200, 200);
    }
}

bool Block::checkWin(){
    // check if blockLinedUp = true; if linesensor registreerd line, stop. 
    readLineSensors();
    if (blockLinedUp){
        for (unsigned int i = 0; i < 3; i++){
            if (line_sensor[i] > 100){
                return true;
            }
        }
    }
    return false;
}

