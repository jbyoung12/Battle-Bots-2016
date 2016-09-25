#include <AFMotor.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initialMotorSetup();
  setupSonar();
  setupCompass();
  setupArmMotion();
}

void loop() {
  //  stopRobotForTime(2);
  runRobotForward();
  sonarCyle();
  Serial.println(getLineReaderRight());
  //compassCycle();
  //runServo();
  turnToDegree(0);
}
