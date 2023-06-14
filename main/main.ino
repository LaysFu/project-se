#include <Wire.h>
#include "Robot.h"



void setup()
{
  Serial.begin(9600); 
} 

void loop()
{
  readLine RL;
  LineFollower LF(RL);
  Block blocky(RL);
  Robot Zumo(RL, LF, blocky);

  Zumo.main();
}