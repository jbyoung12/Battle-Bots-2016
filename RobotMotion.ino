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
// moves robot forward for time t (in seconds)
void forwardRobotForTime(int t) {
  forwardBothMotors();
  delay(t*1000);
}
// stops both motors for certain time t (in seconds)
void stopRobotForTime(int t) {
  stopBothMotors();
  delay(t*1000);
}


// ----------------------- TEST FUNCTIONS ----------------------- //

// stops motors for a very long time
void stopMotors() {
  stopRobotForTime(100);
}

// ----------------------- BASIC METHODS ----------------------- //

// (THESE SHOULD NOT BE CALLED BY THEMSELVES, ALWAYS USE WITH "ForTime" equivalent)
void stopBothMotors() {
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);
}
// runs both motors forward
void forwardBothMotors() {
  leftMotor.run(FORWARD);
  rightMotor.run(FORWARD);
}


