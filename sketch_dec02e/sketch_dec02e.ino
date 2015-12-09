void setup()
{
  Serial.begin(9600);
  Serial.println("Hi we are making this program");
  pinMode(13,OUTPUT);
}

void loop()
{
  digitalWrite(13,HIGH);
  Serial.println("ON");
  delay(1000);
  digitalWrite(13,LOW);
  Serial.println("OFF");
  delay(1000);
}
