#include <Zumo32U4.h>
#include <Wire.h>



Zumo32U4LineSensors lineSensors;
Zumo32U4ButtonA buttonA;
Zumo32U4Buzzer buzzer;

unsigned int lineSensorValues[3];

// calibrates the line sensors
void calibrateLineSensors(){

for(int i = 0; i < 400; i++){
lineSensors.calibrate();
}
}

  const char Tune[] PROGMEM =
  "! V8 L8 T120 O4 e58g58c68g58e58";

void setup() {
  lineSensors.initThreeSensors();
  lineSensors.emittersOn();
  Serial.begin(9600);
  buttonA.waitForButton();

  // plays a tune
  buzzer.playFromProgramSpace(Tune);

  calibrateLineSensors();  
}

void loop() {

// reads the line sensor values and prints them to the serial monitor
  lineSensors.read(lineSensorValues);
   for (uint8_t i = 0; i < 3; i++)
  {
    uint8_t value = map(lineSensorValues[i], 0, 2000, 0, 9);
    Serial.print(value);
    Serial.print(" ");
    if (value > 2){
     buzzer.playFromProgramSpace(Tune);


    }
  }
  Serial.println(" ");

  delay(1000);
}


