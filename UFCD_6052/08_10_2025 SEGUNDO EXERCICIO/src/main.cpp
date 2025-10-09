#include <Arduino.h>

// Estrutura para representar um botão
typedef struct {
  int pino;
} Botao;

// Entrada dos botões no Arduino
Botao botaoCima = {A0};
Botao botaoBaixo = {A1};
Botao botaoEsquerdo = {A2};
Botao botaoDireito = {A3};

// Arranque do programa
void setup() {
  pinMode(botaoCima.pino, INPUT);
  pinMode(botaoBaixo.pino, INPUT);
  pinMode(botaoEsquerdo.pino, INPUT);
  pinMode(botaoDireito.pino, INPUT);

  Serial.begin(9600);
}

// Execução do programa, repetindo o mesmo sempre
void loop() {
  bool cima = digitalRead(botaoCima.pino) == LOW;
  bool baixo = digitalRead(botaoBaixo.pino) == LOW;
  bool esquerdo = digitalRead(botaoEsquerdo.pino) == LOW;
  bool direito = digitalRead(botaoDireito.pino) == LOW;

  // Verifica combinações de dois botões para diagonais
  if (cima && esquerdo) {
    Serial.println("Movimento diagonal superior esquerda");
  } else if (cima && direito) {
    Serial.println("Movimento diagonal superior direita");
  } else if (baixo && esquerdo) {
    Serial.println("Movimento diagonal inferior esquerda");
  } else if (baixo && direito) {
    Serial.println("Movimento diagonal inferior direita");
  }
  // Se apenas um botão estiver pressionado
  else if (cima) {
    Serial.println("Botão cima. Para o alto e avante");
  } else if (baixo) {
    Serial.println("Botão baixo. I don't like");
  } else if (esquerdo) {
    Serial.println("Botão esquerdo. Heeelp");
  } else if (direito) {
    Serial.println("Botão direito. Correeeee");
  } else {
    Serial.println("Esperando o comando de RUFINO");
  }

  delay(100);
}
