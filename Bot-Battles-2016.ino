#include <AFMotor.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initialMotorSetup();
}

void loop() {
  forwardRobotForTime(5);
  stopRobotForTime(2);
}
