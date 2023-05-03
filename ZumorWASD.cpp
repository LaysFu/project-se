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

bool fState = false; // forward
bool bState = false; // backward
bool lState = false; // left
bool rState = false; // right

void loop()
{ 
  if (Serial.available() > 0) {
    char input = Serial.read(); // read input character from serial port
    switch (input) {
      case 'w': // forward
        fState = true;
        break;
      case 's': // backward
        bState = true;
        break;
      case 'a': // left
        lState = true;
        break;
      case 'd': // right
        rState = true;
        break;
      case 'rw': // forward release
        fState = false;
        break;
      case 'rs': // backward release
        bState = false;
        break;
      case 'ra': // left release
        lState = false;
        break;
      case 'rd': // right release
        rState = false;
        break;
      case 'f': // play music
            buzzer.playFromProgramSpace(crabRave);
            break;
      case 'e': // stop music
            buzzer.stopPlaying();
            break;
    }
    
    // call functie afhankelijk van input
    if (forwardState && !backwardState && !leftState && !rightState) {
      forward();
    } else if (backwardState && !forwardState && !leftState && !rightState) {
      backward();
    } else if (leftState && !rightState) {
      left();
    } else if (rightState && !leftState) {
      right();
    } else if (leftState && backwardState && !rightState && !forwardState) {
      bLeft();
    } else if (rightState && backwardState && !leftState && !forwardState) {
      bRight();
    } else { // stop als er geen input is
      stop();
    }
  }
}

void forward() {
  motors.setLeftSpeed(200);
  motors.setRightSpeed(200);
}

void backward() {
  motors.setLeftSpeed(-200);
  motors.setRightSpeed(-200);
}

void left() {
  motors.setLeftSpeed(50);
  motors.setRightSpeed(200);
}

void right() {
  motors.setLeftSpeed(200);
  motors.setRightSpeed(50);
}

void bLeft() {
  motors.setLeftSpeed(-50);
  motors.setRightSpeed(-200);
}

void bRight() {
  motors.setLeftSpeed(-200);
  motors.setRightSpeed(-50);
}

void stop() {
  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);
}