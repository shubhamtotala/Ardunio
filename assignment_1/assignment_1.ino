int a;
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
  if(Serial.available()>0){
    char inByte=Serial.read();
    delay(100);
    Serial.println(inByte);
    delay(100);
}
}
