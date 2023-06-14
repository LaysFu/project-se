#include <Wire.h>
#include "Robot.h"
<<<<<<< HEAD
#include <Arduino.h>
=======
#include <Zumo32U4.h>
>>>>>>> c0bfd119e469aa5ecbb9b0ad80bc4317063329fc


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