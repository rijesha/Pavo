# Pavo
Arduino based equatorial mount

This Equatorial mount is based on arduino reading GPs data and imu data.

The code calls for a GPS outputting NMEA data. This has been tested with a ublox gps.
 
NMEA is parsed using TINYGPS
  
The IMU was used was an Adafruit 9DOF IMU. The IMU provides magnetometer information, and accelerometer information.

These two sensors are enough to control three servos to point a mount in the correct orientation and track the skies
