int redpin=10;
int bluepin = 8;
int greenpin=9;
String msg="What Colour you want?";
String mycol;

void setup()
{
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(msg);
  while(Serial.available()==0){
  }
  mycol = Serial.readString();
  if(mycol=="red"||mycol=="Red"){

    digitalWrite(redpin,HIGH);
    digitalWrite(bluepin,LOW);
    digitalWrite(greenpin,LOW);
  }
  if(mycol=="blue"||mycol=="Blue"){

    digitalWrite(redpin,LOW);
    digitalWrite(bluepin,HIGH);
    digitalWrite(greenpin,LOW);
  }
  if(mycol=="green"||mycol=="Green"){

    digitalWrite(redpin,LOW);
    digitalWrite(bluepin,LOW);
    digitalWrite(greenpin,HIGH);
  }
  if(mycol=="off"||mycol=="Off"){

    digitalWrite(redpin,LOW);
    digitalWrite(bluepin,LOW);
    digitalWrite(greenpin,LOW);
  }
  if(mycol=="aqua"||mycol=="Aqua"){

    digitalWrite(redpin,LOW);
    analogWrite(bluepin,80);
    analogWrite(greenpin,150);
  }
  if(mycol=="yellow"||mycol=="Yellow"){

    analogWrite(redpin,255);
    analogWrite(bluepin,0);
    analogWrite(greenpin,255);
  }
  if(mycol=="cyan"||mycol=="Cyan"){

    analogWrite(redpin,0);
    analogWrite(bluepin,255);
    analogWrite(greenpin,255);
  }
  if(mycol=="magenta"||mycol=="Magenta"){

    analogWrite(redpin,255);
    analogWrite(bluepin, 255);
    analogWrite(greenpin,0);
  }
  if(mycol=="orange"||mycol=="Orange"){

    analogWrite(redpin,255);
    analogWrite(bluepin,0);
    analogWrite(greenpin,165);
  }
  if(mycol=="fuschia"||mycol=="Fuschia"){

    analogWrite(redpin,255);
    analogWrite(bluepin,128);
    analogWrite(greenpin,0);
  }
  if(mycol=="gold"||mycol=="Gold"){

    analogWrite(redpin,255);
    analogWrite(bluepin,0);
    analogWrite(greenpin,215);
  }
}
