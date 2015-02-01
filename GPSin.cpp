#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include "configuration.h"
#include "GPSin.h"

 /* The NMEA GPS data is taken from the ublox Neo 6M using the TinyGPS library. This code then extracts the
specific data we need, namely: longitude, latitude, altitude, date, and time.*/

// This code assumes a 9600-baud serial GPS device hooked up on pins 4(rx) and 3(tx).


TinyGPS gps;

static void smartdelay(unsigned long ms);
static void print_int(unsigned long val, unsigned long invalid, int len);
static void print_date(TinyGPS &gps);
int data=0;

SoftwareSerial nss(GPSRXPIN, GPSTXPIN);

void GPSInitialization()
{
     nss.begin(9600);
}

long latitude, longitude;
unsigned long fix_age, time, date;

float* GPSData()
{
  float GPSdatamat[5];
  
  if(GPS_USE_TEST==1){
    smartdelay(5000);  
    
        GPSdatamat[0]=41.248963;
	GPSdatamat[1]=08151.6838;
	GPSdatamat[2]=170834;
	GPSdatamat[3]=191194;
	GPSdatamat[4]=280.2;

return GPSdatamat;
  
  }
  else{
  
  
  float falt;
  while (data!=20){
    smartdelay(1000);
    gps.get_position(&latitude, &longitude, &fix_age);
    gps.get_datetime(&date, &time, &fix_age);;
    falt = gps.f_altitude();
    if(latitude!=TinyGPS::GPS_INVALID_F_ANGLE){
      data=data+1;
    }
  }
  GPSdatamat[0]=latitude;
  GPSdatamat[1]=longitude;
  GPSdatamat[2]=time;
  GPSdatamat[3]=date;
  GPSdatamat[4]=falt;
  return GPSdatamat;   
  }
  
}

static void smartdelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (nss.available())
      gps.encode(nss.read());
  } while (millis() - start < ms);
}

static void print_date(TinyGPS &gps)
{
  int year;
  byte month, day, hour, minute, second, hundredths;
  unsigned long age;
  gps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths, &age);
  if (age == TinyGPS::GPS_INVALID_AGE)
    Serial.print("********** ******** ");
  else
  {
    char sz[32];
    sprintf(sz, "%02d/%02d/%02d %02d:%02d:%02d ",
        month, day, year, hour, minute, second);
    Serial.print(sz);
  }
  print_int(age, TinyGPS::GPS_INVALID_AGE, 5);
  smartdelay(0);
}


static void print_int(unsigned long val, unsigned long invalid, int len)
{
  char sz[32];
  if (val == invalid)
    strcpy(sz, "*******");
  else
    sprintf(sz, "%ld", val);
  sz[len] = 0;
  for (int i=strlen(sz); i<len; ++i)
    sz[i] = ' ';
  if (len > 0) 
    sz[len-1] = ' ';
  Serial.print(sz);
  smartdelay(0);
}
