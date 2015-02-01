#include <math.h>
#include "earthMath.h"
#include "servo_control.h"
#include "Mag_Accel_data.h"
#include "GPSin.h"


void completegeographicinitiallization(){
	float dummy;
	float* IMUpos = IMUData();
	float* GPSpos = GPSData();
	
	// acellx = *(IMUpos);
	// acelly=*(IMUpos + 1);
	// acellz=*(IMUpos+2);
	// magx=*(IMUpos+3);
	// magy=*(IMUpos+4);
	// magz=*(IMUpos+5);
	// compasshead=*(IMUpos+6);

	// latitude=*(GPSpos);
	// longitude=*(GPSpos + 1);
	// time=*(GPSpos+2);
	// date=*(GPSpos+3);
	// falt=*(GPSpos+4);
	
	IMUpos = IMUData();
	dummy = initflatten(*(IMUpos), *(IMUpos + 1), *(IMUpos + 2));
	initmagnetservo(*(GPSpos), *(IMUpos + 6));
	void servoneutral();
	IMUpos = IMUData();
	initdeclination(*(IMUpos), *(IMUpos + 1), *(IMUpos + 2), *(GPSpos));

}

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
  float originalpitch;
  float newpitch;
  originalpitch = initflatten(x,y,z);
  lats = (2 * M_PI / 180)*lats;
  
  newpitch = 90*sin(lats) - originalpitch;
  servomove(2, newpitch);
  
}

