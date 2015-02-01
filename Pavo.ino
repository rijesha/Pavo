#include <Wire.h>
#include <Adafruit_LSM303_U.h>
#include <Adafuit_9DOF.h>
#include <Adafuit_Simple_AHRS.h>
#include <Adafruit_L3GD20_U.h>
#include <Adafruit_Sensor.h>
#include <TinyGPS.h>
#include <SoftwareSerial.h>
#include <Servo.h> 
#include "configuration.h"
#include "servo_control.h"
#include "earthMath.h"
#include "Mag_Accel_data.h"
#include "GPSin.h"
#include "starlord.h"



// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  GPSInitialization();
  initializeIMU();
  servosetup();
}

// the loop routine runs over and over again forever:
void loop() {
   
	completegeographicinitiallization();
        float amdy;
        
        while(1==1){
        do{
          amdy=analogRead(POTENT)*(180/1024);
          servomove(3,amdy);
        }while (digitalRead(BUTTONPIN)==LOW);


        starlord(amdy);
        } 
}
