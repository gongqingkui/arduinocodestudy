unsigned char hexdata[9] = {0xA5, 0x5A, 0x06, 0x80,0x11,0x11,0x22,0x22, 0xAA};
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
void setup() {
  mySerial.begin(9600);
  mySerial.write(hexdata, 9);
}

void loop() { // run over and over
  delay(2000);
  mySerial.write(hexdata, 9);
}
