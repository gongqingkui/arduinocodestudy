#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10); // RX, TX
unsigned char hexdata[5] = {0xA5, 0x5A, 0x02, 0x80, 0xAA};
void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("begin");
  mySerial.begin(9600);
  mySerial.write(hexdata, 5);
}

void loop() {
  unsigned char cnt = 0;
  unsigned char c ;
  long hchodata = 0;
  float hcho = 0.0;
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
      Serial.print(hchodata, DEC);
      Serial.println("mg/M^3");
      cnt = 0;
      hchodata = 0;
    }
  }
  cnt = 0;
  mySerial.write(hexdata, 5);
  delay(2000);
}
