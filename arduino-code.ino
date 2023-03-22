#include<LiquidCrystal.h>

const int rs =13,en = 12,d4 =11,d5 =10,d6 =9,d7 =8;

LiquidCrystal lcd(rs,en, d4,d5,d6,d7);

int Celsius;


void setup()

{

 Serial.begin(9600);

 lcd.begin(16,2);

 lcd.setCursor(4,0);

 

 

 // set up the LCD's number of columns and rows:

 Serial.begin(9600);

 lcd.begin(16, 2);

 // Print a message to the LCD.

 lcd.print("Tmp PH");

 Serial.println("Tmp PH");

}


void loop()

{

 int sensorValue = analogRead(A0);

 float ph = sensorValue * (14.0/1023.0);

 
Serial.println(ph);

 lcd.setCursor(6,1);

 lcd.print (ph);

 

 Celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);

 lcd.setCursor(0, 0);

 lcd.print("Tmp PH");

 lcd.setCursor(0, 1);

 lcd.print(Celsius);

 lcd.print("C");

 Serial.println(Celsius);

 delay(1000);

 lcd.clear();

 

 //tds

 pinMode(15, INPUT);

 int turbutity;

 int tur1;

 turbutity=analogRead(1);

 tur1=map(turbutity, 0,471,0,5);

 delay(100);

 //tds end

 

 //tds replace by potentiometer

 pinMode(16,INPUT);

 int TDS;

 int TDS1;

 TDS=analogRead(2);

 TDS1=map(TDS,0,1023,0,2000);

 delay(100);

 //tds replace end

 

 //lcd display for tds

 lcd.setCursor(1,0); lcd.print("TDS");

 lcd.setCursor(7,0); lcd.print(TDS1);

 delay(1000);

 lcd.clear();

 

 if (TDS1<300 and (ph<8.5 or ph>6.5)){

 lcd.setCursor(1,0); lcd.print("Water is safe");

 

 //lcd.print("Water is potable and safe to use !");

 Serial.println("Water is safe");

 delay(1000);

 }

 else {

 lcd.setCursor(1,0); lcd.print("NOT safe");

 

 //lcd.print("Warning...Water is NOT safe to use");

 Serial.println("NOT safe");

 delay(1000);

 

 }

 

}
