#include <Wire.h>
#include "Robot.h"
#include <Arduino.h>


void setup()
{
  Serial1.begin(9600); 
} 

void loop()
{
  Serial.println("1");
  readLine RL;
  Serial.println("2");
  LineFollower LF(RL);
  Serial.println("3");
  Block blocky(RL);
  Serial.println("4");
  Robot Zumo(RL, LF, blocky);
  Serial.println("5");

  Zumo.main();
}