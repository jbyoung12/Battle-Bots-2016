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

// moves robot forward for time t (in seconds)
void forwardMotorsForTime(int time) {
  forwardMotors();
  delay(time);
  stopMotors();
}

// runs both motors forward infinitely
void forwardMotors() {
  leftMotor.run(FORWARD);
  rightMotor.run(FORWARD);
}
// stops both motors
void stopMotors() {
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);
}
// sets speed of motors (input should be decimal referring to % of maxSpeed)
void setSpeedMotors(int m1Speed, int m2Speed) {
    leftMotor.setSpeed(motorMaxSpeed * m1Speed);
    rightMotor.setSpeed(motorMaxSpeed * m2Speed);
}

