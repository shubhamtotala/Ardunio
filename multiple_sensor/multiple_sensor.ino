#include <math.h> //O2 Sensor

//Co2 
#include <SoftwareSerial.h>
#define DEBUG 0

//Temperature
#include <TH02_dev.h>
#include "Arduino.h"
#include "Wire.h"

//Multigas
#include <Wire.h>
#include "MutichannelGasSensor.h"

 

int val;  //Loudness

//Dust
int pin = 8;
unsigned long duration;
unsigned long starttime;
unsigned long sampletime_ms = 2000;//sampe 30s&nbsp;;
unsigned long lowpulseoccupancy = 0;
float ratio = 0;
float concentration = 0;

//CO2
const int pinRx = 8;
const int pinTx = 7;
 
SoftwareSerial sensor(pinTx,pinRx);
 
const unsigned char cmd_get_sensor[] =
{
    0xff, 0x01, 0x86, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x79
};
unsigned char dataRevice[9];
int temperature;
int CO2PPM;

//o2
const int buzzerPin=3; //Connect the Buzzer Grove module to Pin3, Digital 3
float WarningValue= 19.5;  //The minimum sate concentration of O2 in air  


void setup()
{
  sensor.begin(9600);
  Serial.begin(115200);  
  
  
  //Dust Sensor
  pinMode(8,INPUT);
  starttime = millis();//get the current time; 
  
  //Co2
    Serial.println("get a 'g', begin to read from sensor!");
    Serial.println("********************************************************");
    Serial.println();
    
   //temperature
  Serial.println("****TH02_dev demo by seeed studio****\n");
  /* Power up,delay 150ms,until voltage is stable */
  delay(150);
  /* Reset HP20x_dev */
  TH02.begin();
  delay(100);
  
  /* Determine TH02_dev is available or not */
  Serial.println("TH02_dev is available.\n"); 


  //Multigas
    Serial.println("power on!");

    mutichannelGasSensor.begin(0x04);//the default I2C address of the slave is 0x04
    //mutichannelGasSensor.changeI2cAddr(0x10);
    //mutichannelGasSensor.doCalibrate();

    mutichannelGasSensor.powerOn();   
}

    
 



void loop()
{ 
  Serial.println("Welcome to Multiple Sensor Program");
  Serial.println("Your are having the following choices");
  Serial.println("1.Measure the Loudness");
  Serial.println("2.Measure O2 Concentration");
  Serial.println("3.Measure Dust Concentration");
  Serial.println("4.Measure Co2 Concentration");
  Serial.println("5.Measure Concentration of Multiple gas");
  Serial.println("6.Measure Temperature and Humidity");
  Serial.println("Enter your choice");
  while (Serial.available()==0)
  {
  }
  int ch=Serial.parseInt();
  
  switch(ch)
  {
    case 1:     //Loudness
    
      analogRead(0);
	delay(10);
	val = analogRead(0);
	Serial.println(val);
	delay(200);
    break;
    
    
    
    case 2:    //O2
    
    //long unsigned a;
float sensorValue;
float sensorVoltage; 
float Value_O2;
sensorValue = analogRead(A1);
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


break;



  case 3:   //Dust
  
  
  duration = pulseIn(pin, LOW);
  lowpulseoccupancy = lowpulseoccupancy+duration;
 
  if ((millis()-starttime) >= sampletime_ms)//if the sampel time = = 30s
  {
    ratio = lowpulseoccupancy/(sampletime_ms*10.0);  // Integer percentage 0=&gt;100
    concentration = 1.1*pow(ratio,3)-3.8*pow(ratio,2)+520*ratio+0.62; // using spec sheet curve
    Serial.print("concentration = ");
    Serial.print(concentration);
    Serial.println(" pcs/0.01cf");
    Serial.println("\n");
    lowpulseoccupancy = 0;
    starttime = millis();
  }    
    break;
    
    
    case 4: //Co2 
 
      
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print("  CO2: ");
        Serial.print(CO2PPM);
        Serial.println("");
    delay(1000);
    
    break;
    
    case 5:    //Multiple Gas
    
    float c;

    c = mutichannelGasSensor.measure_NH3();
    Serial.print("The concentration of NH3 is ");
    if(c>=0) Serial.print(c);
    else Serial.print("invalid");
    Serial.println(" ppm");

    c = mutichannelGasSensor.measure_CO();
    Serial.print("The concentration of CO is ");
    if(c>=0) Serial.print(c);
    else Serial.print("invalid");
    Serial.println(" ppm");

    c = mutichannelGasSensor.measure_NO2();
    Serial.print("The concentration of NO2 is ");
    if(c>=0) Serial.print(c);
    else Serial.print("invalid");
    Serial.println(" ppm");

    c = mutichannelGasSensor.measure_C3H8();
    Serial.print("The concentration of C3H8 is ");
    if(c>=0) Serial.print(c);
    else Serial.print("invalid");
    Serial.println(" ppm");

    c = mutichannelGasSensor.measure_C4H10();
    Serial.print("The concentration of C4H10 is ");
    if(c>=0) Serial.print(c);
    else Serial.print("invalid");
    Serial.println(" ppm");

    c = mutichannelGasSensor.measure_CH4();
    Serial.print("The concentration of CH4 is ");
    if(c>=0) Serial.print(c);
    else Serial.print("invalid");
    Serial.println(" ppm");

    c = mutichannelGasSensor.measure_H2();
    Serial.print("The concentration of H2 is ");
    if(c>=0) Serial.print(c);
    else Serial.print("invalid");
    Serial.println(" ppm");

    c = mutichannelGasSensor.measure_C2H5OH();
    Serial.print("The concentration of C2H5OH is ");
    if(c>=0) Serial.print(c);
    else Serial.print("invalid");
    Serial.println(" ppm");

    delay(1000);
    Serial.println("...");
    
    break;
    
    
    
    case 6:  //temperature
    
    
    float temper = TH02.ReadTemperature(); 
   Serial.println("Temperature: ");   
   Serial.print(temper);
   Serial.println("C\r\n");
   
   float humidity = TH02.ReadHumidity();
   Serial.println("Humidity: ");
   Serial.print(humidity);
   Serial.println("%\r\n");
   delay(1000);
    
    break;
    
    
  }
  }
  
   
    
              



