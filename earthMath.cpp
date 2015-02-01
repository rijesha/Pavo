#include <math.h>
#include "servo_control.h"


float initflatten(float x, float y, float z){
/*initialise servo 2*/
float pitchangle;
float rollangle;

pitchangle=atan((x)/(pow(y,2)+pow(z,2))*.5);
rollangle=atan((y)/(pow(x,2)+pow(z,2))*.5);

pitchangle= (2 * M_PI / 180)*pitchangle + 90;
rollangle= (2 * M_PI / 180)*rollangle + 90;

servomove(2, pitchangle);
servomove(3, rollangle);

return pitchangle;

}

void initmagnetservo(float latitude, float direc){
	/*runs once at start*/
	/*points the platform at magnectic north,
	change later to incorporate angle of declination*/
	
	if (latitude >= 0){
		if (direc<90 && direc >= 0){
			servomove(1, direc);
		}
		else if (direc<0 && direc>-90){
			int intmv = 0;
			intmv = fabs(direc) + 90;
			servomove(1, intmv);
		}
		else if (latitude<0){

		}
	}
	else if (latitude < 0){
		float newdirac = 180 - direc;
		if (direc<90 && direc >= 0){
			servomove(1, direc);
		}
		else if (direc<0 && direc>-90){
			int intmv = 0;
			intmv = fabs(direc) + 90;
			servomove(1, intmv);
		}
		else if (latitude<0){

		}
	}

}

void initdeclination(float x, float y, float z, float lats){
  servomove(2, 0);
  servomove(3, 0);
  //need to take measurement here again
  float originalpitch;
  float newpitch;
  originalpitch = initflatten(x,y,z);
  lats = (2 * M_PI / 180)*lats;
  
  newpitch = 90*sin(lats) - originalpitch;
  servomove(2, newpitch);
  
}

