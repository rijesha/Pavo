#include <Servo.h> 
#include "configuration.h"


int pos1;    // variable to store the servo position of servo 1
int pos2;    // variable to store the servo position of servo 2
int pos3;    // variable to store the servo position of servo 3
/*
pins variables for the three servos
*/


Servo servo1;  // create three servo objects for the three servos. 
Servo servo2;
Servo servo3;


void servosetup()
{
	/*put in setup, initialises servos*/
	servo1.attach(PINSERVO1);  // attaches the servo on pin 9 to the servo object 1 
	servo2.attach(PINSERVO2);  // attaches the servo on pin 9 to the servo object 2
	servo3.attach(PINSERVO3);  // attaches the servo on pin 9 to the servo object 3
}

void servoneutral(){
	servo2.write(90);
	servo3.write(90);
}

void servomove(int servonumber, float degree){
	/*function that moves a particular servo, input servo number and pos from 0-180 degrees that you want it to go to.

	*/
  degree=(1000*degree/180)+1000;
if (servonumber == 1){
	pos1 = (int) degree;
	servo1.writeMicroseconds(pos1);
}

else if (servonumber == 2){
	pos2 = (int) degree;
	servo2.writeMicroseconds(pos2);

}

else if (servonumber == 3){
	pos3 = (int) degree;
	servo2.writeMicroseconds(pos3);
}

}

