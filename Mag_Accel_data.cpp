#include <Wire.h>
#include <Adafruit_LSM303_U.h>
#include <Adafuit_9DOF.h>
#include <Adafuit_Simple_AHRS.h>
#include <Adafruit_L3GD20_U.h>
#include <Adafruit_Sensor.h>
#include <math.h>

Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(12345);
//accerleration values in m/s^2
float acellx;
float acelly;
float acellz;
//magnectic values in micro gauss
float magx;
float magy;
float magz;
/*direction in degrees 0-degreees=N, 180=S 90=E*/
float direc;


void initializeallvalues(void){
  delay(500);
  /*so much stuff I dont understand*/
  sensor_t sensor;
  mag.getSensor(&sensor);
  accel.getSensor(&sensor);
  sensors_event_t event; 
  accel.getEvent(&event);
  mag.getEvent(&event);
  /*initialisation of the magnectic and acceration values*/
 acellx=event.acceleration.x;
 acelly=event.acceleration.y;
 acellz=event.acceleration.z;
 magx=event.magnetic.x;
 magy=event.magnetic.y;
 magz=event.magnetic.z;
 /*calcualtion of direction based on the relative size of the the magx, magy values, 
 diregards magz at the moment, incorporate later
 */
 if(magy>=0){
   direc=90-atan(magx/magy)*(180/M_PI);
 
 }
 else if(magy<0){
   direc=270-atan(magx/magy)*(180/M_PI);
 }
}



void Mag_Accel_data(void) {
  /* Get a new sensor event */ 
  sensors_event_t event; 
  accel.getEvent(&event);
  mag.getEvent(&event);
  delay(1000);
 Serial.println("X ");Serial.print(acellx);Serial.print("  ");
 Serial.println("Y ");Serial.print(acelly);Serial.print("  ");
 Serial.println("Z ");Serial.print(acellz);Serial.print("  ");
 
 delay(500);
}
