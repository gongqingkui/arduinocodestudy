#include "SPI.h"      //24L01库文件
#include "Mirf.h"
#include "nRF24L01.h"
#include "MirfHardwareSpiDriver.h"

char words;


void setup() {
  Serial.begin(9600);
  Mirf.spi = &MirfHardwareSpi;  //加载24L01  SPI
  Mirf.init();                                 //开始
  Mirf.setTADDR((byte *)"serv1");//发送到"接收地址"
  Mirf.payload = sizeof(char);
  Mirf.config();
  Serial.println("send init");
}
void loop() {

  while (Serial.available() > 0)
  { words = Serial.read();
    Mirf.send((byte *)&words);
    Serial.println(words);
    while (Mirf.isSending())
    { }
  }
}
