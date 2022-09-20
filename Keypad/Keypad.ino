#include <Keypad.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define S_WIDTH 128
#define S_HEIGHT 64

Adafruit_SSD1306 display(S_WIDTH, S_HEIGHT, &Wire, -1);

String code;

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {D0, D1, D2, D3};
byte colPins[COLS] = {D4, D5, D6, D7};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c))
  {
    Serial.println("Waiting for OLED to begin!");
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.print("KEYPAD");
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();
}

void loop() {
  display.setCursor(0,0);
  display.print("CODE: ");
  char key = keypad.getKey();
  if (key == '*'){
    if(code == "#ABC"){
      Serial.println("Code 1 Received");
      code = "";
      display.clearDisplay();
      display.setCursor(0,0);
      display.print("ADMIN");
      display.display();
      delay(1000);
      display.clearDisplay();
    }
    else if(code == "#123"){
      Serial.println("Code 2 Received");
      code = "";
      display.clearDisplay();
      display.setCursor(0,0);
      display.print("MANAGER");
      display.display();
      delay(1000);
      display.clearDisplay();
    }
    else{
      Serial.println("Unknown Code Received");
      code = "";
      display.clearDisplay();
      display.setCursor(0,0);
      display.print("WORKER");
      display.display();
      delay(1000);
      display.clearDisplay();
    }
  }
  if ((code.length()>=4)&& key){
    Serial.println("Please Submit your code\nNo more Input Allowed");
    display.clearDisplay();
    display.setCursor(0,0);
    display.print("SUBMIT");
    display.setCursor(0,20);
    display.print("CODE");
    display.display();
    delay(500);
    display.clearDisplay();
  }
  else if (key != '*' && key){
    Serial.print("Key Pressed : ");
    Serial.println(key);
    code += key;
  }
  display.print(code);
  display.display();
  display.clearDisplay();
}
