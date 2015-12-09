int sw;

void setup()
{
  for(int i=2;i<=5;i++)
  pinMode(i,OUTPUT);
  
  pinMode(8,INPUT);
  
  
}

void loop()
{
  sw=digitalRead(8);
  
  if(sw==HIGH)
  {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  delay(200);
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  delay(200);
  digitalWrite(4,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  delay(200);
  digitalWrite(5,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  delay(200); 
  }
 else
 {
  digitalWrite(5,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(2,LOW);
  delay(200);
  digitalWrite(4,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  delay(200);
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  delay(200);
  digitalWrite(2,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  delay(200); 
 }
}
