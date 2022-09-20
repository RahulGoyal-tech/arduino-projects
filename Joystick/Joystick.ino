int xpin = A0;
int ypin = A1;
int xval;
int yval;
int rpin = 12;
int gpin = 11;
int bpin = 13;
int dt = 100;
int count = 0;
float rval;
float bval;
float gval;
float m1 = -0.52;//-255/490
float m2 = 0.50;//255/504
void setup() {
  Serial.begin(9600);
  pinMode(xpin,INPUT);
  pinMode(ypin,INPUT);
  pinMode(rpin,OUTPUT);
  pinMode(bpin,OUTPUT);
  pinMode(gpin,OUTPUT);
}

void loop() {
  xval = analogRead(xpin);
  yval = analogRead(ypin);
  Serial.print("X Value = ");
  Serial.println(xval);
  Serial.print(" Y Value = ");
  Serial.println(yval);
  Serial.println(m1);

//Button ke left mai hai y. Center value = 497. Max(peeche) = 1022. Min(aage) = 0
//Button ke opposite side hai x. Center value = 503. Max(right) = 1022. Min(left) = 0
  if( yval<=490 && xval == 504)
  {
    count++;
    if(count>5){
      count = 0;
      rval = (m1*(yval-490)); 
      Serial.println(yval);
      Serial.println(rval);
      analogWrite(rpin,rval);
      analogWrite(bpin,0);
    }
  }
  else if( yval>=490 && xval == 504)
  {
    count++;
    if(count>5){
      count = 0;
      bval = (m2*(yval-490)); 
//      Serial.println(yval);
//      Serial.println(bval);
      analogWrite(bpin,bval);
      analogWrite(rpin,0);
    }
  }

  if( xval<=504 && yval>=490 && yval <= 500)
  {
    count++;
    if(count>5){
      count = 0;
      gval = (m1*(xval-504)); 
//      Serial.println(xval);
//      Serial.println(gval);
      analogWrite(gpin,gval);
    }
  }
  else if( xval>=504 && yval>=490 && yval <= 500)
  {
    count++;
    if(count>5){
      count = 0;
      bval = (m2*(xval-504)); 
//      Serial.println(yval);
//      Serial.println(bval);
      analogWrite(bpin,bval);
      analogWrite(rpin,bval);
      analogWrite(gpin,bval);
    }
  }
  
  if (yval >= 497 && xval == 504 && yval <= 500){
    count = 0;
    analogWrite(rpin,0);
    analogWrite(bpin,0);
    analogWrite(gpin,0);
  }
}
