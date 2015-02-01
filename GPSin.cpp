#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include <configuration.h>


/* The NMEA GPS data is taken from the ublox Neo 6M using the TinyGPS library. This code then extracts the
specific data we need, namely: longitude, latitude, altitude, date, and time.*/

// This code assumes a 9600-baud serial GPS device hooked up on pins 4(rx) and 3(tx).

TinyGPS gps;

static void smartdelay(unsigned long ms);
static void print_float(float val, float invalid, int len, int prec);
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

int GPSdata[5]()
{
  while (data!=20){
    smartdelay(1000);
    gps.get_position(&latitude, &longitude, &fix_age);
    gps.get_datetime(&date, &time, &fix_age);;
    float falt = gps.f_altitude();
    if(latitude!=TinyGPS::GPS_INVALID_F_ANGLE){
      data=data+1;
    }
  }
  GPSdata[0]=latitude;
  GPSdata[1]=longitude;
  GPSdata[2]=time;
  GPSdata[3]=date;
  GPSdata[4]=falt;
  return GPSdata;
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