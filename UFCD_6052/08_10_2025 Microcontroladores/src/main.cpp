#include <Arduino.h>

unsigned long tempoatual = 0;
unsigned long tempoanterior = 1000; 

int ledPin1 = 13;
int ledPin2 = 12;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  tempoatual = millis();
  Serial.println(tempoatual);

  if (tempoatual - tempoanterior > 1000) { // 1s
    Serial.print("tempo atual: ");
    Serial.println(tempoatual);

    Serial.print("tempo anterior: ");
    Serial.println(tempoanterior);

    // Alterna o estado do LED 1
    digitalWrite(ledPin1, !digitalRead(ledPin1));

    // Alterna o estado do LED 2
    digitalWrite(ledPin2, !digitalRead(ledPin2));

    tempoanterior = millis(); // Atualiza o tempo
  }

  delay(100);
}
