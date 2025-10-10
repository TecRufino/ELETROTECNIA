#include <Arduino.h>

// Estrutura para temporizador
typedef struct {
  unsigned long intervalo;
  unsigned long tempoAnterior;
} Temporizador;

// Criação dos temporizadores
Temporizador temporizador1 = {1000, 0}; // 1 segundo
Temporizador temporizador2 = {3000, 0}; // 3 segundos

int valor = 0;
int periferico = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long tempoAtual = millis();

  
  if (tempoAtual - temporizador1.tempoAnterior >= temporizador1.intervalo) {
    Serial.println("Temporizador 1: Passou 1 segundo!");
    valor = analogRead(periferico);
    Serial.print("RUFINO deu O Valor do sensor: ");
    Serial.println(valor);
    temporizador1.tempoAnterior = tempoAtual;
  }

  // Temporizador 2: ação a cada 3 segundos
  if (tempoAtual - temporizador2.tempoAnterior >= temporizador2.intervalo) {
    Serial.println("Temporizador 2: Passaram 3 segundos!");
    temporizador2.tempoAnterior = tempoAtual;
  }
}
