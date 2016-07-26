/*
 * @todo 编译通过
 * 
1602引脚图
1602引脚 Arduino引脚 功能详解
1        gnd            VSS一般接地
2        +5v            VDD接电源（+5V）
3                    V0液晶显示器对比度调整端，接正电源时对比度最弱，接地电源时对比度最高（对比度过高时会产生“鬼影”，使用时可以通过一个10K的电位器调整对比度）。
4        7          RS RS为寄存器选择，高电平1时选择数据寄存器、低电平0时选择指令寄存器。
5        gnd            R/WR/W为读写信号线，高电平(1)时进行读操作，低电平(0)时进行写操作。
6        6            EE(或EN)端为使能(enable)端，写操作时，下降沿使能。读操作时，E高电平有效
7                    DB0低4位三态、 双向数据总线 0位（最低位）
8                    DB1低4位三态、 双向数据总线 1位
9                    DB2低4位三态、 双向数据总线 2位
10                   DB3低4位三态、 双向数据总线 3位
11       5          DB4高4位三态、 双向数据总线 4位
12       4            DB5高4位三态、 双向数据总线 5位
13       3            DB6高4位三态、 双向数据总线 6位
14       2            DB7高4位三态、 双向数据总线 7位（最高位）（也是busy flag）
15                   BLA背光电源正极
16                   BLK背光 电源负极
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 6
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>
int inputPin = 12;//echo
int outputPin = 13;//trig 

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("hello, world!");
  
  Serial.begin(9600);
  pinMode(inputPin,INPUT);
  pinMode(outputPin,OUTPUT);

}

void loop() {
 //lcd.setCursor(0, 1);
 //lcd.print(millis() / 1000);

 digitalWrite(outputPin,LOW);
  delayMicroseconds(2);
  digitalWrite(outputPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(outputPin,LOW);
  float distance = pulseIn(inputPin,HIGH);
  distance = distance / 58 ;
  Serial.println(distance);
  lcd.setCursor(0, 1);
  lcd.print(distance);
  delay(1000);
}

