#include <Arduino.h>

const int botao1 = 2;
const int botao2 = 3;
const int botao3 = 4;
const int botao4 = 5;
const int botao5 = 6; 

const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;
const int led5 = 12; 

void setup() {
  Serial.begin(9600); // Inicializa comunicação serial
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
  pinMode(botao4, INPUT_PULLUP);
  pinMode(botao5, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {
  int estado = 0;

  if (digitalRead(botao1) == LOW) estado += 1;
  if (digitalRead(botao2) == LOW) estado += 2;
  if (digitalRead(botao3) == LOW) estado += 4;
  if (digitalRead(botao4) == LOW) estado += 8;
  if (digitalRead(botao5) == LOW) estado += 16;

  // Apaga todos os LEDs
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);

  switch (estado) {
    case 0: Serial.println("Nenhum botão pressionado"); break;
    case 1: digitalWrite(led1, HIGH); Serial.println("Botão 1"); break;
    case 2: digitalWrite(led2, HIGH); Serial.println("Botão 2"); break;
    case 4: digitalWrite(led3, HIGH); Serial.println("Botão 3"); break;
    case 8: digitalWrite(led4, HIGH); Serial.println("Botão 4"); break;
    case 16: digitalWrite(led5, HIGH); Serial.println("Botão 5"); break;

    // Exemplos de combinações (adicione mais conforme necessário)
    case 3: digitalWrite(led1, HIGH); digitalWrite(led2, HIGH); Serial.println("Botões 1 e 2"); break;
    case 7: digitalWrite(led1, HIGH); digitalWrite(led2, HIGH); digitalWrite(led3, HIGH); Serial.println("Botões 1, 2 e 3"); break;
    case 31: digitalWrite(led1, HIGH); digitalWrite(led2, HIGH); digitalWrite(led3, HIGH); digitalWrite(led4, HIGH); digitalWrite(led5, HIGH); Serial.println("Todos os botões"); break;

    default:
      Serial.print("Combinação personalizada: ");
      if (estado & 1) Serial.print("Botão 1 ");
      if (estado & 2) Serial.print("Botão 2 ");
      if (estado & 4) Serial.print("Botão 3 ");
      if (estado & 8) Serial.print("Botão 4 ");
      if (estado & 16) Serial.print("Botão 5 ");
      Serial.println();
      break;
  }

  delay(200);
}
