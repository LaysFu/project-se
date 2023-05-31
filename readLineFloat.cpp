#include <Zumo32U4.h>
#include <Wire.h>

Zumo32U4LineSensors lineSensors;

const int numSensors = 5;
const int sensorMinValue = 0;
const int sensorMaxValue = 2000;

// Color thresholds for mapping normalized sensor values to colors
const float middleWhiteMin = 0.0;
const float middleWhiteMax = 0.2;
const float middleBlackMin = 0.3;
const float middleBlackMax = 0.5;
const float middleRedMin = 0.6;
const float middleRedMax = 0.8;
const float middleBrownMin = 0.9;
const float middleBrownMax = 1.0;
const float middleGreenMin = 1.1;
const float middleGreenMax = 1.3;
const float middleGrayMin = 1.4;
const float middleGrayMax = 1.6;

const float outerWhiteMin = 0.0;
const float outerWhiteMax = 0.2;
const float outerBlackMin = 0.3;
const float outerBlackMax = 0.5;
const float outerRedMin = 0.6;
const float outerRedMax = 0.8;
const float outerBrownMin = 0.9;
const float outerBrownMax = 1.0;
const float outerGreenMin = 1.1;
const float outerGreenMax = 1.3;
const float outerGrayMin = 1.4;
const float outerGrayMax = 1.6;

// Variables to store min and max values observed during runtime
float minValue = sensorMaxValue;
float maxValue = sensorMinValue;

void setup() {
  Serial.begin(9600);
  
  // Initialize line sensors
  lineSensors.initFiveSensors();
}

void loop() {
  // Read line sensor reflectance values
  uint16_t lineSensorValues[numSensors];
  lineSensors.read(lineSensorValues);
  
  // Update min and max values
  updateMinMaxValues(lineSensorValues);
  
  // Map sensor values to colors
  String color1 = mapSensorValuesToColor(normalizeSensorValue(lineSensorValues[0]));
  String color2 = mapSensorValuesToColor(normalizeSensorValue(lineSensorValues[1]), normalizeSensorValue(lineSensorValues[2]), normalizeSensorValue(lineSensorValues[3]));
  
  // Print the detected colors
  Serial.print("Sensor 1: ");
  Serial.println(color1);
  Serial.print("Sensor 2, 3, and 4: ");
  Serial.println(color2);
  
  delay(1000); // Adjust the delay as per your requirements
}

float normalizeSensorValue(const uint16_t sensorValue) {
  return static_cast<float>(sensorValue - minValue) / (maxValue - minValue);
}

void updateMinMaxValues(const uint16_t lineSensorValues[]) {
  for (int i = 0; i < numSensors; i++) {
    if (lineSensorValues[i] < minValue) {
      minValue = lineSensorValues[i];
    }
    if (lineSensorValues[i] > maxValue) {
      maxValue = lineSensorValues[i];
    }
  }
}

String mapSensorValuesToColor(const float normalizedSensorValue) {
  if (normalizedSensorValue >= outerWhiteMin && normalizedSensorValue <= outerWhiteMax) {
    return "White";
  } else if (normalizedSensorValue >= outerBlackMin && normalizedSensorValue <= outerBlackMax) {
    return "Black";
  } else if (normalizedSensorValue >= outerRedMin && normalizedSensorValue <= outerRedMax) {
    return "Red";
  } else if (normalizedSensorValue >= outerBrownMin && normalizedSensorValue <= outerBrownMax) {
    return "Brown";
  } else if (normalizedSensorValue >= outerGreenMin && normalizedSensorValue <= outerGreenMax) {
    return "Green";
  } else if (normalizedSensorValue >= outerGrayMin && normalizedSensorValue <= outerGrayMax) {
    return "Gray";
  } else {
    return "Unknown";
  }
}

String mapSensorValuesToColor(const float normalizedSensorValue1, const float normalizedSensorValue2, const float normalizedSensorValue3) {
  float averageValue = calculateAverage(normalizedSensorValue1, normalizedSensorValue2, normalizedSensorValue3);
  
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

float calculateAverage(const float value1, const float value2, const float value3) {
  return (value1 + value2 + value3) / 3.0;
}
