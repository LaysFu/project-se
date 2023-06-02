#include "LineFollower.h"
#include "gyro.h"
#include <Zumo32U4.h>
#include <Wire.h>
#include "readLine.h"

Zumo32U4LineSensors lineSensors;
Zumo32U4ButtonA buttonA;
readLine lineread;

void setup()
{
    Serial.begin(9600);
    lineSensors.initFiveSensors();
    buttonA.waitForButton();
    lineread.calibrateLineSensors();
} 

void loop()
{
    LineFollower lineFollower;
    lineFollower.followLine();
}