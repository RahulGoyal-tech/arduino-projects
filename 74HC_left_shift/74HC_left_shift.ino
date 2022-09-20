/*byte led = 0b01010101;
byte val;
void setup(){

  Serial.begin(9600);
}

void loop(){

  // led mai se humne led *2 krdiya toh left shift ho gyaa
  val = led - led/2;
  Serial.println(val,BIN);
  Serial.println(led,BIN);
  led = val;
  delay(500);
}*/

int dataPin = 12;
int latchPin = 11;
int clockPin = 10;
int dt = 500;
byte led = 0b11000110;

void setup(){
  Serial.begin(9600);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop(){
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, led);
  digitalWrite(latchPin, HIGH);
  led = led * 2;
  delay(dt);
}
