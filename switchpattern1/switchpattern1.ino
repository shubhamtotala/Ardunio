int sw1;
int sw2;
void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);  
}


void loop()
{
  Serial.println("You are having following choices:");
  Serial.println("1.Left to right");
  Serial.println("2.Righ to left");
  Serial.print("Enter your choice --> ");
  while(Serial.available()==0);
  int ch=Serial.read();
  Serial.println(ch);
  while (sw1==HIGH)
   
   
  switch(ch)
  {
    case '1': 
            Serial.println("Left to right");
            digitalWrite(2,HIGH);
            delay(500);
            digitalWrite(2,LOW);
            digitalWrite(3,HIGH);
            delay(500);
            digitalWrite(3,LOW);
            digitalWrite(4,HIGH);
            delay(500);
            digitalWrite(4,LOW);
            digitalWrite(5,HIGH);
            delay(500);
            digitalWrite(5,LOW);
            
            break;
            
    case '2':
            Serial.println("Right to Left");
            digitalWrite(5,HIGH);
            delay(500);
            digitalWrite(5,LOW);
            digitalWrite(4,HIGH);
            delay(500);
            digitalWrite(4,LOW);
            digitalWrite(3,HIGH);
            delay(500);
            digitalWrite(3,LOW);
            digitalWrite(2,HIGH);
            delay(500);
            digitalWrite(2,LOW);
            break;
  
            
            
      default:
            Serial.println("Invalid Choice");
            for (int i=0;i<=3;i++)
            {
              digitalWrite(2,HIGH);
              digitalWrite(3,HIGH);
              digitalWrite(4,HIGH);
              digitalWrite(5,HIGH);
              delay(500);
              digitalWrite(2,LOW);
              digitalWrite(3,LOW);
              digitalWrite(4,LOW);
              digitalWrite(5,LOW);
              delay(500);
            }
            break;
  }
       }
    

 

            
             
               
            
            
