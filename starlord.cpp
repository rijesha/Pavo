#include <Servo.h>
#include "servo_control.h"
#include "configuration.h"
#include <arduino.h>


float earthFreq=0.004178066f/4; //Speed of Earth in deg/s


void starlord(float initangle)
{
  do{
  delay(250);
  servomove(3, initangle);
  initangle=initangle+earthFreq;
  }while(digitalRead(BUTTONPIN)==HIGH);
}
