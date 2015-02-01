#include <SoftwareSerial.h>
#include <TinyGPS.h>


/* The NMEA GPS data is taken from the ublox Neo 6M using the TinyGPS library. This code then extracts the
specific data we need, namely: longitude, latitude, altitude, and time.*/

// This code assumes a 9600-baud serial GPS device hooked up on pins 4(rx) and 3(tx).

TinyGPS gps;
static void print_int(unsigned long val, int len);

#define RXPIN 4
#define TXPIN 3

SoftwareSerial nss(RXPIN, TXPIN);

long latitude, longitude;
unsigned long fix_age, time, date;
int michael=42;

void setup()
{
  Serial.begin(115200);
  nss.begin(9600);
}

void loop()
{
  while (nss.available())
  {
    int c = nss.read();
    if (gps.encode(c)){
      do{        
          // retrieves +/- lat/long in 100000ths of a degree
          gps.get_position(&latitude, &longitude, &fix_age);
           
          // time in hhmmsscc, date in ddmmyy
          gps.get_datetime(&date, &time, &fix_age);
      } while(fix_age>20);
    }
    Serial.println("\nfix_age: "); print_int(fix_age, 5 );
    Serial.println("\nLatitude: ");Serial.println(latitude);
    Serial.println("\nLongitude: ");Serial.println(longitude);
    Serial.println("\nDate: ");Serial.println(date);
    Serial.println("\nTime: ");Serial.println(time);
  }
}

static void print_int(unsigned long val, int len)
{
  char sz[32];
  sprintf(sz, "%ld", val);
  sz[len] = 0;
  for (int i=strlen(sz); i<len; ++i)
    sz[i] = ' ';
  if (len > 0) 
    sz[len-1] = ' ';
  Serial.print(sz);
}

