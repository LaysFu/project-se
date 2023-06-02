#include <Arduino.h>
#include "readLine.h"
#include "Zumo32U4.h"

Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;

String sensorColors[5]; // 5 sensors

readLine::readLine(int sensorValues) {
  lineSensorValues = sensorValues;
}

const int numSensors = 5;
  
void readLine::identifyColor() {

  int lineSensorValues[numSensors];
  lineSensors.read(lineSensorValues);

  lineSensorColors(lineSensorValues);

  sensorColors[0] = lineSensorColors.getColor1();
  sensorColors[1] = lineSensorColors.getColor2();
  sensorColors[2] = lineSensorColors.getColor3();
  sensorColors[3] = lineSensorColors.getColor4();
  sensorColors[4] = lineSensorColors.getColor5();

  Serial.print("Sensor Left: ");
  Serial.println(lineSensorColors.getColor1());
  Serial.print("Sensor MidL: ");
  Serial.println(lineSensorColors.getColor2());
  Serial.print("Sensor Mid: ");
  Serial.println(lineSensorColors.getColor3());
  Serial.print("Sensor MidR: ");
  Serial.println(lineSensorColors.getColor4());
  Serial.print("Sensor Right: ");
  Serial.println(lineSensorColors.getColor5());

  delay(1000);
}

void readLine::calibrateLineSensors() {
  delay(1000);
  for (uint16_t i = 0; i < 120; i++) {
    if (i > 30 && i <= 90) {
      motors.setSpeeds(-200, 200);
    } else {
      motors.setSpeeds(200, -200);
    }
    lineSensors.calibrate();
  }
  motors.setSpeeds(0, 0);
}

String* readLine::getSensorColors() {
  return sensorColors;
}