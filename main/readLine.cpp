// #include "HardwareSerial.h"
// #include "USBAPI.h"
#include "readLine.h"

readLine::readLine() : doubleGrey(0), doubleBrown(0) {
  lineSensors.initFiveSensors();
  calibrateLineSensors();
  lineSensors.emittersOn();
}

void readLine::setup(){

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
  return lineSensors.readLine(lineSensorPos);
}

void readLine::identifyColor() {
  lineSensors.readCalibrated(lineSensorValues);
  

  if((lineSensorValues[0] >= 280 && lineSensorValues[0] <= 350) && lineSensorValues[0] >= 280 && lineSensorValues[0] <= 350) {
    brownCount++;
  }
  if(lineSensorValues[0] >= 200 && lineSensorValues[0] <=  250){ 
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
    Serial.println("Black");
    color8 = "Black";
    leftGreyCount = 0;
    rightGreyCount = 0; 
    leftBlackCount = 0;
    rightBlackCount =0;
  }
  if (brownCount > 4){
    Serial.println("Brown");
    color8 = "Brown";
    brownCount = 0;
  }  
}