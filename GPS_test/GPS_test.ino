#include <SoftwareSerial.h>
#include <TinyGPS.h>


/* The NMEA GPS data is taken from the ublox Neo 6M using the TinyGPS library. This code then extracts the
specific data we need, namely: longitude, latitude, altitude, and time.*/

// This code assumes a 9600-baud serial GPS device hooked up on pins 4(rx) and 3(tx).

TinyGPS gps;

static void smartdelay(unsigned long ms);
static void print_float(float val, float invalid, int len, int prec);
static void print_int(unsigned long val, unsigned long invalid, int len);
static void print_date(TinyGPS &gps);

#define RXPIN 4
#define TXPIN 3

SoftwareSerial nss(RXPIN, TXPIN);

void setup()
{
  Serial.begin(115200);
  nss.begin(9600);
}

void loop()
{
  long latitude, longitude;
  unsigned long fix_age, time, date;
  
  gps.get_position(&latitude, &longitude, &fix_age);
  Serial.println("\nLatitude: ");
  print_float(latitude, TinyGPS::GPS_INVALID_F_ANGLE, 10, 6);
  Serial.println("\nLongitude: ");
  print_float(longitude, TinyGPS::GPS_INVALID_F_ANGLE, 11, 6);
  Serial.println("\nfix_age: ");
  print_int(fix_age, TinyGPS::GPS_INVALID_AGE, 5);
  Serial.println("\nDate: ");
  print_date(gps);
  Serial.println("\nAltitude: ");
  print_float(gps.f_altitude(), TinyGPS::GPS_INVALID_F_ALTITUDE, 7, 2);
  
  smartdelay(1000);
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

static void print_float(float val, float invalid, int len, int prec)
{
  if (val == invalid)
  {
    while (len-- > 1)
      Serial.print('*');
    Serial.print(' ');
  }
  else
  {
    Serial.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1); // . and -
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i=flen; i<len; ++i)
      Serial.print(' ');
  }
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
