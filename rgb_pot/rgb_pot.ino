int redpin = 10;
int greenpin = 9;
int bluepin = 8;
int potpin = A0;
int potval;
float redval;
float greenval;
float blueval;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(redpin, OUTPUT);
pinMode(greenpin, OUTPUT);
pinMode(bluepin, OUTPUT);
pinMode(potpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
potval = analogRead(potpin);
if(potval>=0&&potval<256){
  analogWrite(redpin,potval);
  analogWrite(bluepin,0);
  analogWrite(greenpin,0);
}
if(potval>=256&&potval<512){
  analogWrite(redpin,255);
  analogWrite(bluepin,potval-256);
  analogWrite(greenpin,0);
}
if(potval>=512&&potval<768){
  analogWrite(redpin,255);
  analogWrite(bluepin,255);
  analogWrite(greenpin,potval-512);
}
if(potval>=768&&potval<1023){
  analogWrite(redpin,255);
  analogWrite(bluepin,255);
  analogWrite(greenpin,255);
}
Serial.println(potval);
}
