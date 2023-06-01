#include <Arduino.h>
#include "readLine.h"
#include "Zumo32U4.h"

Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;

const int numSensors = 5;
  
void readLine::identifyColor() {
  uint16_t lineSensorValues[numSensors];
  lineSensors.read(lineSensorValues);

  readLine lineSensorColors(lineSensorValues);

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
