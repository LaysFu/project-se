#include "LineFollower.h"
#include <Zumo32U4.h>
#include <Wire.h>

void LineFollower::followLine() {
  bool turnLeft = false;
  bool turnRight = false;

  gyro.init(); // Initialize gyro

  while (true) {
    Color lineSensorValues[5];
    readline.readLine(lineSensorValues); // Update sensor color values

    if (isBrownLineDetected(lineSensorValues)) {
      block.switchMode(); // Switch naar block mode
      break;
    }

    if (isGrayLinesDetected(lineSensorValues)) {
      pauseMovement = true; // pause until pitch is below zero
      continue;
    } else if (lineSensorValues[0] == Color::Gray) {
      turnLeft = true; // turn left on next black line
    } else if (lineSensorValues[4] == Color::Gray) {
      turnRight = true; // turn right on next black line
    }

    if (pauseMovement) {
      if (isPitchBelowZero()) {
        pauseMovement = false;
      } else {
        pauseMovement();
        continue;
      }
    }

    if (turnLeft) {
      if (lineSensorValues[0] == Color::Black) {
        turnLeft();
        turnLeft = false;
      }
    } else if (turnRight) {
      if (lineSensorValues[4] == Color::Black) {
        turnRight();
        turnRight = false;
      }
    }

    updateOnGreenLine(lineSensorValues);

    int position = calculateLinePosition(lineSensorValues);

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

bool LineFollower::isBrownLineDetected(Color lineSensorValues[5]) {
  return (lineSensorValues[0] == Color::Brown || lineSensorValues[4] == Color::Brown);
}

bool LineFollower::isGrayLinesDetected(Color lineSensorValues[5]) {
  return (lineSensorValues[0] == Color::Gray && lineSensorValues[4] == Color::Gray);
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

void LineFollower::updateOnGreenLine(Color lineSensorValues[5]) {
  onGreenLine = (lineSensorValues[2] == Color::Green);
}

int LineFollower::calculateLinePosition(Color lineSensorValues[5]) {
  int position = 0;
  int count = 0;
  for (int i = 0; i < 3; i++) {
    if (lineSensorValues[i] == getColor()) {
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
  return (onGreenLine ? Color::Green : Color::Black);
}

int LineFollower::calculateSpeedDifference(int error) {
  return error / 4 + 6 * (error - lastError);
}

void LineFollower::setMotorSpeeds(int leftSpeed, int rightSpeed) {
  leftSpeed = constrain(leftSpeed, 0, maxSpeed);
  rightSpeed = constrain(rightSpeed, 0, maxSpeed);
  motors.setSpeeds(leftSpeed, rightSpeed);
}