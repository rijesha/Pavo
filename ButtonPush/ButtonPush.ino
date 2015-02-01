#define BUTTONPIN 8 //put this in configuration.h
#include <configuration.h>
#include <SoftwareSerial.h>

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  if (digitalRead(BUTTONPIN)==HIGH)
  {
      //start doing stuff
      Serial.println("1");
  }
  else{
      //stop doing stuff
      Serial.println("0");
  }
}
