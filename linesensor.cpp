#include <Zumo32U4.h>
#include <Wire.h>

Zumo32U4LineSensors lineSensors;
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

unsigned int lineSensorValues[3];

void calibrateLineSensors(){

for(int i = 0; i < 400; i++){
lineSensors.calibrate();
}
}

void setup() {
  lineSensors.initThreeSensors();
  lineSensors.emittersOn();
  Serial.begin(9600);
  buttonA.waitForButton();

  calibrateLineSensors();
}

void loop() {

  lineSensors.read(lineSensorValues);
   for (uint8_t i = 0; i < 3; i++)
  {
    uint8_t value = map(lineSensorValues[i], 0, 2000, 0, 9);
    Serial.print(value);
    Serial.print(" ");
  }
  Serial.println(" ");

  delay(1000);
}