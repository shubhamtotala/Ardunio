void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}


void loop()
{
  Serial.println("You are having following choices:");
  Serial.println("1.Blink only one led");
  Serial.println("2.Blink two led");
  Serial.println("3.Bilnk three led");
  Serial.println("4.Blink all led");

  Serial.print("Enter your choice --> ");
  while(Serial.available()==0);
  int ch=Serial.read();
  Serial.println(ch);
  
   
   
  switch(ch)
  {
    case '1': 
            Serial.println("One LED blinking");
            digitalWrite(2,HIGH);
            delay(1000);
            digitalWrite(2,LOW);
            delay(1000);
            break;
            
    case '2':
            Serial.println("Two LED blinking");
            for(int i=2;i<=3;i++)
            {
            digitalWrite(i,HIGH);
            delay(1000);
            digitalWrite(i,LOW);
            }
            break;
            
     case '3':
     
            Serial.println("Three LED blinking");
            for (int i=2;i<=4;i++)
            {
              digitalWrite(i,HIGH);
              delay(1000);
              digitalWrite(i,LOW);
              delay(1000);
            }
            break;
            
            
     case '4':
             Serial.println("Four LED blinking");
            for(int i=2;i<=5;i++)
            {
              digitalWrite(i,HIGH);
              delay(1000);
              digitalWrite(i,LOW);
              delay(1000);
            }
            break;
            
            
      default:
            Serial.println("No LED blinking");
            for (int i=2;i<=5;i++)
            {
              digitalWrite(i,LOW);
              delay(1000);
            }
            break;
  }
       }
    

 

            
             
               
            
            
