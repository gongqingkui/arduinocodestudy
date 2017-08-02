/*********************************************************************
  需要
  1.下载Adafruit-PCD8544-Nokia-5110-LCD-library-master解压到D:\Program Files\Arduino\libraries
  2.下载Adafruit-GFX-Library-master解压到D:\Program Files\Arduino\libraries
  3.@todo 巩庆奎 Arduino 1.6.7编译通过
*********************************************************************/
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Software SPI (slower updates, more flexible pin options):
// pin 6 - Serial clock out (SCLK)
// pin 5 - Serial data out (DIN)
// pin 4 - Data/Command select (D/C)
// pin 3 - LCD chip select (CS)
// pin 2 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544( 6, 5, 4, 3, 2);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

void setup()   {
  Serial.begin(9600);
  display.begin();
  display.clearDisplay();
  display.setContrast(50);
  // text display tests
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0, 0);
  display.println("Hello, world!");
  display.setTextColor(WHITE, BLACK); // 'inverted' text
  display.println(3.141592);
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.print("0x"); display.println(0xDEADBEEF, HEX);
  display.display();
  //delay(2000);
  //display.clearDisplay();
  //display.setRotation(1);  // rotate 90 degrees counter clockwise, can also use values of 2 and 3 to go further.
}


void loop() {
  display.clearDisplay();
  display.println("a");
  display.display();
}


