#include <Arduino.h>

#define BOTAO_PIN A0         // Pino do botão
#define RELE_PIN  7          // Pino do relé
#define CONTATOR_LEITURA A5  // Pino de leitura do contator (contato auxiliar)

int estadoRele = LOW;
int botaoAnterior = HIGH;

void setup() {
  Serial.begin(9600);

  pinMode(BOTAO_PIN, INPUT_PULLUP);
  pinMode(RELE_PIN, OUTPUT);
  digitalWrite(RELE_PIN, LOW);

  pinMode(CONTATOR_LEITURA, INPUT_PULLUP); // ou INPUT se vier sinal direto
}

void loop() {
  int leituraBotao = digitalRead(BOTAO_PIN);

  // Detecta clique no botão
  if (botaoAnterior == HIGH && leituraBotao == LOW) {
    estadoRele = (estadoRele == LOW) ? HIGH : LOW;
    digitalWrite(RELE_PIN, estadoRele);

    Serial.print("Botão pressionado - Relé ");
    Serial.println(estadoRele == HIGH ? "LIGADO" : "DESLIGADO");

    delay(200); 
  }

  botaoAnterior = leituraBotao;

  // Leitura do estado do contator
  int leituraContator = digitalRead(CONTATOR_LEITURA);
  Serial.print("Estado do Contator (A5): ");
  Serial.println(leituraContator == LOW ? "LIGADO" : "DESLIGADO");

  delay(500); // intervalo entre leituras
}