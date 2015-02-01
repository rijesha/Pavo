#include <Servo.h>
#include "servo_control.h"
#include "configuration.h"

void setup()
{
  servosetup();
}

float earthFreq=0.004178066f; //Speed of Earth in deg/s

void loop()
{
  delay(1000);
  servomove(3, earthFreq);
}
