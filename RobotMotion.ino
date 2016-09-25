#include <AFMotor.h>

// Objects (two motors)
AF_DCMotor leftMotor(1, MOTOR12_64KHZ);
AF_DCMotor rightMotor(2, MOTOR12_64KHZ);
const int motorMaxSpeed = 255;
const int stopDistance = 2;


// Set up initial speed of motors
void initialMotorSetup() {
  setSpeedMotors(1.0, 1.0);
}


// ----------------------- MOTOR CONTROLS ----------------------- //

// sets speed of motors (input should be decimal referring to % of maxSpeed)
void setSpeedMotors(int m1Speed, int m2Speed) {
  leftMotor.setSpeed(motorMaxSpeed * m1Speed);
  rightMotor.setSpeed(motorMaxSpeed * m2Speed);
}
// moves robot forward for time t (in ms)
void forwardRobotForTime(int t) {
  forwardBothMotors();
  delay(t * 1000);
=======
  delay(t);
}
void runBothMotorsForTime(int t) {
  runBothMotors();
  delay(t);
}

// stops both motors for certain time t (in ms)
void stopRobotForTime(int t) {
  stopBothMotors();
  delay(t * 1000);
=======
  delay(t);
}

void turnRobotLeftForDegrees(int d) {
  leftMotor.run(RELEASE);
  rightMotor.run(FORWARD);
}


// ----------------------- TEST FUNCTIONS ----------------------- //

// stops motors for a very long time
void stopRobot() {
  stopRobotForTime(100000);
}

// ----------------------- BASIC METHODS ----------------------- //

// (THESE SHOULD NOT BE CALLED BY THEMSELVES, ALWAYS USE WITH "ForTime" equivalent)
void stopBothMotors() {
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);
}
// runs both motors forward
void forwardBothMotors() {
  if (!checkStop())
  {
    leftMotor.run(FORWARD);
    rightMotor.run(FORWARD);
  }
}

boolean checkStop() {
  if (getDistance() <= stopDistance)
  {
    stopBothMotors();
    return true;
  }
  else
    return false;
  setSpeedMotors(1.0,1.0);
  leftMotor.run(FORWARD);
  rightMotor.run(FORWARD);
}
// runs both motors forward
void runBothMotors() {
  leftMotor.run(FORWARD);
  rightMotor.run(FORWARD);
}


