#include <iarduino_RTC.h>
iarduino_RTC time(RTC_DS3231);
void setup()
{
  time.begin();
  time.settime(0,50,16,30,9,18,0);
}
void loop()
{
  
}
