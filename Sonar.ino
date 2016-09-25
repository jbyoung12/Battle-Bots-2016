#define echoPin 30 // Echo Pin
#define trigPin 31 // Trigger Pin
#define LEDPin 13 // Onboard LED

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance
int runningAverage[10]; //used to smooth out wierdness
int replacementIndex = 0;



void setupSonar() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
  setUpAverage();
}



long getDistance() {
  int average;
  for (int i = 0; i < 10; i++)
  {
    average  = average + runningAverage[i];
  }
  average = average / 10;
  return average;
}

void setUpAverage()
{
  for (int i = 0; i < 10; i = i + 1)
  {
    runningAverage[i] = 0;
  }
}
void sonarCyle() {
  /* The following trigPin/echoPin cycle is used to determine the
    distance of the nearest object by bouncing soundwaves off of it. */
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH, 40000);

  //Calculate the distance (in cm) based on the speed of sound.

  distance = duration / 58.2;

   
  if (distance == 0)
  {
    distance = stopDistance + 1;
  }
  
  runningAverage[replacementIndex] = distance;
  
  if (replacementIndex < 9)
  {
    replacementIndex = replacementIndex + 1;
  }
  else
  {
    replacementIndex = 0;
  }


  if (distance >= maximumRange || distance <= minimumRange) {
    /* Send a negative number to computer and Turn LED ON
      to indicate "out of range" */
    Serial.print("-1: ");
    Serial.println(distance);
    digitalWrite(LEDPin, HIGH);
  }
  else {
    /* Send the distance to the computer using Serial protocol, and
      turn LED OFF to indicate successful reading. */
    //Serial.println(distance);
    Serial.println(distance);
    digitalWrite(LEDPin, LOW);
  }


}

