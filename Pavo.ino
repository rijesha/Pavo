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





// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  GPSInitialization();
}

// the loop routine runs over and over again forever:
void loop() {
   
  float* IMUData;
   float acellx;
   float acelly;
   float acellz;
   float magx;
   float magy;
   float magz;
 
  float* GPSpos;
  float latitude;
  float longitude;
  float time;
  float date;
  float falt;
  
  float* IMUData = GPSData();
 
  acellx=*(IMUData);
  acelly=*(IMUData + 1);
  acellz=*(IMUData+2);
  magx=*(IMUData+3);
  magy=*(IMUData+4);
  magz=*(IMUData+5);
  
  float* GPSpos = GPSData();
 
  latitude=*(GPSpos);
  longitude=*(GPSpos + 1);
  time=*(GPSpos+2);
  date=*(GPSpos+3);
  falt=*(GPSpos+4);
}
