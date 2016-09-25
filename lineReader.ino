int leftSensor = 14; 
int rightSensor = 15;


//990 ish is in bounds
//line is ~620

int getLineReaderRight(){
  int val = analogRead(rightSensor);
  return val;
}

int getLineReaderLeft(){
  int val = analogRead(leftSensor);
  return val;
}

