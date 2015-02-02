# Pavo
Arduino based equatorial mount

This Equatorial mount is based on an arduino reading GPS data, Magnetometer data and IMU data.

The code calls for a GPS outputting NMEA data. This has been tested with a ublox gps. NMEA is parsed using TINYGPS
  
The IMU that is referenced is an Adafruit 9DOF IMU. The IMU provides magnetometer information, and accelerometer information.

These two sensors are enough to control three servos to point algin a mount with the celestial axis and perform a tracking rotation.

Future code ideas include have a Bluetooth receiver to set different configuartions for the mount, providing declination data, and for star pointing.
