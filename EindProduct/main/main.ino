#include "LineFollower.h"
#include <Wire.h>
#include <Zumo32U4.h>



void setup()
{
    Serial.begin(9600);
} 

void loop()
{
  LineFollower lf;
  lf.followLine();
  //Serial.println("Hello world!");    
}