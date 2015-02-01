#include "servo_control.h"
#include "configuration.h"
#include "SoftwareSerial.h"
#include <Servo.h> 

void setup()
{
 Serial.begin(115200);
  Serial.println(F("Adafruit 9DOF Tester")); Serial.println("");
  servosetup();
}

int something=180;
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
  Serial.println("something");
  
  servoneutral();
}
