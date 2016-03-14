#include <stdio.h>
#include <string.h>
byte dipin = 8;
byte dapin = 10;
byte charSpe = 12;
byte ledpin = 13;
char morse[6] = "     ";
byte i = 0;
void setup() {
  pinMode(dipin, INPUT);
  pinMode(dapin, INPUT);
  pinMode(charSpe, INPUT);

  digitalWrite(dipin, HIGH);
  digitalWrite(dapin, HIGH);
  digitalWrite(charSpe, HIGH);

  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  /*
    if(digitalRead(dipin)==LOW){
      delay(100);
      if(digitalRead(dipin)==LOW){
        morse[i++] = '.';
      }
    }
    if(digitalRead(dapin)==LOW){
      delay(100);
      if(digitalRead(dapin)==LOW){
        morse[i++] = '-';
      }
    }
    if(digitalRead(charSpe)==LOW){
      delay(100);
      if(digitalRead(charSpe)==LOW){
        Serial.println(morse);
        Serial.println("Transfer:"+trans(morse));
        i = 0;
        clearMorse();
      }
    }
  */
  delay(1000);
  Serial.println(trans("..."));
  Serial.println(trans("---"));
  Serial.println(trans("..."));
}
char trans(char * str) {
  /*
    str .-***
    A ．━ B ━ ．．． C ━ ．━ ． D ━ ．．
    E ． F ．．━ ． G ━ ━ ． H ．．．．
    I ．． J ．━ ━ ━ K ━ ．━ L ．━ ．．
    M ━ ━ N ━ ． O ━ ━ ━ P ．━ ━ ．
    Q ━ ━ ．━ R ．━ ． S ．．． T ━
    U ．．━ V ．．．━ W ．━ ━ X ━ ．．━
    Y ━ ．━ ━ Z ━ ━ ．．   　
    0 ━ ━ ━ ━ ━ 1 ．━ ━ ━ ━ 2 ．．━ ━ ━ 3 ．．．━ ━
    4 ．．．．━ 5 ．．．．． 6 ━ ．．．． 7 ━ ━ ．．．
    8 ━ ━ ━ ．． 9 ━ ━ ━ ━ ．   */
  //Serial.print(str);
  char c = ' ';
  char morseTab[36][6] = {{".-"}, {"-..."},{"-.-."},{"-.."},
  {"."},{"..-."},{"--."},{"...."},
  {".."},{".---"},{"-.-"},{".-.."},
  {"--"},{"-."},{"---"},{".--."},
  {"--.-"},{".-."},{"..."},{"-"},
  {"..-"},{"...-"},{".--"},{"-..-"},
  {"-.--"},{"--.."},
  {"-----"},
  {".----"},{"..---"},{"...--"},{"....-"},{"....."},
  {"-...."},{"--..."},{"---.."},{"----."}};
  for (int i = 0; i < 36; i++) {
    if (strcmp(str, morseTab[i]) == 0) {
      c = 65 + i;
    }
  }
  return c;
}
void clearMorse() {
  for (int i = 0; i <= 5; i++)
    morse[i] = '*';
}
//digitalWrite(ledpin,LOW);
//delay(3000);
//digitalWrite(ledpin,HIGH);

