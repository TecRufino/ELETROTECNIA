#include <Arduino.h> 


// Definição dos pinos dos botões
const int botaoIniciar = 2; // Botão para iniciar medição
const int botaoMaximo = 3;  // Botão para detectar máximo
const int botaoAmbos = 4;   // Botão para executar ambas funções juntas
const int botaoAmbos2 = 5;  // Segundo botão para executar ambas juntas

// Variáveis de controle
bool medindo = false; // Indica se está medindo temperatura
int temperatura = 0;  // Valor simulado da temperatura
const int temperaturaMaxima = 80; // Temperatura máxima permitida


void setup() {
  Serial.begin(9600); 
  pinMode(botaoIniciar, INPUT); // Configura botão iniciar como entrada
  pinMode(botaoMaximo, INPUT);  // Configura botão máximo como entrada
  pinMode(botaoAmbos, INPUT);   // Configura botão ambos como entrada
  pinMode(botaoAmbos2, INPUT);  // Configura botão ambos2 como entrada
}


void loop() {
  // Leitura dos botões e definição do comando
  int comando = 0; // Variável para armazenar comando do botão
  bool b1 = digitalRead(botaoIniciar) == LOW; // Estado do botão 1
  bool b2 = digitalRead(botaoMaximo) == LOW;  // Estado do botão 2

  // Corrige as condições para cada caso
  if (b1 && b2) {
    comando = 1; // Só botão 1 pressionado
  } else if (b1 && b2) {
    comando = 2; // Só botão 2 pressionado
  } else if (b1 && b2) {
    comando = 3; // Ambos pressionados
  } else {
    comando = 0; // Nenhum pressionado
  }

  switch (comando) {
    case 1: // Só botão 1 pressionado
      Serial.println("Função do botão 1 executada"); // Executa função do botão 1
      delay(300); //tempo de repetição
      break;
    case 2: // Só botão 2 pressionado
      Serial.println("Função do botão 2 executada"); // Executa função do botão 2
      delay(300); // tempo de repetição
      break;
    case 3: // Ambos pressionados
      Serial.println("Função dos dois botões juntos executada"); // Executa função dos dois juntos
      delay(300); // tempo de repetição
      break;
    case 0:
    default:
      // Não faz nada
      break;
  }
}