#include <Wire.h>
#include "Sodaq_DS3231.h"

char weekDay[][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
const int chipSelect = 4;
uint32_t old_ts;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();

}
void loop() {

  Serial.println(nowtime());
  delay(2000);
}
String nowtime() {
  DateTime now = rtc.now(); //get the current date-time
  uint32_t ts = now.getEpoch();

  String dataString = "";
  dataString = now.year();
  dataString += "-";
  dataString += now.month();
  dataString += "-";
  dataString += now.date();
  dataString += " ";
  dataString += now.hour();
  dataString += ":";
  dataString += now.minute();
  dataString += ":";
  dataString += now.second();

  return dataString;
}
