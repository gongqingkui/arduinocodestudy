/*
 * 甲醛数据记录仪
 * TF** MOSI - pin 11 ** MISO - pin 12 ** CLK - pin 13 ** CS - pin 4
 * 甲醛传感器 9 10 做软串口
 * DS3231 SCL A5 SDA A4
 */
#include <SoftwareSerial.h>
#include <Wire.h>
#include "Sodaq_DS3231.h"
#include <SPI.h>
#include <SD.h>

SoftwareSerial mySerial(9, 10);
char weekDay[][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
const int chipSelect = 4;
uint32_t old_ts;

void setup() {
  //JQ
  Serial.begin(9600);
  delay(1000);
//  while (!Serial) {
//    ;
//  }
  Serial.println("JQbegin");
  mySerial.begin(9600);
  //DS3231
  Wire.begin();
  rtc.begin();
  //TF
  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("card initialized.");
}

void loop() {
  String nowTimeStr = "2016-01-01 12:00:00";
  String jqStr = "0.000000000";
  //ds
  nowTimeStr = nowtime();
  //Serial.println(nowTimeStr);
  delay(1000);
  //JQ
  jqStr = readJQ();
  //Serial.println(jqStr);
  delay(1000);
  //tf
  tflog(nowTimeStr + ":" + jqStr);
  delay(58000);
}

void tflog(String var) {
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.println(var);
    dataFile.close();
    Serial.println(var);
  }
  else {
    Serial.println("error opening datalog.txt");
  }
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

float readJQ() {
  unsigned char hexdata[5] = {0xA5, 0x5A, 0x02, 0x80, 0xAA};
  unsigned char cnt = 0;
  unsigned char c ;
  long hchodata = 0;
  float hcho = 0.0;
  mySerial.write(hexdata, 5);
  while (mySerial.available()) {
    c = mySerial.read();
    //Serial.print(c, HEX); Serial.print(' ');
    cnt++;
    if (cnt == 5) {//第五位*156
      hchodata = c * 256;
    }
    if (cnt == 6) {
      hchodata += c;
    }
    if (c == 170) {//最后一位
      hcho = ((float)hchodata / 100);
      return hcho;
    }
  }
}
