#include <Arduino.h>

unsigned long tempoatual = 0;
unsigned long tempoanterior = 1000; // Inicializa com 1 segundo para evitar acionamento imediato
int ledPin = 13;
int led2 = 12;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  tempoatual = millis();
  Serial.println(tempoatual);

  if (tempoatual - tempoanterior > 1000) { // 1 segundo
    Serial.print("tempo atual: ");
    Serial.println(tempoatual);

    Serial.print("tempo anterior: ");
    Serial.println(tempoanterior);

    if (digitalRead(ledPin) == LOW) {
      digitalWrite(ledPin, HIGH); // Liga o LED
    } else {
      digitalWrite(ledPin, LOW); // Desliga o LED
    }

    tempoanterior = millis(); // Atualiza o tempo anterior
  }

  delay(100);
}
