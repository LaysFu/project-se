#include "LineFollower.h"

LineFollower::LineFollower() : gameOn(true){
  Serial.println("Linefollower created!");
}

void LineFollower::followLine() {
  bool goLeft = false;
  bool goRight = false;

  gyro.init(); // Initialize gyro

  while (gameOn) {
    rl.identifyColor(); // Identify sensor colors

    // if (rl.color1 == "Brown" || rl.color5 == "Brown" {
    //   gameOn = false;
    //   block.switchMode(); // Switch naar block mode
    //   break;
    // }

    if (rl.color0 == "Gray" && rl.color4 == "Gray") {
      pause = true; // pause until pitch is below zero
      continue;
    } else if (rl.color0 == "Gray") {
      goLeft = true; // turn left on next black line
    } else if (rl.color4 == "Gray") {
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
      if (rl.color0 == "Black") {
        turnLeft();
        goLeft = false;
      }
    } else if (goRight) {
      if (rl.color4 == "Black") {
        turnRight();
        goRight = false;
      }
    }

    updateOnGreenLine();

    int position = calculateLinePosition();

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

void LineFollower::updateOnGreenLine() {
  onGreenLine = (rl.color3 == "Green");
}

int LineFollower::calculateLinePosition() {
  int position = 0;
  int count = 0;
  if (rl.color1 == getColor()) {
    position += 0 * 1000;
    count++;
  }
  else if (rl.color2 == getColor()) {
    position += 1 * 1000;
    count++;
  }
  else if (rl.color3 == getColor()) {
    position += 2 * 1000;
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