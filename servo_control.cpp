#include <Servo.h> 
#include "configuration.h"


float pos1;    // variable to store the servo position of servo 1
float pos2;    // variable to store the servo position of servo 2
float pos3;    // variable to store the servo position of servo 3
/*
pins variables for the three servos
*/


Servo servo1;  // create three servo objects for the three servos. 
Servo servo2;
Servo servo3;

bool firsttime=true;
void servosetup()
{
        if(firsttime){
	/*put in setup, initialises servos*/
	servo1.attach(PINSERVO1);  // attaches the servo on pin 9 to the servo object 1 
	servo2.attach(PINSERVO2);  // attaches the servo on pin 9 to the servo object 2
	servo3.attach(PINSERVO3);  // attaches the servo on pin 9 to the servo object 3
        firsttime=false;
}

}

void servoneutral(){
	servo2.write(90);
	servo3.write(90);
}

void servomove(int servonumber, float degree){
	/*function that moves a particular servo, input servo number and pos from 0-180 degrees that you want it to go to.

	*/
if (servonumber == 1){
	pos1 = (int) degree;
	servo1.write(pos1);
        delay(500);
}

else if (servonumber == 2){
	pos2 = (int) degree;
	servo2.write(pos2);
delay(500);

}

else if (servonumber == 3){
	pos3 = (int) degree;
	servo3.write(pos3);
delay(500);
}

}

