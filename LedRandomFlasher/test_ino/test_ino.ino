/*In the ubuntu with Arduino USB cable on the FrontBroad
You shoud choose the /dev/ttyACM1 or 0 serial
gongqingkui at 126.com
*/
byte yellowledpin = 11;
byte redledpin = 10;
void setup(){
  pinMode(yellowledpin,OUTPUT);
  pinMode(redledpin,OUTPUT);
}
void loop(){
  analogWrite(yellowledpin,random(0));
  analogWrite(redledpin,random(255));  
}
