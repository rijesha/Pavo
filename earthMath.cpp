#include <math.h>
#include "Mag_Accel_data.cpp"
#define pi 3.14159f
#include "servo_control.cpp"

void initservo(float latitude, float direc){
	/*runs once at start*/
	/*points the platform at magnectic north,
	change later to incorporate angle of declination*/
	
	if (latitude >= 0){
		if (direc<90 && direc >= 0){
			servomove(1, direc);
		}
		else if (direc<0 && direc>-90){
			int intmv = 0;
			intmv = abs(direc) + 90;
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
			intmv = abs(direc) + 90;
			servomove(1, intmv);
		}
		else if (latitude<0){

		}
	}
	/*initialise servo 2*/
	int abslat = 90 * sin(2 * pi*abs(latitude) / 180);

	servomove(2, abslat);

}
