int sPin = 5;
int dir1 = 4;
int dir2 = 3;
int button1 = 6;
int button2 = 7;
int sVal = 0;
int button1NewVal;
int button2NewVal;
int button1OldVal=1;
int button2OldVal=1;
int increament = 10;//bas 50 ki jgh variable lga diya taki easily step val control kr ske
int decreament = 50;//bas 50 ki jgh variable lga diya taki easily step val control kr ske

void setup(){

  pinMode(sPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  digitalWrite(button1, HIGH);
  digitalWrite(button2, HIGH);
  Serial.begin(9600);
}

void loop(){

  button1NewVal = digitalRead(button1);
  button2NewVal = digitalRead(button2);
  if(button1OldVal == 0 && button1NewVal ==1){
    if(sVal>=0&&sVal<110){
      sVal = 110;
      digitalWrite(dir1, HIGH);
      digitalWrite(dir2, LOW);
      analogWrite(sPin,sVal);
    }
    else if(sVal>=110){

      if(sVal<255){
        sVal = sVal + increament;
        if(sVal > 255){
        sVal = 255;
        analogWrite(sPin,sVal);
        }
        else{
          analogWrite(sPin,sVal);
        }
      }
    }
    else if(sVal<0 && sVal>=-110){
      sVal = 0;
        analogWrite(sPin, sVal);
    }
    else{
      sVal = sVal + increament;
        analogWrite(sPin, -sVal);
    }
  }
  
  
  if(button2OldVal ==0 && button2NewVal ==1){
    if(sVal<=0 && sVal>-110){
      sVal = -110;
        digitalWrite(dir1,LOW);
        digitalWrite(dir2, HIGH);
        analogWrite(sPin, -sVal);
    }
    
    else if(sVal<=-110){
      if(sVal>-255){
          sVal = sVal - decreament;
        if(sVal < -255){
            sVal = -255;
          analogWrite(sPin, -sVal);
        }
        else{
            analogWrite(sPin, -sVal);
        }
      }
    }
    else if(sVal >0 && sVal<=110){
      sVal = 0;
        analogWrite(sPin, sVal);
    }
    else{
      sVal = sVal - decreament;
        analogWrite(sPin, sVal);
    }
  }
  
  button1OldVal = button1NewVal;
  button2OldVal = button2NewVal;
  
}
