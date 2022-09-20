#include<LiquidCrystal.h>

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

int num1;
int num2;
String op;
float res;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup(){

  lcd.begin(16,2);
  Serial.begin(9600);
    lcd.setCursor(0,0);
  lcd.print("Welcome to Calc");
  delay(1500);
  lcd.clear();
}

void loop(){  

  lcd.setCursor(0,0);
  lcd.print("Enter 1st Num: ");
  while(Serial.available() == 0){
  }
  num1 = Serial.parseInt();
  lcd.setCursor(0,1);
  lcd.print("You Entered: ");
  lcd.print(num1);
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter 2nd Num: ");
  while(Serial.available() == 0){
  }
  num2 = Serial.parseInt();
  lcd.setCursor(0,1);
  lcd.print("You Entered: ");
  lcd.print(num2);
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter operator: ");
  while(Serial.available() == 0){
  }
  op = Serial.readString();
  lcd.setCursor(0,1);
  lcd.print("You Entered: ");
  lcd.print(op);
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Your Result is: ");
  if(op == "+"){ 
  lcd.setCursor(0,1);
  lcd.print(num1);
  lcd.print("+");
  lcd.print(num2);
  lcd.print("=");
  res = num1+num2;
  lcd.print(res);
  delay(4000);
  }
  if(op == "-"){   
  lcd.setCursor(0,1);
  lcd.print(num1);
  lcd.print("-");
  lcd.print(num2);
  lcd.print("=");
  res = num1-num2;
  lcd.print(res);
  delay(4000);
  }
  if(op == "*"){   
  lcd.setCursor(0,1);
  lcd.print(num1);
  lcd.print("*");
  lcd.print(num2);
  lcd.print("=");
  res = num1*num2;
  lcd.print(res);
  delay(4000);  
  }
  if(op == "/"){  
  lcd.setCursor(0,1);
  lcd.print(num1);
  lcd.print("/");
  lcd.print(num2);
  lcd.print("=");
  res = num1/num2;
  lcd.print(res);
  delay(4000);
  }
  lcd.clear();
}
