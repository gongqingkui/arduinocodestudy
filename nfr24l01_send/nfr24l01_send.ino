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

Mirf.setRADDR((byte *)"clie1"); // 标记本地名，用于接收
Mirf.payload = 11; //对话的长度，用于约定双方对话的缓冲窗口大小，这个代表5个字节
Mirf.channel = 3; // 信道，测试了一下,不同的信道也能接收但即时性很差，不知是不是存在自动寻道匹配机制

Mirf.config();
}
void loop(){
unsigned long time = millis();

Mirf.setTADDR((byte *)"serv1"); // 标记对方的地址
Sends("gongqingkui"); //发送了一个5字节的hello
delay(1000);
} 


void Sends(char *str)
{
int lens;
lens=strlen(str);

char msg[lens];
int i;
for (i=0;i<lens;i++)
{
msg[i]= int(str[i]);
}
Mirf.send((byte *)&msg);

while(Mirf.isSending()){}



}
