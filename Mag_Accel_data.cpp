#include <Wire.h>
#include <Adafruit_LSM303_U.h>
#include <Adafuit_9DOF.h>
#include <Adafuit_Simple_AHRS.h>
#include <Adafruit_L3GD20_U.h>
#include <Adafruit_Sensor.h>
#include <math.h>

Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(12345);

/*direction in degrees 0-degreees=N, 180=S 90=E*/
float direc;

void initiallizeIMU(){
if(!accel.begin())
  {
    while(1);
  }
  if(!mag.begin())
  {
    while(1);
  }
}

float* IMUData(){
  delay(500);
  float IMUdata[7];
  /*so much stuff I dont understand*/
  sensor_t sensor;
  mag.getSensor(&sensor);
  accel.getSensor(&sensor);
  sensors_event_t event; 
  accel.getEvent(&event);
  mag.getEvent(&event);
  /*initialisation of the magnectic and acceration values*/
 IMUdata[0]=event.acceleration.x;
 IMUdata[1]=event.acceleration.y;
 IMUdata[2]=event.acceleration.z;
 IMUdata[3]=event.magnetic.x;
 IMUdata[4]=event.magnetic.y;
 IMUdata[5]=event.magnetic.z;
 /*calcualtion of direction based on the relative size of the the magx, magy values, 
 diregards magz at the moment, incorporate later
 */
 if(IMUdata[4]>=0){
   direc=90-atan(IMUdata[3]/IMUdata[4])*(180/M_PI);
 
 }
 else if (IMUdata[4]<0){
   direc=270-atan(IMUdata[3]/IMUdata[4])*(180/M_PI);
 }
 IMUdata[6]=direc;
 return IMUdata;
}
