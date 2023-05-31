#include <Zumo32U4.h>
#include <Wire.h>

Zumo32U4LineSensors lineSensors;

const int numSensors = 5;
const int sensorMinValue = 0;
const int sensorMaxValue = 2000;

// Color thresholds for mapping sensor values to colors
const int middleWhiteMin = 0;
const int middleWhiteMax = 0;
const int middleBlackMin = 0;
const int middleBlackMax = 0;
const int middleRedMin = 0;
const int middleRedMax = 0;
const int middleBrownMin = 0;
const int middleBrownMax = 0;
const int middleGreenMin = 0;
const int middleGreenMax = 0;
const int middleGrayMin = 0;
const int middleGrayMax = 0;

const int outerWhiteMin = 0;
const int outerWhiteMax = 0;
const int outerBlackMin = 0;
const int outerBlackMax = 0;
const int outerRedMin = 0;
const int outerRedMax = 0;
const int outerBrownMin = 0;
const int outerBrownMax = 0;
const int outerGreenMin = 0;
const int outerGreenMax = 0;
const int outerGrayMin = 0;
const int outerGrayMax = 0;

void setup() {
  Serial.begin(9600);
  
  // Initialize line sensors
  lineSensors.initFiveSensors();
}

void loop() {
  // Read line sensor reflectance values
  uint16_t lineSensorValues[numSensors];
  lineSensors.read(lineSensorValues);
  
  // Map sensor values to colors
  String color1 = mapSensorValuesToColor(lineSensorValues[0], lineSensorValues[4]);
  String color2 = mapSensorValuesToColor(lineSensorValues[1], lineSensorValues[2], lineSensorValues[3]);
  
  // Print the detected colors
  Serial.print("Sensor 1 and 5: ");
  Serial.println(color1);
  Serial.print("Sensor 2, 3, and 4: ");
  Serial.println(color2);
  
  delay(1000); // Adjust the delay as per your requirements
}

String mapSensorValuesToColor(const uint16_t sensorValue1, const uint16_t sensorValue2) {
  int averageValue = calculateAverage(sensorValue1, sensorValue2);
  
  if (averageValue >= outerWhiteMin && averageValue <= outerWhiteMax) {
    return "White";
  } else if (averageValue >= outerBlackMin && averageValue <= outerBlackMax) {
    return "Black";
  } else if (averageValue >= outerRedMin && averageValue <= outerRedMax) {
    return "Red";
  } else if (averageValue >= outerBrownMin && averageValue <= outerBrownMax) {
    return "Brown";
  } else if (averageValue >= outerGreenMin && averageValue <= outerGreenMax) {
    return "Green";
  } else if (averageValue >= outerGrayMin && averageValue <= outerGrayMax) {
    return "Gray";
  } else {
    return "Unknown";
  }
}

String mapSensorValuesToColor(const uint16_t sensorValue1, const uint16_t sensorValue2, const uint16_t sensorValue3) {
  int averageValue = calculateAverage(sensorValue1, sensorValue2, sensorValue3);
  
  if (averageValue >= middleWhiteMin && averageValue <= middleWhiteMax) {
    return "White";
  } else if (averageValue >= middleBlackMin && averageValue <= middleBlackMax) {
    return "Black";
  } else if (averageValue >= middleRedMin && averageValue <= middleRedMax) {
    return "Red";
  } else if (averageValue >= middleBrownMin && averageValue <= middleBrownMax) {
    return "Brown";
  } else if (averageValue >= middleGreenMin && averageValue <= middleGreenMax) {
    return "Green";
  } else if (averageValue >= middleGrayMin && averageValue <= middleGrayMax) {
    return "Gray";
  } else {
    return "Unknown";
  }
}

int calculateAverage(const uint16_t value1, const uint16_t value2) {
  unsigned long sum = value1 + value2;
  
  return static_cast<int>(sum / 2);
}

int calculateAverage(const uint16_t value1, const uint16_t value2, const uint16_t value3) {
  unsigned long sum = value1 + value2 + value3;
  
  return static_cast<int>(sum / 3);
}
