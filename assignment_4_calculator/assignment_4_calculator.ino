int a;
int b;
int c;
int d;
int e;
int f;
int ch;

void setup()
{
  Serial.begin(9600);
  Serial.println("Program for Calculator");
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
  
  Serial.println("You are have the following choice:");
  Serial.println("1.Addition");
  Serial.println("2.Subtaction");
  Serial.println("3.Multiplication");
  Serial.println("4.Division");
  Serial.println("Enter your Choice:");
  while (Serial.available()==0)
  {
    
  }
  ch=Serial.parseInt();
  
  
  switch(ch)
  {
    case 1:
            Serial.println("Addition of Two number is:");
            c=a+b;
            Serial.println(c);
            break;
            
    case 2:
    
            Serial.println("Subtraction of Two number is:");
            d=a-b;
            Serial.println(d);
            break;
            
    case 3:
            
            Serial.println("Multiplication of Two number is:");
            e=a*b;
            Serial.println(e);
            break;
            
            
    case 4:
            Serial.println("Division of Two number is:");
            f=a/b;
            Serial.println(f);
            break;
    
  }
}
