double sine;
double cose;
float angles = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sine = sin(3*angles);
  cose = cos(3*angles);
  Serial.print(1);
  Serial.print(",");
  Serial.print(sine);
  Serial.print(",");
  Serial.print(cose);
  Serial.print(",");
  Serial.println(-1);
  angles = angles+0.01;
}
