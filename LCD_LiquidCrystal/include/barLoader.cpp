#include <Arduino.h>
#include <config.cpp>

void clear_space(uint8_t coloumn,uint8_t rows, uint8_t numOfClearSpaces);

void barLoaderOnLCD(int timeInMilliSeconds){
    int delayTime = timeInMilliSeconds/50;
    int percent = 0;
    uint8_t col = 0;
    uint8_t row = 0;

    //Making bytes for custom characters
    byte one[8]{
        0b10000,
        0b10000,
        0b10000,
        0b10000,
        0b10000,
        0b10000,
        0b10000,
        0b10000
    };
    byte two[8]{
        0b11000,
        0b11000,
        0b11000,
        0b11000,
        0b11000,
        0b11000,
        0b11000,
        0b11000
    };
    byte three[8]{
        0b11100,
        0b11100,
        0b11100,
        0b11100,
        0b11100,
        0b11100,
        0b11100,
        0b11100
    };
    byte four[8]{
        0b11110,
        0b11110,
        0b11110,
        0b11110,
        0b11110,
        0b11110,
        0b11110,
        0b11110
    };
    byte five[8]{
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111,
        0b11111
    };

    //Assigning custom character the byte number
    lcd.createChar(1,one);
    lcd.createChar(2,two);
    lcd.createChar(3,three);
    lcd.createChar(4,four);
    lcd.createChar(5,five);
    lcd.begin(16,2);
    lcd.setCursor(col,row);
    row++;
    lcd.print("Progress Bar");
    lcd.setCursor(13,1);
    lcd.print(percent);
    lcd.print('%');
    lcd.setCursor(col,row);

    for(int i=0; i<10; i++){
        lcd.write(byte(1));
        delay(10);
        percent+=2;
        if(percent/10 == 0){
            clear_space(12, 1, 3);
            lcd.setCursor(14,1);
            lcd.print(percent);
            lcd.print('%');
            lcd.setCursor(col,row);
        }
        else if(percent/100 == 0){
            clear_space(12, 1, 3);
            lcd.setCursor(13,1);
            lcd.print(percent);
            lcd.print('%');
            lcd.setCursor(col,row);
        }
        delay(delayTime);

        lcd.write(byte(2));
        delay(10);
        percent+=2;
        if(percent/10 == 0){
            clear_space(12, 1, 3);
            lcd.setCursor(14,1);
            lcd.print(percent);
            lcd.print('%');
            lcd.setCursor(col,row);
        }
        else if(percent/100 == 0){
            clear_space(12, 1, 3);
            lcd.setCursor(13,1);
            lcd.print(percent);
            lcd.print('%');
            lcd.setCursor(col,row);
        }
        delay(delayTime);

        lcd.write(byte(3));
        delay(10);
        percent+=2;
        if(percent/10 == 0){
            lcd.setCursor(14,1);
            lcd.print(percent);
            lcd.print('%');
            lcd.setCursor(col,row);
        }
        else if(percent/100 == 0){
            lcd.setCursor(13,1);
            lcd.print(percent);
            lcd.print('%');
            lcd.setCursor(col,row);
        }
        delay(delayTime);

        lcd.write(byte(4));
        delay(10);
        percent+=2;
        if(percent/10 == 0){
            lcd.setCursor(14,1);
            lcd.print(percent);
            lcd.print('%');
            lcd.setCursor(col,row);
        }
        else if(percent/100 == 0){
            lcd.setCursor(13,1);
            lcd.print(percent);
            lcd.print('%');
            lcd.setCursor(col,row);
        }
        delay(delayTime);

        lcd.write(byte(5));
        delay(10);
        percent+=2;
        if(percent/10 == 0){
            lcd.setCursor(14,1);
            lcd.print(percent);
            lcd.print('%');
            lcd.setCursor(col,row);
        }
        else if(percent/100 == 0){
            lcd.setCursor(13,1);
            lcd.print(percent);
            lcd.print('%');
            lcd.setCursor(col,row);
        }
        else if(percent == 100){
            lcd.setCursor(12,1);
            lcd.print(percent);
            lcd.print('%');
            lcd.setCursor(col,row);
        }
        delay(delayTime);
        
        col++;
        lcd.setCursor(col,row);
    }
    
}
void clear_space(uint8_t coloumn,uint8_t rows, uint8_t numOfClearSpaces){
    lcd.setCursor(coloumn, rows);
    for(int i=0; i<numOfClearSpaces; i++){
        lcd.print(" ");
    }
}