/*
  SD card datalogger

  This example shows how to log data from three analog sensors
  to an SD card using the SD library.

  The circuit:
   analog sensors on analog ins 0, 1, and 2
   SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

     DHT11引脚
  文字面是背面
  窗口面正面，左至右为+5v data GND
  数据引脚9


  created  24 Nov 2010
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

*/

#include <SPI.h>
#include <SD.h>
#include <dht11.h>

dht11 DHT11;
#define DHT11PIN 9
float humidity = 0.0;
float temperature = 0.0;

const int chipSelect = 4;

void setup() {
  if (!SD.begin(chipSelect)) {
    return;
  }
}

void loop() {
  int chk = DHT11.read(DHT11PIN);
  humidity = (float)DHT11.humidity;
  temperature = (float)DHT11.temperature;
  String dataString = "";
  dataString +=String(millis()/1000);
  dataString += ":";
  dataString += String(chk);
  dataString += ",";
  dataString += String(temperature);
  dataString += ",";
  dataString += String(humidity);
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
  }
  delay(2000);
}
