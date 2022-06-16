#include <Arduino.h>
#include <config.cpp>
#include <beatingHeart.cpp>
#include <circularLoader.cpp>
#include <barLoader.cpp>

void setup() {}

void loop() {
  //Beating Heart Animation
  beatHeartOnLCD(5);
  delay(1000);
  //Small size Loader Animation
  smallLoaderOnLCD(2000);
  delay(1000);
  //Large Size Loader Animation
  largeLoaderOnLCD(2000);
  delay(1000);
  //Bar Loader Animation
  barLoaderOnLCD(5000);
  delay(1000);
}