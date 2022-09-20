int potPin = A0;
int redPin = 7;
int potVal;

void setup() {
  // put your setup code here, to run once:
pinMode(potPin,INPUT);
pinMode(redPin, OUTPUT);
Serial.begin(250000);
}

void loop() {
  // put your main code here, to run repeatedly:
potVal = analogRead(potPin);
Serial.println(potVal);
digitalWrite(redPin,HIGH);
delay(potVal);
digitalWrite(redPin,LOW);
delay(potVal);
}
