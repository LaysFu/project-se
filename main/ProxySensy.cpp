#include "ProxySensy.h"

ProxySensy::ProxySensy(){}

void ProxySensy::readProxySensors(){
    read();
    left_sensor = proxySensy.countsFrontWithLeftLeds();
    right_sensor = proxySensy.countsFrontWithRightLeds();
};

int ProxySensy::left(){
    return left_sensor;
}

int ProxySensy::right(){
    return right_sensor;
}