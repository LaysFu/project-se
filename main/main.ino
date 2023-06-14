#include <Wire.h>
#include "Robot.h"



void setup()
{
  Serial.begin(9600); 
} 

void loop()
{
  Robot Zumo;
  readLine RL;
  RL.setup();
  Zumo.main();
}