#include <Arduino.h>
#include <config.cpp>
#include <beatingHeart.cpp>
#include <circularLoader.cpp>
#include <barLoader.cpp>

void setup() {}

void loop() {
  beatHeartOnLCD(5);
  delay(1000);
  smallLoaderOnLCD(2000);
  delay(1000);
  largeLoaderOnLCD(2000);
  delay(1000);
  barLoaderOnLCD(5000);
  delay(1000);
}