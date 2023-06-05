#include "readLine.h"

readLine::readLine() {
  Serial.println("Hi readline");
  lineSensors.initFiveSensors();
  calibrateLineSensors();
}

void readLine::identifyColor() {
  int16_t position = lineSensors.readLine(lineSensorValues);

  // for (int i = 0; i < NUM_SENSORS; i++){
  //   switch(i){
  //     case 0:
  //       color0 = getSideColor(i); 
  //       break;
  //     case 1:
  //       color1 = getMidColor(i); 
  //       break;
  //     case 2: 
  //       color2 = getMidColor(i); 
  //       break;
  //     case 3:
  //       color3 = getMidColor(i); 
  //       break;
  //     case 4: 
  //       color4 = getSideColor(i); 
  //       break;
  //   }
  // }
  color0 = getColor0();
  color1 = getColor1();
  color2 = getColor2();
  color3 = getColor3();
  color4 = getColor4();

  Serial.print("Sensor Left: ");
  Serial.println(lineSensorValues[0]);
  Serial.print("Sensor MidL: ");
  Serial.println(lineSensorValues[1]);
  Serial.print("Sensor Mid: ");
  Serial.println(lineSensorValues[2]);
  Serial.print("Sensor MidR: ");
  Serial.println(lineSensorValues[3]);
  Serial.print("Sensor Right: ");
  Serial.println(lineSensorValues[4]);

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

// String readLine::getSideColor(int i) {
//   if (lineSensorValues[i] >= leftWhiteMin && lineSensorValues[i] <= leftWhiteMax) {
//     return "White";
//   } else if (lineSensorValues[i] >= leftBrownMin && lineSensorValues[i] <= leftBrownMax) {
//     return "Brown";
//   } else if (lineSensorValues[i] >= leftGrayMin && lineSensorValues[i] <= leftGrayMax) {
//     return "Gray";
//   } else if (lineSensorValues[i] >= leftBlackMin && lineSensorValues[i] <= leftBlackMax) {
//     return "Black";
//   } else {
//     return "Unknown";
//   }
// }

// String readLine::getMidColor(int i) {
//   if (lineSensorValues[i] >= middleWhiteMin && lineSensorValues[i] <= middleWhiteMax) {
//     return "White";
//   } else if (lineSensorValues[i] >= middleBlackMin && lineSensorValues[i] <= middleBlackMax) {
//     return "Black";
//   } else if (lineSensorValues[i] >= middleGreenMin && lineSensorValues[i] <= middleGreenMax) {
//     return "Green";
//   } else {
//     return "Unknown";
//   }
// }

String readLine::getColor0() {
  if (lineSensorValues[0] >= rightWhiteMin && lineSensorValues[0] <= rightWhiteMax) {
    return "White";
  } else if (lineSensorValues[0] >= rightBrownMin && lineSensorValues[0] <= rightBrownMax) {
    return "Brown";
  } else if (lineSensorValues[0] >= rightGrayMin && lineSensorValues[0] <= rightGrayMax) {
    return "Gray";
  } else if (lineSensorValues[0] >= rightBlackMin && lineSensorValues[0] <= rightBlackMax) {
    return "Black";
  } else {
    return "Unknown";
  }
}

String readLine::getColor1() {
  return "";
}

String readLine::getColor2() {
  if (lineSensorValues[2] >= middleWhiteMin && lineSensorValues[2] <= middleWhiteMax) {
    return "White";
  } else if (lineSensorValues[2] >= middleBlackMin && lineSensorValues[2] <= middleBlackMax) {
    return "Black";
  } else if (lineSensorValues[2] >= middleGreenMin && lineSensorValues[2] <= middleGreenMax) {
    return "Green";
  } else {
    return "Unknown";
  }
}

String readLine::getColor3() {
  return "";
}

String readLine::getColor4() {
  if (lineSensorValues[4] >= rightWhiteMin && lineSensorValues[4] <= rightWhiteMax) {
    return "White";
  } else if (lineSensorValues[4] >= rightBrownMin && lineSensorValues[4] <= rightBrownMax) {
    return "Brown";
  } else if (lineSensorValues[4] >= rightGrayMin && lineSensorValues[4] <= rightGrayMax) {
    return "Gray";
  } else if (lineSensorValues[4] >= rightBlackMin && lineSensorValues[4] <= rightBlackMax) {
    return "Black";
  } else {
    return "Unknown";
  }
}
