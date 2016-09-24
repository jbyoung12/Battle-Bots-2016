#include <AFMotor.h>

// Objects
AF_DCMotor leftMotor(1, MOTOR12_64KHZ);
AF_DCMotor rightMotor(2, MOTOR12_64KHZ);
const int motorMaxSpeed = 255;

// Setup
void motorSetup() {
    leftMotor.setSpeed(motorMaxSpeed*.8);
    rightMotor.setSpeed(motorMaxSpeed*.8);
}


// Running motors
void runMotors() {
    leftMotor.run(FORWARD);
    rightMotor.run(FORWARD);
}

