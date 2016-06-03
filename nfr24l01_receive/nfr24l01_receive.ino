/*gnd gnd 
vcc 3.3v 
ce 8
csn 7
csk 13
mosi 11
miso 12
irq null
*/
#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
void setup(){
Serial.begin(9600);

Mirf.spi = &MirfHardwareSpi;
Mirf.init();

Mirf.setRADDR((byte *)"serv1"); // 本地名
Mirf.payload = 11; // 长度
Mirf.channel = 3; // 信道

Mirf.config();

}
void loop(){

byte data[Mirf.payload];
if(!Mirf.isSending() && Mirf.dataReady()){ //存在数据

Mirf.getData(data);


int i;
String Temp;
for (i = 0; i < Mirf.payload; i++) //把收到的信息拼起来，到一个串里面
{
Temp += char(data[i]);
}
Serial.print("Get:");
Serial.print(Mirf.payload);
Serial.print(" ");
Serial.println(Temp);

/**
Mirf.setTADDR((byte *)"clie1");
Mirf.send(data);
**/
}
}
