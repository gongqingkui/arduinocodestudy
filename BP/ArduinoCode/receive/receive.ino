#include "SPI.h"                              //24L01库文件
#include "Mirf.h"
#include "nRF24L01.h"
#include "MirfHardwareSpiDriver.h"

char data;
char words;


void setup() {
  Serial.begin(9600);
  Mirf.spi = &MirfHardwareSpi;          //加载24L01  SPI
  Mirf.init();
  Mirf.setRADDR((byte *)"serv1"); //接收地址" "
  Mirf.payload = sizeof(char);            //数据类型（整数）
  Mirf.config();
  Serial.println("NRF24L01inited");
}

void loop() {

  if (Mirf.dataReady())
  { //如果接收到数据则执行
    Mirf.getData((byte *)&data);   //接收数据
    words = data;
    Mirf.rxFifoEmpty();   //清理24L01援存??
    Serial.print(words);  //显示X向 1至1024

  }
}

