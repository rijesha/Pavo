#include "servo_control.h"
#include "configuration.h"
#include <Servo.h> 

void setup()
{
  servosetup();
}

int something=1800;
void loop()
{
  servomove(1,something);
  something=something-25;
  delay(1000);
  servomove(2,something);
  something=something-25;
  delay(1000);
  servomove(3,something); 
  something=something-25;
}
