#include <math.h>

void setup()
{
   Serial.begin(9600);                //Start the Serial connection
 
}
void loop()
{
//long unsigned a;
float sensorValue;
float sensorVoltage; 
float Value_O2;
sensorValue = analogRead(A0);
sensorVoltage =(sensorValue/1024)*5.0;
sensorVoltage = sensorVoltage/100*10000;
Value_O2 = sensorVoltage/7.43;
 
Serial.print("Concentration of O2 is ");
Serial.print(Value_O2,1);
Serial.println("%");
 
if(Value_O2<=WarningValue)
 {
   digitalWrite(3,HIGH);
 }
 else digitalWrite(3,LOW);
delay(1000);
}
