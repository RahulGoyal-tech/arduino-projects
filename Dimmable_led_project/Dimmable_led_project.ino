int button1Pin = A0;
int button2Pin = A4;
int ledPin = 11;
int button1Old=0;
int button2Old=0;
int button1New;
int button2New;
int ledState=0;
int level0 = 0;
int level1 = 85;
int level2 = 170;
int level3 = 255;
int buzzPin = 13;
int dt = 100;
int j;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  Serial.begin(9600);
}

void loop()
{
   button1New = digitalRead(button1Pin);
    button2New = digitalRead(button2Pin);
    Serial.print("Button 1: ");
    Serial.println(button1New);
    Serial.print("Button 2: ");
    Serial.println(button2New);
  if(button1Old == 1 && button1New == 0){
    if(ledState == 0){
      analogWrite(ledPin, level1);
      ledState = 1;
    }
    else if(ledState == 1){
      analogWrite(ledPin, level2);
      ledState = 2;
    }
    else if(ledState == 2){
      analogWrite(ledPin, level3);
      ledState = 3;
    }
    else if(ledState == 3){
      for(j=0; j<100; j=j+1){
      digitalWrite(buzzPin, HIGH);
      delayMicroseconds(1000);
      digitalWrite(buzzPin, LOW);
      }
    }
  }
  Serial.print("HERE ");
  if(button2Old == 1 && button2New == 0){
    if(ledState == 3){
      analogWrite(ledPin, level2);
      ledState = 2;
    }
    else if(ledState == 2){
      analogWrite(ledPin, level1);
      ledState = 1;
    }
    else if(ledState == 1){
      analogWrite(ledPin, level0);
      ledState = 0;
    }
    else if(ledState == 0){
      for(j=0; j<100; j=j+1){
      digitalWrite(buzzPin, HIGH);
      delay(1);
      digitalWrite(buzzPin, LOW);
      }
    }
  }
  button1Old = button1New;
  button2Old = button2New;
  delay(dt);
}
