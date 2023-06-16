#include <Zumo32U4.h>
#include <Wire.h>


Zumo32U4LineSensors lineSensors;
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

const int numSensors = 5;
uint16_t sensorMin[numSensors];
uint16_t sensorMax[numSensors];

void setup()
{
  Serial.begin(9600);
  
  // Initialize line sensors
  lineSensors.initFiveSensors();

  buttonA.waitForButton();

  // Perform calibration
  calibrateLineSensors();
}

void loop()
{
  // Read line sensor reflectance values
  uint16_t lineSensorValues[numSensors];
  lineSensors.read(lineSensorValues);

  // Send reflectance values to the terminal via XBee
  for (int i = 0; i < numSensors; i++) {
    Serial.print("Line Sensor ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(lineSensorValues[i]);
  }

  delay(1000);  // Adjust the delay as per your requirements
}

void calibrateLineSensors()
{

  // Wait 1 second and then begin automatic sensor calibration
  // by rotating in place to sweep the sensors over the line
  delay(1000);
  for(uint16_t i = 0; i < 120; i++)
  {
    if (i > 30 && i <= 90)
    {
      motors.setSpeeds(-200, 200);
    }
    else
    {
      motors.setSpeeds(200, -200);
    }

    lineSensors.calibrate();
  }
  motors.setSpeeds(0, 0);

}
