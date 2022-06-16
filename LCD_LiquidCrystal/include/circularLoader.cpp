#include <Arduino.h>
#include <config.cpp>

void smallLoaderOnLCD(unsigned int timeInMilliSeconds) {
    byte circOne[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b10001,
    0b10001,
    0b01110,
    0b00000,
    0b00000,
    };

    byte circTwo[8] = {
    0b00000,
    0b00000,
    0b01110,
    0b10000,
    0b10000,
    0b01110,
    0b00000,
    0b00000,
    };

    byte circThree[8] = {
    0b00000,
    0b00000,
    0b01110,
    0b10001,
    0b10001,
    0b00000,
    0b00000,
    0b00000,
    };
    
    byte circFour[8] = {
    0b00000,
    0b00000,
    0b01110,
    0b00001,
    0b00001,
    0b01110,
    0b00000,
    0b00000,
    };

    lcd.createChar(1,circOne);
    lcd.createChar(2,circTwo);
    lcd.createChar(3,circThree);
    lcd.createChar(4,circFour);
    lcd.begin(16,2);
    lcd.clear();
    lcd.print("Small Loader:");
    lcd.setCursor(14,0);

    int startTime = millis();

    while((millis()-startTime) <= timeInMilliSeconds){
        lcd.write(byte(1));
        delay(200);
        lcd.rightToLeft();
        lcd.print(" ");
        lcd.leftToRight();
        lcd.write(byte(2));
        delay(200);
        lcd.rightToLeft();
        lcd.print(" ");
        lcd.leftToRight();
        lcd.write(byte(3));
        delay(200);
        lcd.rightToLeft();
        lcd.print(" ");
        lcd.leftToRight();
        lcd.write(byte(4));
        delay(200);
        lcd.rightToLeft();
        lcd.print(" ");
        lcd.leftToRight();
    }
    lcd.clear();
}

void largeLoaderOnLCD(unsigned int timeInMilliSeconds) {

    byte circOne[8] = {
    0b00000,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b01110,
    };

    byte circTwo[8] = {
    0b01110,
    0b10000,
    0b10000,
    0b10000,
    0b10001,
    0b10001,
    0b10001,
    0b01110,
    };

    byte circThree[8] = {
    0b01110,
    0b10001,
    0b10001,
    0b10001,
    0b10000,
    0b10000,
    0b10000,
    0b01110,
    };
    
    byte circFour[8] = {
    0b01110,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b00000,
    };

    byte circFive[8] = {
    0b01110,
    0b10001,
    0b10001,
    0b10001,
    0b00001,
    0b00001,
    0b00001,
    0b01110,
    };

    byte circSix[8] = {
    0b01110,
    0b00001,
    0b00001,
    0b00001,
    0b10001,
    0b10001,
    0b10001,
    0b01110,
    };

    lcd.createChar(1,circOne);
    lcd.createChar(2,circTwo);
    lcd.createChar(3,circThree);
    lcd.createChar(4,circFour);
    lcd.createChar(5,circFive);
    lcd.createChar(6,circSix);
    lcd.begin(16,2);
    lcd.clear();
    lcd.print("Large Loader:");
    lcd.setCursor(14,0);

    int startTime = millis();

    while((millis()-startTime) <= timeInMilliSeconds){
        lcd.write(byte(1));
        delay(150);
        lcd.rightToLeft();
        lcd.print(" ");
        lcd.leftToRight();
        lcd.write(byte(2));
        delay(150);
        lcd.rightToLeft();
        lcd.print(" ");
        lcd.leftToRight();
        lcd.write(byte(3));
        delay(150);
        lcd.rightToLeft();
        lcd.print(" ");
        lcd.leftToRight();
        lcd.write(byte(4));
        delay(150);
        lcd.rightToLeft();
        lcd.print(" ");
        lcd.leftToRight();
        lcd.write(byte(5));
        delay(150);
        lcd.rightToLeft();
        lcd.print(" ");
        lcd.leftToRight();
        lcd.write(byte(6));
        delay(150);
        lcd.rightToLeft();
        lcd.print(" ");
        lcd.leftToRight();
    }
    lcd.clear();
}