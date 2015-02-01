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
Serial.begin(115200);  
  // initialize the digital pin as an output.
  GPSInitialization();
  initializeIMU();
  servosetup();
}

// the loop routine runs over and over again forever:
void loop() {
   Serial.println("Done 0");
	completegeographicinitiallization();
Serial.println("Done 1");
        float amdy;
        
        while(1==1){
        do{
          amdy=analogRead(POTENT)*(180/1024);
          servomove(3,amdy);
          delay(1000);
          Serial.println(analogRead(POTENT));
        }while (digitalRead(BUTTONPIN)==LOW);
  Serial.println("yolo sauce");

        starlord(amdy);
        } 
}
