const int TrigPin = 2; 
const int EchoPin = 3; 
long cm; 
void setup() 
{ 
Serial.begin(9600); 
pinMode(TrigPin, OUTPUT); 
pinMode(EchoPin, INPUT); 
} 
void loop() 
{ 
//发一个10ms的高脉冲去触发TrigPin 
digitalWrite(TrigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(TrigPin, HIGH); 
delayMicroseconds(10); 
digitalWrite(TrigPin, LOW); 
 
//cm = pulseIn(EchoPin, HIGH) / 58.0; //算成厘米 
cm = pulseIn(EchoPin,HIGH)/1000*340/2;
cm = (int(cm * 100.0)) / 100.0; //保留两位小数 
Serial.print(cm); 
Serial.print("cm"); 
Serial.println(); 
delay(1000); 
}
