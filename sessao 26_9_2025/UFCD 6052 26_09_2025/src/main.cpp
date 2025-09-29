#include <Arduino.h>

const int Botao = A0;
const int led = 2;

void setup() {
Serial.begin(115200);
pinMode(Botao, INPUT);
pinMode(led, OUTPUT);
}

void loop()
{

  Serial.println(digitalRead(Botao));
  if (digitalRead(Botao) == LOW)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
 delay(100);
}