#include <Zumo32U4.h>
#include <Wire.h>

Zumo32U4LineSensors lineSensors;
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

const int numSensors = 5;
const int sensorMinValue = 0;
const int sensorMaxValue = 2000;

// Color thresholds for mapping sensor values to colors
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

void setup() {
  Serial.begin(9600);
  
  // Initialize line sensors
  lineSensors.initFiveSensors();

    buttonA.waitForButton();

  // Perform calibration
  calibrateLineSensors();
}

void loop() {
  // Read line sensor reflectance values
  uint16_t lineSensorValues[numSensors];
  lineSensors.read(lineSensorValues);
  
  // Map sensor values to colors
  String color1 = mapSensor1Color(lineSensorValues[0]);
  String color2 = mapSensor2Color(lineSensorValues[1]);
  String color3 = mapSensor3Color(lineSensorValues[2]);
  String color4 = mapSensor2Color(lineSensorValues[3]);
  String color5 = mapSensor1Color(lineSensorValues[4]);
  
  // Print the detected colors
  Serial.print("Sensor 1: ");
  Serial.println(color1);
  Serial.print("Sensor 2: ");
  Serial.println(color2);
  Serial.print("Sensor 3: ");
  Serial.println(color3);
  Serial.print("Sensor 4: ");
  Serial.println(color4);
  Serial.print("Sensor 5: ");
  Serial.println(color5);
  
  delay(1000); // Adjust the delay as per your requirements
}

String mapSensor1Color(const uint16_t sensorValue) {
  if (sensorValue >= outerWhiteMin && sensorValue <= outerWhiteMax) {
    return "White";
  } else if (sensorValue >= outerBrownMin && sensorValue <= outerBrownMax) {
    return "Brown";
  } else if (sensorValue >= outerGrayMin && sensorValue <= outerGrayMax) {
    return "Gray";
  } else {
    return "Unknown";
  }
}

String mapSensor2Color(const uint16_t sensorValue) {
  if (sensorValue >= midOutWhiteMin && sensorValue <= midOutWhiteMax) {
    return "White";
  } else if (sensorValue >= midOutBlackMin && sensorValue <= midOutBlackMax) {
    return "Black";
  } else if (sensorValue >= midOutGreenMin && sensorValue <= midOutGreenMax) {
    return "Green";
  } else {
    return "Unknown";
  }
}

String mapSensor3Color(const uint16_t sensorValue) {
  if (sensorValue >= middleWhiteMin && sensorValue <= middleWhiteMax) {
    return "White";
  } else if (sensorValue >= middleBlackMin && sensorValue <= middleBlackMax) {
    return "Black";
  } else if (sensorValue >= middleGreenMin && sensorValue <= middleGreenMax) {
    return "Green";
  } else {
    return "Unknown";
  }
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