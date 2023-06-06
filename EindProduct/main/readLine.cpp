#include "readLine.h"

readLine::readLine() {
  lineSensors.initFiveSensors();
  calibrateLineSensors();
}

void readLine::identifyColor() {
  position = lineSensors.readLine(lineSensorValues);

  for (int i = 0; i < NUM_SENSORS; i++) {
    switch (i) {
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

  Serial.print("Sensor Left: ");
  Serial.println(color0);

  // Serial.print("Sensor Mid: ");
  // Serial.println(color2);
  Serial.print("Sensor Right: ");
  Serial.println(color4);
  Serial.println();
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
  int blackCount = 0;
  int brownCount = 0;
  int grayCount = 0;
  int whiteCount = 0;

  for (int j = 0; j < 8; j++) {
    if (lineSensorValues[i] >= sideBlackMin && lineSensorValues[i] <= sideBlackMax) {
      blackCount++;
    } else if (lineSensorValues[i] >= sideBrownMin && lineSensorValues[i] <= sideBrownMax) {
      brownCount++;
    } else if (lineSensorValues[i] >= sideGrayMin && lineSensorValues[i] <= sideGrayMax) {
      grayCount++;
    } else {
      whiteCount++;
    }
  }

  if (blackCount >= 8) {
    return "Black";
  } else if (brownCount >= 8) {
    return "Brown";
  } else if (grayCount >= 8) {
    return "Gray";
  } else {
    return "White";
  }
}

String readLine::getMidColor(int i) {
  int blackCount = 0;
  int greenCount = 0;
  int whiteCount = 0;

  for (int j = 0; j < 8; j++) {
    if (lineSensorValues[i] >= middleBlackMin && lineSensorValues[i] <= middleBlackMax) {
      blackCount++;
    } else if (lineSensorValues[i] >= middleGreenMin && lineSensorValues[i] <= middleGreenMax) {
      greenCount++;
    } else {
      whiteCount++;
    }
  }

  if (blackCount >= 8) {
    return "Black";
  } else if (greenCount >= 8) {
    return "Green";
  } else {
    return "White";
  }
}