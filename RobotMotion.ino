#include <AFMotor.h>

// Objects (two motors)
AF_DCMotor leftMotor(1, MOTOR12_64KHZ);
AF_DCMotor rightMotor(2, MOTOR12_64KHZ);
const int motorMaxSpeed = 255;


// Set up initial speed of motors
void initialMotorSetup() {
    setSpeedMotors(1.0,1.0);
}


// ----------------------- MOTOR CONTROLS ----------------------- //

// sets speed of motors (input should be decimal referring to % of maxSpeed)
void setSpeedMotors(int m1Speed, int m2Speed) {
    leftMotor.setSpeed(motorMaxSpeed * m1Speed);
    rightMotor.setSpeed(motorMaxSpeed * m2Speed);
}

void runRobotForward() {
  if (!checkStop()) {
    setSpeedMotors(1.0,1.0);
    runBothMotorsForward();
  }
}
void runRobotBackwards() {
  setSpeedMotors(1.0,1.0);
  runBothMotorsBackwards(); 
}

void turnRobotLeftForDegrees(int d) {
  setSpeedMotors(0.0,1.0);
  runBothMotorsForward();
  delay(d);
}

bool checkStop() {
  if (getDistance() <= 2) {
    turnRobotLeftForDegrees(90);
    return true;
  }
  else {
    return false;
  }
}

// ----------------------- TEST FUNCTIONS ----------------------- //


// moves robot forward for time t (in ms)
void forwardRobotForTime(int t) {
  setSpeedMotors(1.0,1.0);
  runBothMotorsForwardForTime(t);
}

// runs both motors at whatever speeds they're set at
void runBothMotorsForwardForTime(int t) {
  runBothMotorsForward();
  delay(t);
}

// stops both motors for certain time t (in ms)
void stopRobotForTime(int t) {
  stopBothMotors();
  delay(t);
}

// ----------------------- BASIC METHODS ----------------------- //

// (THESE SHOULD NOT BE CALLED BY THEMSELVES, ALWAYS USE WITH "ForTime" equivalent)

void runBothMotorsForward() {
  leftMotor.run(FORWARD);
  rightMotor.run(FORWARD);
}
void runBothMotorsBackwards() {
  leftMotor.run(FORWARD);
  rightMotor.run(FORWARD);
}
void stopBothMotors() {
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);
}



