#include <AFMotor.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initialMotorSetup();
  setupSonar();
  setupCompass();
}

void loop() {
  //  forwardRobotForTime(5);
  //  stopRobotForTime(2);
  forwardBothMotors();
  sonarCyle();

  //compassCycle();  
}
