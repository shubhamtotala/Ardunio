#include <math.h>
#include <TH02_dev.h>
#include "Arduino.h"
#include "Wire.h"
const int buzzerPin=3; //Connect the Buzzer Grove module to Pin3, Digital 3
float WarningValue= 19.5;  //The minimum sate concentration of O2 in air  
int val;

void setup()
{
   Serial.begin(9600);    //Start the Serial connection
   TH02.begin();
  delay(100);
 
}
void loop()
{
 
  //O2 Sensor Code
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
  delay(20);

    //UV Sensor Code

     long  sum=0;
     for(int i=0;i<1024;i++)
       {  
          sensorValue=analogRead(A1);
          sum=sensorValue+sum;
          delay(2);
       }   
     sum = sum >> 10;
     Serial.print("The voltage value:");
     Serial.print(sum*4980.0/1023.0);
     Serial.println("mV");
     delay(20);
     Serial.print("\n");
 
    //Loudness Sensor Code
 
     //analogRead(0);
     delay(10);
     val = analogRead(A2);
     Serial.println(val);
     delay(20);
     
     //Temperature
     
     
     float temper = TH02.ReadTemperature(); 
   Serial.println("Temperature: ");   
   Serial.print(temper);
   Serial.println("C\r\n");
   
   float humidity = TH02.ReadHumidity();
   Serial.println("Humidity: ");
   Serial.print(humidity);
   Serial.println("%\r\n");
   delay(20);
     
     
}




