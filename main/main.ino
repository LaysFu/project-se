#include <Wire.h>
#include "Robot.h"



void setup()
{
  Serial.begin(9600); 
} 

void loop()
{
  readLine RL;
  Robot Zumo(RL);
  
  RL.setup();
  Zumo.main();
}