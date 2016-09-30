#include <Wire.h>
#include <float.h>
#include <math.h>
#include "Adafruit_Sensor.h"
#include "Adafruit_HMC5883_U.h"

// 3-axis Magnetometer (compass)
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

/*
   The current heading of the robot in degrees
*/
float read_heading() {

  sensors_event_t event;
  mag.getEvent(&event);

  float heading = atan2(event.magnetic.y, event.magnetic.x);

  // Correct for when signs are reversed.
  if (heading < 0) {
    heading += 2 * PI;
  }

  // Convert to degrees and return
  return heading * 180 / M_PI;
}

/*
   Filters the degree heading using a simple exponential filter.'
   Smooths out the value while still keeping the average age of the
   output components pretty recent.
*/
const float FILTER_ALPHA = 0.5;
float filterLastOutput;
bool headingFilterPrimed = false;
float filter_heading(float heading) {

  // First run
  if (!headingFilterPrimed) {
    headingFilterPrimed = true;
    filterLastOutput = heading;
    return heading;
  }

  // Update filter and return
  filterLastOutput = FILTER_ALPHA * heading + (1.0 - FILTER_ALPHA) * filterLastOutput;
  return filterLastOutput;
}

/*
   Angles from the magnetometer naturally wrap at 0 and 360 degrees.
   Unwrap these values to extend to >360 and <0 degrees so that we can
   safely apply filters and use the value for controls.
*/
float unwrapHeadingOffset = 0.0;
float unwrapLastHeading = 0.0;
bool unwrapHasBegun = false;

float unwrap_heading(float heading) {

  // First run
  if (!unwrapHasBegun) {
    unwrapHasBegun = true;
    unwrapLastHeading = heading;
    return heading;
  }

  // Possibly adjust offset
  if (unwrapLastHeading - heading < -180.0) {
    unwrapHeadingOffset -= 360.0;
  } else if (unwrapLastHeading - heading > 180.0) {
    unwrapHeadingOffset += 360.0;
  }
  unwrapLastHeading = heading;

  return heading + unwrapHeadingOffset;
}

/*
   Set and then later subtract the zero point of the heading based on a known
   angle at a given time, passed to set_heading_zero()
*/
float headingZero = 0.0;
float zero_heading(float heading) {
  return heading - headingZero;
}
float set_heading_zero(float currentReading, float knownHeading) {
  headingZero = currentReading - knownHeading;
}

void setupCompass() {
  // Initialize the magnetometer
  if (!mag.begin()) {
    Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
    while (1);
  }

  // Let transients die out, then zero the heading
  float heading, unwrapped, filtered;
  for (int i = 0; i < 10; i++) {
    heading = read_heading();
    unwrapped = unwrap_heading(heading);
    filtered = filter_heading(unwrapped);
  }
  set_heading_zero(filtered, 0.0);
}

float desiredHeading = 0.0;
int count = 0;
float compassCycle(){
 float heading = read_heading();
  float unwrapped = unwrap_heading(heading);
  float filtered = filter_heading(unwrapped);
  float zeroed = zero_heading(filtered);
   Serial.println(zeroed);

  count++;
  if (count == 5) {
    return zeroed;
    //Serial.print("Heading (degrees): "); Serial.println(zeroed);
    count = 0;
}

  return zeroed;

}

