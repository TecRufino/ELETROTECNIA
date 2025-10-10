#include <Arduino.h>

// Estrutura para temporizador
typedef struct {
  unsigned long intervalo;
  unsigned long tempoAnterior;
  bool estado;
  int pino;
} Temporizador;

// Relés nos pinos 8 e 9, alternam a cada 10 segundos
Temporizador rele1 = {10000, 0, false, 8};
Temporizador rele2 = {10000, 0, false, 9};

void setup() {
  Serial.begin(9600);
  pinMode(rele1.pino, OUTPUT);
  pinMode(rele2.pino, OUTPUT);
}

void loop() {
  unsigned long tempoAtual = millis();

  // Temporizador do relé 1
  if (tempoAtual - rele1.tempoAnterior >= rele1.intervalo) {
    rele1.estado = !rele1.estado;
    digitalWrite(rele1.pino, rele1.estado ? HIGH : LOW);
    Serial.println(rele1.estado ? "RUFINO ligou o Relé 1!" : "RUFINO desligou o Relé 1!");
    rele1.tempoAnterior = tempoAtual;
  }

  // Temporizador do relé 2
  if (tempoAtual - rele2.tempoAnterior >= rele2.intervalo) {
    rele2.estado = !rele2.estado;
    digitalWrite(rele2.pino, rele2.estado ? HIGH : LOW);
    Serial.println(rele2.estado ? "RUFINO ligou o Relé 2!" : "RUFINO desligou o Relé 2!");
    rele2.tempoAnterior = tempoAtual;
  }
}























