#include "LineFollower.h"
#include <Zumo32U4Buttons.h>

Zumo32U4ButtonA buttonA;
LineFollower lf;

void setup()
{
    Serial.begin(9600);
    Serial.println("Hello world!");
} 

void loop()
{;
    lf.followLine();
}