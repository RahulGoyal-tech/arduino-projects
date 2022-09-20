int trigPin = 12;
int echoPin = 11;
int pingTravelTime;
float distance;
void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(2000000);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(10);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
pingTravelTime = pulseIn(echoPin, HIGH);
//Serial.print("PTT = ");
//Serial.print(pingTravelTime);
//Serial.print(",");
//Serial.print(" Distance = ");
distance = (0.0343*(pingTravelTime))/2;
//distance = ((9.2/500.)*(pingTravelTime-200)) + 3.8 ;
Serial.println(distance);
//Serial.println(" cm ");
delay(25);
}
