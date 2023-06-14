#include "HardwareSerial.h"
#include "USBAPI.h"
#include "readLine.h"
#include "Motors.h"
#include <Zumo32U4Buttons.h>

readLine::readLine() : index(0){
  for (int i : leftAR) { leftAR[i] = 0; }
  for (int i : rightAR) { rightAR[i] = 0; }
  GreySeen[0] = false;
  GreySeen[1]=false;

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
  lineSensors.readCalibrated(lineSensorValues);
  GreyL = lineSensorValues[0];
  GreyR = lineSensorValues[4];
  Serial1.print("Links: ");
  Serial1.println(GreyL);
  Serial1.print("Rechts: ");
  Serial1.println(GreyR);
  bB.waitForButton();
  lineSensors.readCalibrated(lineSensorValues);
  BrownL = lineSensorValues[0];
  BrownR = lineSensorValues[4];
  Serial1.print("Links: ");
  Serial1.println(BrownL);
  Serial1.print("Rechts: ");
  Serial1.println(BrownR);
  bA.waitForButton();
}

void readLine::calibrateLineSensors() {
  Motors motor;
  Serial1.println("Start calibrating!");
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
  return lineSensors.readLine(lineSensorPos);
}

void readLine::identifyColor() {
  lineSensors.readCalibrated(lineSensorValues);
  leftAR[index] = lineSensorValues[0];
  rightAR[index] = lineSensorValues[4];
  index++;
  if (index > 50) { index = 0; }
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
      // Serial.println(" " + leftAR[i]);
      // Serial.println(" " + rightAR[i]);    
    }
    inRangeCheck(highestLeft, highestRight);
  }
}

void readLine::inRangeCheck(int highL, int highR){
  if ( highL == 1000) { BlackSeen[0] = true; }
  if ( highR == 1000) { BlackSeen[1] = true; return; }
  if (highL >= (GreyL-RANGE) && highL <= (GreyL+RANGE) && highR >= (GreyR-RANGE) && highR <= (GreyR+RANGE)) {
    Serial1.println("SetGrey");
    GreySeen[0] = true;
    GreySeen[1] = true;
    return;
  }
  if (highL >= (GreyL-RANGE) && highL <= (GreyL+RANGE)) { GreySeen[0] = true; GreySeen[1] = false;}
  if (highR >= (GreyR-RANGE) && highR <= (GreyR+RANGE)) { GreySeen[1] = true; GreySeen[0] = false;}
  if (highL >= (BrownL-RANGE) && highL <= (BrownL+RANGE)) { BrownSeen[0] = true; }
  if (highR >= (BrownR-RANGE) && highR <= (BrownR+RANGE)) { BrownSeen[1] = true; }

  // als dit niet werkt weer naar bovenste gaan
  // if ( (highL-(Grey+RANGE))*(highL-(Grey-RANGE)) <= 0) { GreySeen[0] = true; }
  // if ( (highR-(Grey+RANGE))*(highR-(Grey-RANGE)) <= 0) { GreySeen[1] = true; return; }
  // if ( (highL-(Brown+RANGE))*(highL-(Brown-RANGE)) <= 0) { BrownSeen[0] = true; }
  // if ( (highR-(Brown+RANGE))*(highL-(Brown-RANGE)) <= 0) { BrownSeen[1] = true; }
}

bool readLine::checkBlack(){
  lineSensors.readCalibrated(lineSensorValues);
  return (lineSensorValues[2] == 1000);
}

int readLine::checkGreen(){
  return (lineSensorValues[2] >= 100 && lineSensorValues[2] <= 200) ? 2 : 1;
}

void readLine::resetSeen(){
  for (auto i : GreySeen){
    GreySeen[i] = false;
    BrownSeen[i] = false;
    BlackSeen[i] = false;
  }
}