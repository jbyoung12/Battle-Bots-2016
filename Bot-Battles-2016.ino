void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initialMotorSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  forwardMotorsForTime(10);
}
