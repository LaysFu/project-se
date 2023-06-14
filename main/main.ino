#include <Wire.h>
#include "Robot.h"
#include <Arduino.h>
#include <Zumo32U4.h>


void setup()
{
  Serial1.begin(9600); 
} 

void loop()
{
  readLine RL;
  
  LineFollower LF(RL);

  Block blocky(RL);
  Robot Zumo(RL, LF, blocky);


  Zumo.main();
}