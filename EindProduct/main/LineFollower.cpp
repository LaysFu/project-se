#include "LineFollower.h"
#include <Zumo32U4.h>
#include <Wire.h>

void LineFollower::followLine(readLine& rl) {
  bool goLeft = false;
  bool goRight = false;

  gyro.init(); // Initialize gyro

  while (true) {
    rl.identifyColor(); // Identify sensor colors

    // if (isBrownLineDetected(rl)) {
    //   block.switchMode(); // Switch naar block mode
    //   break;
    // }

    if (isGrayLinesDetected(rl)) {
      pause = true; // pause until pitch is below zero
      continue;
    } else if (rl.color1 == "Gray") {
      goLeft = true; // turn left on next black line
    } else if (rl.color5 == "Gray") {
      goRight = true; // turn right on next black line
    }

    if (pause) {
      if (isPitchBelowZero()) {
        pause = false;
      } else {
        pauseMovement();
        continue;
      }
    }

    if (goLeft) {
      if (rl.color1 == "Black") {
        turnLeft();
        goLeft = false;
      }
    } else if (goRight) {
      if (rl.color5 == "Black") {
        turnRight();
        goRight = false;
      }
    }

    updateOnGreenLine(rl);

    int position = calculateLinePosition(rl);

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

bool LineFollower::isBrownLineDetected(readLine& rl) {
  return (rl.color1 == "Brown" || rl.color5 == "Brown");
}

bool LineFollower::isGrayLinesDetected(readLine& rl) {
  return (rl.color1 == "Gray" && rl.color5 == "Gray");
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

void LineFollower::updateOnGreenLine(readLine& rl) {
  onGreenLine = (rl.color3 == "Green");
}

int LineFollower::calculateLinePosition(readLine& rl) {
  int position = 0;
  int count = 1;
  if (rl.color3 == getColor()) {
      position += count * 1000;
      count++;
    }
  if (count > 0) {
    position /= count;
  } else {
    position = 2000; // Center of line
  }
  return position;
}

String LineFollower::getColor() {
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