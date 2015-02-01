#include <SoftwareSerial.h>
#include "Tiny GPS/TinyGPS.h"

/* The NMEA GPS data is taken from the ublox Neo 6M using the TinyGPS library. This code then extracts the
specific data we need, namely: longitude, latitude, altitude, and time.*/

// This code assumes a 9600-baud serial GPS device hooked up on pins 4(rx) and 3(tx).

TinyGPS gps;

#define RXPIN 4
#define TXPIN 3

SoftwareSerial nss(RXPIN, TXPIN);

long latitude, longitude;
unsigned long fix_age, time;

void loop()
{
  while (nss.available())
  {
    int c = nss.read();
    if (gps.encode(c)){
      do{        
          // retrieves +/- lat/long in 100000ths of a degree
          gps.get_position(&lat, &lon, &fix_age);
           
          // time in hhmmsscc, date in ddmmyy
          gps.get_datetime(&date, &time, &fix_age);
      } while(fix_age>20);
    }
  }
}