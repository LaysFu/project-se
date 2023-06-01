#include "LineSensorColors.h"

const int numSensors = 5;
const int sensorMinValue = 0;
const int sensorMaxValue = 2000;

const int middleWhiteMin = 0;
const int middleWhiteMax = 130;
const int middleBlackMin = 600;
const int middleBlackMax = 900;
const int middleGreenMin = 140;
const int middleGreenMax = 280;

const int midOutWhiteMin = 70;
const int midOutWhiteMax = 130;
const int midOutBlackMin = 230;
const int midOutBlackMax = 330;
const int midOutGreenMin = 130;
const int midOutGreenMax = 230;

const int outerWhiteMin = 80;
const int outerWhiteMax = 180;
const int outerBrownMin = 540;
const int outerBrownMax = 800;
const int outerGrayMin = 300;
const int outerGrayMax = 524;

LineSensorColors::LineSensorColors(const uint16_t* sensorValues) {
  lineSensorValues = sensorValues;
}

String LineSensorColors::getColor1() {
  if (lineSensorValues[0] >= outerWhiteMin && lineSensorValues[0] <= outerWhiteMax) {
    return "White";
  } else if (lineSensorValues[0] >= outerBrownMin && lineSensorValues[0] <= outerBrownMax) {
    return "Brown";
  } else if (lineSensorValues[0] >= outerGrayMin && lineSensorValues[0] <= outerGrayMax) {
    return "Gray";
  } else {
    return "Unknown";
  }
}

String LineSensorColors::getColor2() {
  if (lineSensorValues[1] >= midOutWhiteMin && lineSensorValues[1] <= midOutWhiteMax) {
    return "White";
  } else if (lineSensorValues[1] >= midOutBlackMin && lineSensorValues[1] <= midOutBlackMax) {
    return "Black";
  } else if (lineSensorValues[1] >= midOutGreenMin && lineSensorValues[1] <= midOutGreenMax) {
    return "Green";
  } else {
    return "Unknown";
  }
}

String LineSensorColors::getColor3() {
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

String LineSensorColors::getColor4() {
  if (lineSensorValues[3] >= midOutWhiteMin && lineSensorValues[3] <= midOutWhiteMax) {
    return "White";
  } else if (lineSensorValues[3] >= midOutBlackMin && lineSensorValues[3] <= midOutBlackMax) {
    return "Black";
  } else if (lineSensorValues[3] >= midOutGreenMin && lineSensorValues[3] <= midOutGreenMax) {
    return "Green";
  } else {
    return "Unknown";
  }
}

String LineSensorColors::getColor5() {
  if (lineSensorValues[4] >= outerWhiteMin && lineSensorValues[4] <= outerWhiteMax) {
    return "White";
  } else if (lineSensorValues[4] >= outerBrownMin && lineSensorValues[4] <= outerBrownMax) {
    return "Brown";
  } else if (lineSensorValues[4] >= outerGrayMin && lineSensorValues[4] <= outerGrayMax) {
    return "Gray";
  } else {
    return "Unknown";
  }
}
