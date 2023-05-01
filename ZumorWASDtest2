#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Buzzer buzzer;
Zumo32U4Motors motors;

const char crabRave[] PROGMEM =
  "! V10 O5 L8 T125 db-gg16dd16aff16dd16aff16ccee16f16e16"
  "db-gg16dd16aff16dd16aff16ccee16f16e16"
  "db-gg16dd16aff16dd16aff16ccee16f16e16"
  "db-gg16dd16aff16dd16aff16ccee16f16e16";

void setup()
{
  Serial.begin(9600); // serial connection
  buzzer.stopPlaying();
}

void loop()
{ 
  if (Serial.available() > 0) {
    char input = Serial.read(); // read input character from serial port
    switch (input) {
      case 'w': // forward
        motors.setLeftSpeed(200);
        motors.setRightSpeed(200);
        break;
      case 's': // backward
        motors.setLeftSpeed(-200);
        motors.setRightSpeed(-200);
        break;
      case 'a': // left
        motors.setLeftSpeed(-100);
        motors.setRightSpeed(100);
        break;
      case 'd': // right
        motors.setLeftSpeed(100);
        motors.setRightSpeed(-100);
        break;
      case 'f': // play music
            buzzer.playFromProgramSpace(crabRave);
            break;
      case 'e': // stop music
            buzzer.stopPlaying();
            break;
      default: // stop if invalid input received
        motors.setLeftSpeed(0);
        motors.setRightSpeed(0);
        break;
    }
  }
}