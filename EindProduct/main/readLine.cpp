#include "readLine.h"

readLine::readLine() {
  lineSensors.initFiveSensors();
  calibrateLineSensors();
}

void readLine::identifyColor() {
  position = lineSensors.readLine(lineSensorValues);

  for (int i = 0; i < NUM_SENSORS; i++){
    switch(i){
      case 0:
        color0 = getSideColor(i); 
        break;
      case 2: 
        color2 = getMidColor(i); 
        break;
      case 4: 
        color4 = getSideColor(i); 
        break;
    }
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