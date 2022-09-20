int micPin = 2;
int micValNew;
int micValOld = 1;
int ledPin = 13;
int ledState=0;
//This mic does digital read and gives 0 on sound
void setup() {
  // put your setup code here, to run once:
  pinMode(micPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin,LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
micValNew = digitalRead(micPin);
Serial.print("Mic Value New : ");
Serial.print(micValNew);
Serial.print(" Mic Value Old : ");
Serial.println(micValOld);
if(micValOld==0 && micValNew == 1)
{
  if(ledState == 0){
    digitalWrite(ledPin,HIGH);
    ledState = 1;
  }
  else{
    digitalWrite(ledPin,LOW);
    ledState = 0;
  }
}
micValOld = micValNew;
}
