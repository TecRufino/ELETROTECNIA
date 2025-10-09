#include <Arduino.h>

int ledEsquerdo = 5;     
int ledDireito = 6;      
int botao1 = A0;         
int botao2 = A1;         
int estado = 0;          

void setup() {
  pinMode(ledEsquerdo, OUTPUT);
  pinMode(ledDireito, OUTPUT);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  if (digitalRead(botao1) == HIGH && digitalRead(botao2) == HIGH) {
    estado = 0; // nenhum pressionado
  }
  else if (digitalRead(botao1) == LOW && digitalRead(botao2) == HIGH) {
    estado = 1; // botão 1 pressionado
  }
  else if (digitalRead(botao2) == LOW && digitalRead(botao1) == HIGH) {
    estado = 2; // botão 2 pressionado
  }
  else if (digitalRead(botao1) == LOW && digitalRead(botao2) == LOW) {
    estado = 3; // ambos pressionados
  }

  switch (estado) {
    case 1:
      digitalWrite(ledEsquerdo, HIGH);
      digitalWrite(ledDireito, LOW);
      Serial.println("LED esquerdo ligado, LED direito desligado - botao 1 pressionado");
      break;
    case 2:
      digitalWrite(ledEsquerdo, LOW);
      digitalWrite(ledDireito, HIGH);
      Serial.println("LED direito ligado, LED esquerdo desligado - botao 2 pressionado");
      break;
    case 3:
      digitalWrite(ledEsquerdo, HIGH);
      digitalWrite(ledDireito, HIGH);
      Serial.println("Ambos os LEDs ligados - ambos botoes pressionados");
      break;
    default:
      digitalWrite(ledEsquerdo, LOW);
      digitalWrite(ledDireito, LOW);
      Serial.println("Ambos os LEDs desligados - nenhum botao pressionado");
      break;
  }
  delay(1000);
}