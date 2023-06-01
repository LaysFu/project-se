#include "readLine.h"

const int sensorMinValue = 0;
const int sensorMaxValue = 2000;

const int middleWhiteMin = 0;
const int middleWhiteMax = 130;
const int middleBlackMin = 600;
const int middleBlackMax = 2000;
const int middleGreenMin = 140;
const int middleGreenMax = 280;

const int midOutWhiteMin = 70;
const int midOutWhiteMax = 130;
const int midOutBlackMin = 230;
const int midOutBlackMax = 2000;
const int midOutGreenMin = 130;
const int midOutGreenMax = 230;

const int leftWhiteMin = 80;
const int leftWhiteMax = 200;
const int leftBrownMin = 520;
const int leftBrownMax = 700;
const int leftGrayMin = 210;
const int leftGrayMax = 520;
const int leftBlackMin = 700;
const int leftBlackMax = 2000;

const int rightWhiteMin = 80;
const int rightWhiteMax = 200;
const int rightBrownMin = 420;
const int rightBrownMax = 700;
const int rightGrayMin = 210;
const int rightGrayMax = 420;
const int rightBlackMin = 700;
const int rightBlackMax = 2000;

readLine::LineSensorColors(const uint16_t* sensorValues) {
  lineSensorValues = sensorValues;
}

String readLine::getColor1() {
  if (lineSensorValues[0] >= leftWhiteMin && lineSensorValues[0] <= leftWhiteMax) {
    return "White";
  } else if (lineSensorValues[0] >= leftBrownMin && lineSensorValues[0] <= leftBrownMax) {
    return "Brown";
  } else if (lineSensorValues[0] >= leftGrayMin && lineSensorValues[0] <= leftGrayMax) {
    return "Gray";
  } else if (lineSensorValues[0] >= leftBlackMin && lineSensorValues[0] <= leftBlackMax) {
    return "Black";
  } else {
    return "Unknown";
  }
}

String readLine::getColor2() {
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

String readLine::getColor3() {
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

String readLine::getColor4() {
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

String readLine::getColor5() {
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
