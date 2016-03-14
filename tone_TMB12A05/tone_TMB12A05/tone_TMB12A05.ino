byte tonepin = 10;
void setup(){
  pinMode(tonepin,OUTPUT);
}
void loop(){
  //int i = 20;
  //for(i=20;i<=20000;i+=10){  
  //  tone(tonepin,i);
  //  delay(20);
  //}
  tone(tonepin,random(20,20000));
}
