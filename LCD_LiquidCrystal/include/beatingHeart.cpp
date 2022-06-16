#include <Arduino.h>
#include <config.cpp>

byte heart[8] = {
  0b00000,
  0b01010,
  0b10101,
  0b10001,
  0b10001,
  0b01010,
  0b00100,
  0b00000
};

byte smallHeart[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b10101,
  0b01010,
  0b00100,
  0b00000,
  0b00000
};

void beatHeartOnLCD(int numTimes){
    lcd.begin(16,2); 
    lcd.createChar(0,heart);
    lcd.createChar(1,smallHeart);
    lcd.setCursor(0,0);
    lcd.print("Beating Heart");
    lcd.setCursor(0,1);
    for(int i=0; i<numTimes; i++){
        lcd.write(byte(1));
        lcd.write(byte(1));
        lcd.write(byte(1));
        lcd.write(byte(1));
        lcd.write(byte(1));
        lcd.write(byte(1));
        lcd.write(byte(1));
        lcd.write(byte(1));
        lcd.write(byte(1));
        lcd.write(byte(1));
        lcd.write(byte(1));
        lcd.write(byte(1));
        lcd.write(byte(1));
        lcd.write(byte(1));
        lcd.write(byte(1));
        lcd.write(byte(1));
        delay(300);
        lcd.setCursor(0,1);
        lcd.write(byte(0));
        lcd.write(byte(0));
        lcd.write(byte(0));
        lcd.write(byte(0));
        lcd.write(byte(0));
        lcd.write(byte(0));
        lcd.write(byte(0));
        lcd.write(byte(0));
        lcd.write(byte(0));
        lcd.write(byte(0));
        lcd.write(byte(0));
        lcd.write(byte(0));
        lcd.write(byte(0));
        lcd.write(byte(0));
        lcd.write(byte(0));
        lcd.write(byte(0));
        delay(400);
        lcd.setCursor(0,1);
    }
    lcd.clear();
}
