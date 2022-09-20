int readVal;
int readPin = A2;
float V2;
int delayT=500;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(readPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
readVal = analogRead(readPin);
V2 = (5./1023.)*readVal;
Serial.println(V2);
delay(delayT);
}
