/*
Sketch: GPRS Call Up 

Function: This sketch is used to test seeeduino GPRS's callUp function.to make it 
work, you should insert SIM card to Seeeduino GPRS and replace the phoneNumber,enjoy it!
*********************************************************************************
note: the following pins has been used and should not be used for other purposes.
  pin 8   // tx pin
  pin 7   // rx pin
  pin 9   // power key pin
  pin 12  // power status pin
*********************************************************************************
created on 2013/12/5, version: 0.1
by lawliet.zou(lawliet.zou@gmail.com)
*/

#include <gprs.h>
#include <SoftwareSerial.h>
/*
#define SIM800_TX_PIN 8 
#define SIM800_RX_PIN 7
*/
GPRS gprs;
SoftwareSerial serialSIM800(SIM800_TX_PIN,SIM800_RX_PIN);
void setup() {
  Serial.begin(9600);
  while(!Serial);
  //serialSIM800.begin(9600);  
  Serial.println("GPRS - Call up Test...");
  gprs.preInit();//power on SIM800
  delay(1000);
  while(0 !=gprs.init()) { //gprs init
      delay(1000);
      Serial.print("init error\r\n");
  }  
  Serial.println("Init success, start to call...");
  gprs.callUp("15133760632");
}

void loop() {
  /*
  if(serialSIM800.available()){
    Serial.write(serialSIM800.read());
  }
  //Read Arduino IDE Serial Monitor inputs (if available) and send them to SIM800
  if(Serial.available()){    
    serialSIM800.write(Serial.read());
  }
  */
}
