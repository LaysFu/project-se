#include "HardwareSerial.h"
#include "USBAPI.h"
#include "readLine.h"

readLine::readLine() {
  lineSensors.initFiveSensors();
  calibrateLineSensors();
  lineSensors.emittersOn();
}

void readLine::identifyColor() {
  position = lineSensors.readLine(lineSensorPos);  
  lineSensors.readCalibrated(lineSensorValues);
  //Serial.println(position);
  if (lineSensorValues[2] < 50) {
    whiteCount++;
  }
  else { whiteCount = 0; }
  if (lineSensorValues[2] > 100 && lineSensorValues[2] < 200){
    color2 = "Green";
  }
  Serial.print("Links");
  Serial.println(lineSensorValues[0]);
  Serial.print("Rechts");
  Serial.println(lineSensorValues[4]);
  if((lineSensorValues[0] >= 250 && lineSensorValues[0] <= 350) && lineSensorValues[4] >= 280 && lineSensorValues[4] <= 350) {
    brownCount++;
  }
  if(lineSensorValues[0] >= 180 && lineSensorValues[0] <=  230){ 
          leftGreyCount++; 
          leftBlackCount =0;
  }
  else if(lineSensorValues[0] >= 500){ 
          leftBlackCount++; 
          leftGreyCount =0;
        }
  if(lineSensorValues[4] >= 150 && lineSensorValues[4] <= 200 ){ 
          rightGreyCount++; 
          rightBlackCount =0;
  }
  else if(lineSensorValues[4] >= 500){ 
          rightBlackCount++; 
          rightGreyCount =0;
  }
  if (leftGreyCount >= 4){
      Serial.println("Grey");
        color0 = "Gray";
        leftGreyCount = 0; 
    }
  if (rightGreyCount >= 4) {
        Serial.println("Grey");
        color4 = "Gray";
        rightGreyCount = 0; 
      }
  if (leftBlackCount > 5 || rightBlackCount > 5){
    //Serial.println("Black");
    color8 = "Black";
    leftGreyCount = 0;
    rightGreyCount = 0; 
    leftBlackCount = 0;
    rightBlackCount =0;
  }
  if (brownCount > 2){
    Serial.println("Brown");
    color8 = "Brown";
    brownCount = 0;
  }
  if(whiteCount > 50){
    color2 = "White";
  }

  
  
    // Serial.print("Sensor Left: ");
    // Serial.println(color0);
  
    // // Serial.print("Sensor Mid: ");
    // // Serial.println(color2);
    // Serial.print("Sensor Right: ");
    // Serial.println(color4);
    // Serial.println();

  
}

void readLine::calibrateLineSensors() {
  Zumo32U4Motors motor;
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

String readLine::getSideColor(int i) {
  if (lineSensorValues[i] >= sideBlackMin && lineSensorValues[i] <= sideBlackMax) {
    return "Black";
  } else if (lineSensorValues[i] >= sideBrownMin && lineSensorValues[i] <= sideBrownMax) {
    return "Brown";
  } else if (lineSensorValues[i] >= sideGrayMin && lineSensorValues[i] <= sideGrayMax) {
    return "Gray";
  } else {
    return "White";
  }
}

String readLine::getMidColor(int i) {
  if (lineSensorValues[i] >= middleBlackMin && lineSensorValues[i] <= middleBlackMax) {
    return "Black";
  } else if (lineSensorValues[i] >= middleGreenMin && lineSensorValues[i] <= middleGreenMax) {
    return "Green";
  } else {
    return "White";
  }
}