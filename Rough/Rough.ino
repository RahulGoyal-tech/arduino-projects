void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(D1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(D1))
  {
    Serial.println("Received");
  }
  else
  {
  }
}
