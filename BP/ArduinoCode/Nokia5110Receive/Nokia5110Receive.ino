/*********************************************************************
  需要
  1.下载Adafruit-PCD8544-Nokia-5110-LCD-library-master解压到D:\Program Files\Arduino\libraries
  2.下载Adafruit-GFX-Library-master解压到D:\Program Files\Arduino\libraries
  3.@todo 巩庆奎 Arduino 1.6.7编译通过
  // Software SPI (slower updates, more flexible pin options):
  // pin 6 - Serial clock out (SCLK)
  // pin 5 - Serial data out (DIN)
  // pin 4 - Data/Command select (D/C)
  // pin 3 - LCD chip select (CS)
  // pin 2 - LCD reset (RST)
*********************************************************************/
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#include "Mirf.h"
#include "nRF24L01.h"
#include "MirfHardwareSpiDriver.h"

Adafruit_PCD8544 display = Adafruit_PCD8544( 6, 5, 4, 3, 2);
char data;
char words;
char wordss[144];

void setup()   {
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  Serial.begin(9600);
  display.begin();
  display.clearDisplay();
  display.setContrast(50);
  // text display tests
  //display.setTextSize(1);
  //display.setTextColor(BLACK);
  //display.setTextColor(WHITE, BLACK); // 'inverted' text
  //display.println(3.141592);
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0, 0);
  //display.print("0x"); display.println(0xDEADBEEF, HEX);
 display.setTextSize(2);
 display.println("CZLBPS");
 display.setTextSize(1);
  display.println("CangZhou Local BP Server");
  //display.setCursor(4,0);
  display.println("gongqingkui@126.com");
  display.display();
  //delay(2000);
  //display.clearDisplay();
  //display.setRotation(1);  // rotate 90 degrees counter clockwise, can also use values of 2 and 3 to go further.

  Serial.begin(9600);
  Mirf.spi = &MirfHardwareSpi;          //加载24L01  SPI
  Mirf.init();
  Mirf.setRADDR((byte *)"serv1"); //接收地址" "
  Mirf.payload = sizeof(char);            //数据类型（整数）
  Mirf.config();
  Serial.println("NRF24L01inited");
}

int i = 0;
void loop() {
  if (Mirf.dataReady())
  { //如果接收到数据则执行
    Mirf.getData((byte *)&data);   //接收数据
    if (data != '\n') {
      wordss[i++] = data;
    } else if (data == '\n') {
      
      wordss[i++] = '\n';
      for(;i<144;i++){wordss[i]=0;}
      Serial.print(wordss);  //显示X向 1至1024
      display.clearDisplay();
      display.println(wordss);
      display.display();
      i = 0;
    }
    Mirf.rxFifoEmpty();   //清理24L01援存
  }


}
