int inputPin = 4;//echo
int outputPin = 5;//trig 
void setup(){
  Serial.begin(9600);
  pinMode(inputPin,INPUT);
  pinMode(outputPin,OUTPUT);
}
void loop(){
  digitalWrite(outputPin,LOW);
  delayMicroseconds(2);
  digitalWrite(outputPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(outputPin,LOW);
  float distance = pulseIn(inputPin,HIGH);
  distance = distance / 58 ;
  Serial.println(distance);
  delay(1000); 
  }

