#include <Wire.h>
#include <Adafruit_LSM303_U.h>
#include <Adafuit_9DOF.h>
#include <Adafuit_Simple_AHRS.h>
#include <Adafruit_L3GD20_U.h>
#include <Adafruit_Sensor.h>
#include <TinyGPS.h>
#include <SoftwareSerial.h>
#include <Servo.h> 
#include "Mag_Accel_data.h"
#include "GPSin.h"
#include "configuration.h"
#include "servo_control.h"
#include "earthMath.h"




// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  GPSInitialization();
  servosetup();
}

// the loop routine runs over and over again forever:
void loop() {
   

   float acellx;
   float acelly;
   float acellz;
   float magx;
   float magy;
   float magz;
   float compasshead;
  

  float latitude;
  float longitude;
  float time;
  float date;
  float falt;
  
  
  float pitchangle;
  
  float* IMUpos = IMUData();
 
  acellx=*(IMUpos);
  acelly=*(IMUpos + 1);
  acellz=*(IMUpos+2);
  magx=*(IMUpos+3);
  magy=*(IMUpos+4);
  magz=*(IMUpos+5);
  compasshead=*(IMUpos+5);
  
  float* GPSpos = GPSData();
 
  latitude=*(GPSpos);
  longitude=*(GPSpos + 1);
  time=*(GPSpos+2);
  date=*(GPSpos+3);
  falt=*(GPSpos+4);
 
 //earthmath with falt, magx accelx, eccely etz
 
 pitchangle = initflatten(acellx, acelly, acellz);
 initmagnetservo(latitude, compasshead);
 
  IMUpos = IMUData();
 
  acellx=*(IMUpos);
  acelly=*(IMUpos + 1);
  acellz=*(IMUpos+2);
  magx=*(IMUpos+3);
  magy=*(IMUpos+4);
  magz=*(IMUpos+5);
 
 initdeclination(acellx, acelly, acellz, latitude);
 
 
 
 
 //starlord
  
  
  
}
