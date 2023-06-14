#include "ProxySensy.h"

ProxySensy::ProxySensy(){}

void ProxySensy::readProxySensors(){
    read();
    left_sensor = countsFrontWithLeftLeds();
    right_sensor = countsFrontWithRightLeds();
};

int ProxySensy::left(){
    return left_sensor;
}

int ProxySensy::right(){
    return right_sensor;
}