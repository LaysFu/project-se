// #include "HardwareSerial.h"
// #include "USBAPI.h"
#include "readLine.h"
#include "Motors.h"
#include <Zumo32U4Buttons.h>

readLine::readLine() : Green(1), index(0){
  for (int i : leftAR) { leftAR[i] = 0; }
  for (int i : rightAR) { rightAR[i] = 0; }
}

void readLine::setup(){
  // basic setup
  lineSensors.initFiveSensors();
  lineSensors.emittersOn();
  Zumo32U4ButtonA bA;
  Zumo32U4ButtonB bB;

  
  calibrateLineSensors();
  // calibrate all colors
  bB.waitForButton();
  Grey = (lineSensorValues[0] + lineSensorValues[4]) / 2;
  bB.waitForButton();
  Brown = (lineSensorValues[0] + lineSensorValues[4]) / 2;
  bB.waitForButton();
  Black = (lineSensorValues[0] + lineSensorValues[4]) / 2;
  bA.waitForButton();
}

void readLine::calibrateLineSensors() {
  Motors motor;
  Serial.println("Start calibrating!");
  delay(1000);
  for (uint16_t i = 0; i < 120; i++) {
    if (i > 30 && i <= 90) {
      motor.setSpeeds(-200, 200);
    } else {
      motor.setSpeeds(200, -200);
    }
    lineSensors.calibrate();
  }
  motor.setSpeeds(0, 0);
}

uint16_t readLine::lineRider() {
  return lineSensorPos.readLine(lineSensorPos);
}

void readLine::identifyColor() {
  lineSensors.readCalibrated(lineSensorValues);
  leftAR[index] = lineSensorValues[0];
  rightAR[index] = lineSensorValues[4];
  index++;
}

void readLine::checkHistory(){
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= INTERVAL) {
    previousMillis = currentMillis;
    int highestLeft = 0;
    int highestRight = 0;
    for (int i : leftAR) {
      if (highestLeft < leftAR[i]){ highestLeft = leftAR[i]; }
      if (highestRight < rightAR[i]){ highestRight = rightAR[i]; } 
      Serial.println(" " + leftAR[i]);
      Serial.println(" " + rightAR[i]);    
    }
    inRangeCheck(highestLeft, highestRight);
  }
}

void readLine::inRangeCheck(int highL, int highR){
  if ( highL == 1000) { BlackSeen[0] = true; }
  if ( highR == 1000) { BlackSeen[1] = true; return; }
  // if (highL >= (Grey-RANGE) && highL <= (Grey+RANGE)) { Grey[0] = true }
  // if (highR >= (Grey-RANGE) && highL <= (Grey+RANGE)) { Grey[2] = true }
  // if (highL >= (Brown-RANGE) && highL <= (Brown+RANGE)) { Brown[0] = true }
  // if (highR >= (Brown-RANGE) && highL <= (Brown+RANGE)) { Brown[2] = true }

  // als dit niet werkt weer naar bovenste gaan
  if ( (highL-(Grey+RANGE))*(highL-(Grey-RANGE)) <= 0) { GreySeen[0] = true; }
  if ( (highR-(Grey+RANGE))*(highR-(Grey-RANGE)) <= 0) { GreySeen[1] = true; return; }
  if ( (highL-(Brown+RANGE))*(highL-(Brown-RANGE)) <= 0) { BrownSeen[0] = true; }
  if ( (highR-(Brown+RANGE))*(highL-(Brown-RANGE)) <= 0) { throw; }
}

void resetSeen(){
  for (int i : GreySeen){
    GreySeen[i] = false;
    BrownSeen[i] = false;
    BlackSeen[i] = false;
  }
}