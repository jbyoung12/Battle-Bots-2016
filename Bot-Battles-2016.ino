#include <AFMotor.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initialMotorSetup();
}

void loop() {
  forwardRobotForTime(1000);
  stopRobotForTime(1000);
  turnRobotLeftForDegrees(90);
  delay(1500);
}
