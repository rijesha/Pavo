#include <Servo.h>
#include "servo_control.h"
#include "configuration.h"
#include <arduino.h>


float earthFreq=0.004178066f/4; //Speed of Earth in deg/s divided by 4


void starlord(float initangle)
{
  float angle=initangle;
  do{
  delay(250);
  servomove(3, angle);
  angle=angle+earthFreq+30;
  }while(digitalRead(BUTTONPIN)==HIGH);
  for(int i=1;i<(angle-initangle)/10.; i++){
    servomove(3, angle-10*i);
  }
}
