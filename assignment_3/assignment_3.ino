int a;
int b;
int c;

void setup()
{
  Serial.begin(9600);
  Serial.println("Program for addition");
  delay(1000);
  
}

void loop()
{
   
    Serial.println("Enter the first Number:");
    while (Serial.available()==0)
    {
     
    }
     a=Serial.parseInt();
    Serial.println(a);
      
    delay(1000); 
  
  Serial.println("Enter the Second Number:");
  while (Serial.available()==0)
  {
  
  }
  b=Serial.parseInt();
  Serial.println(b);
  
   c=a+b;
  
  Serial.print("Addition of Two number is:");
  Serial.println(c);
  
  }
  


