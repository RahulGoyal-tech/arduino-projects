int readPin = 12;
int readOld=0;
int readNew;
int ledPin = 13;
int ledState = 0;
int dt = 50;

void setup() {
  // put your setup code here, to run once:
pinMode(readPin, INPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
readNew = digitalRead(readPin);
if(readOld == 1 && readNew == 0){
  digitalWrite(ledPin, !ledState);
  ledState = !ledState;
}
readOld = readNew;
delay(dt);
}
