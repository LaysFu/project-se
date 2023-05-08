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

void loop(){ 
  if (Serial.available() > 0) {
    char input = Serial.read(); // read input character from serial port
    switch (input) {
      case 'w': // forward
        forward();
        break;
      case 's': // backward
        backward();
        break;
      case '1': // forward left
        left();
        break;
      case '2': // forward right
        right();
        break;
      case '3': // backward right
        bRight();
        break;
      case '4': // backward left
        bLeft();
        break;
      case 'f': // play music
            buzzer.playFromProgramSpace(crabRave);
            break;
      case 'e': // stop music
            buzzer.stopPlaying();
            break;
      default: 
            stop();
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
  motors.setSpeeds(50, 300);
}

void right() {
  motors.setSpeeds(300, 50);
}

void bLeft() {
  motors.setSpeeds(-50, -300);
}

void bRight() {
  motors.setSpeeds(-300, -50);
}

void stop() {
  motors.setSpeeds(0, 0);
}