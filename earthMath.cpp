#include <math.h>

void initservo(){
	/*runs once at start*/
	/*points the platform at magnectic north,
	change later to incorporate angle of declination*/
	initializeallvalues();
	if (lat >= 0){
		if (direc<90 && direc >= 0){
			servomove(1, direc);
		}
		else if (direc<0 && direc>-90){
			int intmv = 0;
			intmv = abs(direc) + 90;
			servomove(1, intmv);
		}
		else if (lat<0){

		}
	}
	else if (lat < 0){
		float newdirac = 180 - dirac;
		if (direc<90 && direc >= 0){
			servomove(1, direc);
		}
		else if (direc<0 && direc>-90){
			int intmv = 0;
			intmv = abs(direc) + 90;
			servomove(1, intmv);
		}
		else if (lat<0){

		}
	}
	/*initialise servo 2*/
	int abslat = 90 * sin(2 * pi*abs(lat) / 180);

	servomove(2, abslat);

}
