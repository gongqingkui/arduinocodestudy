byte led = 13;
byte morse[26][4] ={{300,500},{500,300,300,300}};
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  flash(300);flash(300);flash(300);
  delay(300);
  flash(500);flash(500);flash(500);
  delay(300);
  flash(300);flash(300);flash(300);
 
  morseFlash('a');
  morseFlash('b');
  delay(1000); 
}
void flash(int duration){
  digitalWrite(led,HIGH);
  delay(duration);
  digitalWrite(led,LOW);
  delay(duration);
  }
void morseFlash(char c){
  byte a = c -'a';
  for(int i=0;i<=3;i++){
    flash(morse[a][i]);
    }
  delay(300);
  }
