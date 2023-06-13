#include <Wire.h>
#include <Zumo32U4.h>
#include "controllerclass.h"

ControllerClass controller;

void setup() {
  Serial1.begin(9600);
}

void loop() {
  controller.Controller();
}