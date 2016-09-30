#include <AFMotor.h>

// Objects (two motors)
AF_DCMotor leftMotor(1, MOTOR12_64KHZ);
AF_DCMotor rightMotor(2, MOTOR12_64KHZ);
//const int motorMaxSpeed = (255*.7); //use with battery pack
const int motorMaxSpeed = (255); //use with comp

const int stopDistance = 2;


// Set up initial speed of motors
void initialMotorSetup() {
  setSpeedMotors(1.0, 1.0);
}


// ----------------------- MOTOR CONTROLS ----------------------- //

// sets speed of motors (input should be decimal referring to % of maxSpeed)
void setSpeedMotors(int m1Speed, int m2Speed) {
  leftMotor.setSpeed(motorMaxSpeed * m1Speed);
  rightMotor.setSpeed(motorMaxSpeed * m2Speed*.95);
}

// runs robot forward until it senses something in front of it
void runRobotForward() {
  //if (!avoidObstacle()) {
    setSpeedMotors(1.0, 1.0);
    runBothMotorsForward();
 // }
}
void runRobotBackwards() {
  setSpeedMotors(1.0, 1.0);
  runBothMotorsBackwards();
}

// turning robot
void turnRobotLeftForDegrees(int d) {
  setSpeedMotors(0.0, 1.0);
  runBothMotorsForward();
  delay(d);
}

void spinTurnRight(int d) {
  setSpeedMotors(1.0, 1.0);
  leftMotor.run(FORWARD);
  rightMotor.run(BACKWARD);
  delay(d);
  stopBothMotors();
}

void spinTurnLeft(int d) {
  setSpeedMotors(1.0, 1.0);
  leftMotor.run(BACKWARD);
  rightMotor.run(FORWARD);
  delay(d);
  stopBothMotors();
  setSpeedMotors(1.0, 1.0);
}
bool avoidObstacle() {
  if (getDistance() <= stopDistance) {
    turnRobotLeftForDegrees(90);
    return true;
  }
  else if (getLineReaderRight() < 700) {
    spinTurnRight(1500);
  }
  else {
    return false;
  }
}

//turning with compass
void turnToDegree(int targetReading) {
  float currentReading = compassCycle();
  while (!(currentReading > targetReading - 5 && currentReading < targetReading + 5))
  {
    if (compassCycle() < targetReading) {
      spinTurnRight(10);
    }
    else {
      spinTurnLeft(10);
    }
    currentReading = compassCycle();
  }
}



// ----------------------- TEST FUNCTIONS ----------------------- //


// moves robot forward for time t (in ms)
void forwardRobotForTime(int t) {
  setSpeedMotors(1.0, 1.0);
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
  leftMotor.run(BACKWARD);
  rightMotor.run(BACKWARD);
}
void stopBothMotors() {
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);
}






