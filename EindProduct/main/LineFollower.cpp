#include "LineFollower.h"
#include <Zumo32U4.h>
#include <Wire.h>

void LineFollower::followLine() {
  bool turnLeft = false;
  bool turnRight = false;

  gyro.init(); // Initialize gyro

  while (true) {
    readline.identifyColor();
    String* sensorColors = readline.getSensorColors(); // Update sensor color values

    // if (isBrownLineDetected(sensorColors)) {
    //   block.switchMode(); // Switch naar block mode
    //   break;
    // }

    if (isGrayLinesDetected(sensorColors)) {
      pause = true; // pause until pitch is below zero
      continue;
    } else if (sensorColors[0] == "Gray") {
      turnLeft = true; // turn left on next black line
    } else if (sensorColors[4] == "Gray") {
      turnRight = true; // turn right on next black line
    }

    if (pause) {
      if (isPitchBelowZero()) {
        pause = false;
      } else {
        pauseMovement();
        continue;
      }
    }

    if (turnLeft) {
      if (sensorColors[0] == "Black") {
        turnLeft();
        turnLeft = false;
      }
    } else if (turnRight) {
      if (sensorColors[4] == "Black") {
        turnRight();
        turnRight = false;
      }
    }

    updateOnGreenLine(sensorColors);

    int position = calculateLinePosition(sensorColors);

    int error = position - 2000;

    int leftSpeed, rightSpeed;
    if (onGreenLine) {
      leftSpeed = maxSpeed / 2 + calculateSpeedDifference(error);
      rightSpeed = maxSpeed / 2 - calculateSpeedDifference(error);
    } else {
      leftSpeed = maxSpeed + calculateSpeedDifference(error);
      rightSpeed = maxSpeed - calculateSpeedDifference(error);
    }

    setMotorSpeeds(leftSpeed, rightSpeed);
  }
}

bool LineFollower::isBrownLineDetected(sensorColors) {
  return (sensorColors[0] == "Brown" || sensorColors[4] == "Brown");
}

bool LineFollower::isGrayLinesDetected(sensorColors) {
  return (sensorColors[0] == "Gray" && sensorColors[4] == "Gray");
}

bool LineFollower::isPitchBelowZero() {
  double pitch = gyro.calculatePitch();
  return (pitch < 0);
}

void LineFollower::pauseMovement() {
  motors.setSpeeds(0, 0); // Pause movement
}

void LineFollower::turnLeft() {
  leftSpeed = 0;
  rightSpeed = maxSpeed;
  delay(200);
}

void LineFollower::turnRight() {
  leftSpeed = maxSpeed;
  rightSpeed = 0;
  delay(200);
}

void LineFollower::updateOnGreenLine(sensorColors) {
  onGreenLine = (sensorColors[2] == "Green");
}

int LineFollower::calculateLinePosition(sensorColors) {
  int position = 0;
  int count = 0;
  for (int i = 0; i < 3; i++) {
    if (sensorColors[i] == getColor()) {
      position += i * 1000;
      count++;
    }
  }
  if (count > 0) {
    position /= count;
  } else {
    position = 2000; // Center of line
  }
  return position;
}

void LineFollower::getColor() {
  return (onGreenLine ? "Green" : "Black");
}

int LineFollower::calculateSpeedDifference(int error) {
  return error / 4 + 6 * (error - lastError);
}

void LineFollower::setMotorSpeeds(int leftSpeed, int rightSpeed) {
  leftSpeed = constrain(leftSpeed, 0, maxSpeed);
  rightSpeed = constrain(rightSpeed, 0, maxSpeed);
  motors.setSpeeds(leftSpeed, rightSpeed);
}