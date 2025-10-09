#include <Arduino.h>

// Estrutura para representar um botoes 
typedef struct {
  int pino;
} Botao;  
// entrada dos botoes no arduino
Botao botaoCima = {A0}; 
Botao botaoBaixo = {A1};
Botao botaoEsquerdo = {A2};
Botao botaoDireito = {A3};
// arranque do programa
void setup() {  
  pinMode(botaoCima.pino, INPUT);
  pinMode(botaoBaixo.pino, INPUT);
  pinMode(botaoEsquerdo.pino, INPUT);
  pinMode(botaoDireito.pino, INPUT);

  Serial.begin(9600);
}
// execusao do programa, repetindo o mesmo sempre.
void loop() 
{  
  bool cima = digitalRead(botaoCima.pino) == LOW;
  bool baixo = digitalRead(botaoBaixo.pino) == LOW;
  bool esquerdo = digitalRead(botaoEsquerdo.pino) == LOW;
  bool direito = digitalRead(botaoDireito.pino) == LOW;

  // defificoes para cada botao
  int estado = 0;
  if (cima) estado = 1;
  else if (baixo) estado = 2;
  else if (esquerdo) estado = 3;
  else if (direito) estado = 4;

  //
  switch (estado) {
    case 1:
      Serial.println("Botao cima. para o alto e avante");
      break;
    case 2:
      Serial.println("Botao baixo. helpeeeeee");
      break;
    case 3:
      Serial.println("Botao esquerdo correee");
      break;
    case 4:
      Serial.println("Botao direito. ficaaaa");
      break;
    default:
      Serial.println("aguardando a ordem do RUFINO");
      break;
  }

  delay(100);
}