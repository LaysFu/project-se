#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Buzzer buzzer;
Zumo32U4Motors motors;

const char crabRave[] PROGMEM = // load crab rave song into program space
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
        forward();
        break;
      case 's': // backward
        backward();
        break;
      case 'a': // left
        left();
        break;
      case 'd': // right
        right();
        break;
      case 'f': // play music
        buzzer.playFromProgramSpace(crabRave);
        break;
      case 'e': // stop music
        buzzer.stopPlaying();
        break;
      default: // stop if invalid input received
        stop();
        break;
    }
  }
}

void forward() {
  motors.setSpeeds(200, 200);
}

void backward() {
  motors.setSpeeds(-200, -200);
}

void left() {
  motors.setSpeeds(-100, 100)
}

void right() {
  motors.setSpeeds(100, -100);
}

void stop() {
  motors.setSpeeds(0, 0);
}