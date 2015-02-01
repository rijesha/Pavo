#include <Wire.h>
#include <Adafruit_LSM303_U.h>
#include <Adafuit_9DOF.h>
#include <Adafuit_Simple_AHRS.h>
#include <Adafruit_L3GD20_U.h>
#include <Adafruit_Sensor.h>

Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(12345);

float acellx;
float acelly;
float acellz;
float magx;
float magy;
float magz;

void initializeallvalues(void){
  delay(500);
  sensor_t sensor;
  mag.getSensor(&sensor);
  accel.getSensor(&sensor);
  sensors_event_t event; 
  accel.getEvent(&event);
  mag.getEvent(&event);
 acellx=event.acceleration.x;
 acelly=event.acceleration.y;
 acellz=event.acceleration.z;
 magx=event.magnetic.x;
 magy=event.magnetic.y;
 magz=event.magnetic.z;
}

void setup(void) {                
  Serial.begin(9600);
      
}



void loop(void) {
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
