int dataPin = 12;
int latchPin = 11;
int clockPin = 10;
int dt = 100;

byte LED = B11111111;

void setup(){
  Serial.begin(9600);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop(){
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LED);
  digitalWrite(latchPin, HIGH);
  LED = LED + 1;
  if(LED>B11111111)
  {
     LED = B11111111; 
  }
  Serial.println(LED,BIN);
  delay(dt);
}
