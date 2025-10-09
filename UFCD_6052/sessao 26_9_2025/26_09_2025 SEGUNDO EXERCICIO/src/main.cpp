#include <Arduino.h>

int teste = -5;

void setup()
{
  Serial.begin(9600);
}

void loop() 
{
  if(teste)
  {
    Serial.println("if");
  }
  else
  {
    Serial.println("else");
  }
  delay(2000);
}  

