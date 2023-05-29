#include <Wire.h>
#include <Zumo32U4.h>

class CrabRaveSong {
public:
  CrabRaveSong() {}
  static const char song[] PROGMEM;
};

const char CrabRaveSong::song[] PROGMEM =
  "! V10 O5 L8 T125" 
  "db-gg16dd16aff16dd16aff16ccee16f16e16"
  "db-gg16dd16aff16dd16aff16ccee16f16e16"
  "db-gg16dd16aff16dd16aff16ccee16f16e16"
  "db-gg16dd16aff16dd16aff16ccee16f16e16";

class ZumoMotors {
private:
  Zumo32U4Buzzer buzzer;
  Zumo32U4Motors motors;

public:
  ZumoMotors() {}
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

  void playSong() {
    buzzer.playFromProgramSpace(CrabRaveSong::song);
  }

  void stopSong() {
    buzzer.stopPlaying();
  }
};

class Controller {
private:
  ZumoMotors control;

public:
  Controller() {}

  void controller() {
    if (Serial.available() > 0) {
      char input = Serial.read();
      switch (input) {
        case 'w':
          control.forward();
          break;
        case 's':
          control.backward();
          break;
        case '1': // forward left
          control.left();
          break;
        case '2': // forward rights
          control.right();
          break;
        case '3': // backward right
          control.bRight();
          break;
        case '4': // backward left
          control.bLeft();
          break;
        case 'f':
          control.playSong();
          break;
        case 'e':
          control.stopSong();
          break;
        default:
          control.stop();
      }
    }
  }
};

Controller controller;
ZumoMotors motors;

void setup() {
  Serial.begin(9600);
}

void loop() {
  controller.controller();
}