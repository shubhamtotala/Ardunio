int a,b,c;
void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    ;
  }
}

void loop()
{
  a=10;
  b=20;
  c= a+b;
  Serial.println(c);
}
