#include "LineFollower.h"
#include "gyro.h"
#include <Zumo32U4.h>
#include <Wire.h>


void setup()
{
    Serial.begin(9600);
} 

void loop()
{
    LineFollower lineFollower;
    lineFollower.followLine();
}