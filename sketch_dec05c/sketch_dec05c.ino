float a;
float b;
float c;
void setup(){
Serial.begin(9600);  
 while(!Serial); 
}

void loop(){
    Serial.print("Enter first number");
    while(Serial.available()==0);
    a=Serial.parseFloat();
    Serial.println(a);
    
    delay(500);
    
    Serial.print("Enter the second number");
    while(Serial.available()==0);
    b=Serial.parseFloat();
    Serial.println(b);
    `
    
    Serial.print("Addition is=");
    c=a+b;
    Serial.println(c);
  
  
  
}
