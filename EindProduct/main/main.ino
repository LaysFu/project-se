#include "LineFollower.h"
#include "gyro.h"
#include <Zumo32U4.h>
#include <Wire.h>
#include "readLine.h"

Zumo32U4ButtonA buttonA;
readLine lineread;
LineFollower lf;

void setup()
{
    Serial.begin(9600);
    Serial.println("Hello world!");

    //lineread.calibrateLineSensors();
} 

void loop()
{;
    //lf.followLine(lineread);
}