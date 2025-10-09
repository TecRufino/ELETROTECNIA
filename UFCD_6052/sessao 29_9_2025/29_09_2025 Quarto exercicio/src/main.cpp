#include <Arduino.h>


int led = 5;     // Pino do LED
int botao1 = A0;   // Pino do botao 1 aquecimento
int botao2 = A1;   // Pino do botão 2 resfriamento
int estado = 0; // variável de estado

void ligaLed() {
  digitalWrite(led, HIGH); // Liga o LED
}
void desligaLed() {
  digitalWrite(led, LOW); // Desliga o LED
}
void setup() {
  pinMode(led, OUTPUT);      //  LED  portão como saída
  pinMode(botao1, INPUT);    // botão 1 portA DE entrada
  pinMode(botao2, INPUT);   // Define botão 2 PORTA DE entrada
  Serial.begin(9600);     // comunicação serial QUE TAMBEM PODE SER 115200
}





void loop() 
{
  if (digitalRead(botao1) == HIGH && digitalRead(botao2) == HIGH) {
    estado = 0; // nenhum pressionado
  }
  else if (digitalRead(botao1) == LOW && digitalRead(botao2) == HIGH) {
    estado = 1; // aquecimento
  }
  else if (digitalRead(botao2) == LOW && digitalRead(botao1) == HIGH) {
    estado = 2; // resfriamento
  }
  else if (digitalRead(botao1) == LOW && digitalRead(botao2) == LOW) {
    estado = 3; // ambos pressionados
  }
 
  switch (estado) {
    case 1:
      ligaLed();
      Serial.println("em aquecimento");
      break;
    case 2:
      ligaLed();
      Serial.println("em resfriamento");
      break;
    case 3:
      ligaLed();
      Serial.println("entrando em temperatura ambiente");
      break;
    default:
      desligaLed();
      Serial.println("stand by");
      break;
  }
  delay(100);
}