#include <Arduino.h>

// Estrutura para relé
struct Rele {
  int valor;       
  int periferico;  
};

Rele reles[4]; // Array de 4 relés
int botoes[4] = {A0, A1, A2, A3}; // Pinos dos botões
int estados[4] = {LOW, LOW, LOW, LOW}; // Estados dos relés
int botoesAnteriores[4] = {HIGH, HIGH, HIGH, HIGH}; // Estados anteriores dos botões

void setup() {
  Serial.begin(9600);

  // Define os pinos dos relés
  reles[0].periferico = 12;
  reles[1].periferico = 11;
  reles[2].periferico = 10;
  reles[3].periferico = 9;

  // Configura os pinos dos relés como saída
  for (int i = 0; i < 4; i++) {
    pinMode(reles[i].periferico, OUTPUT);
    digitalWrite(reles[i].periferico, LOW);
  }

  // Configura os pinos dos botões como entrada com pull-up
  for (int i = 0; i < 4; i++) {
    pinMode(botoes[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    int leituraBotao = digitalRead(botoes[i]);

    // transição de HIGH para LOW (clique)
    if (botoesAnteriores[i] == HIGH && leituraBotao == LOW) {
      estados[i] = (estados[i] == LOW) ? HIGH : LOW;
      digitalWrite(reles[i].periferico, estados[i]);

      Serial.print("RUFINO deu o comando ");
      Serial.print(i + 1);
      Serial.print(", ");
      Serial.print((estados[i] == HIGH) ? "ligou" : "desligou");
      Serial.print(" rele ");
      Serial.println(i + 1);

      // Aguarda o botão ser solto antes de continuar
      while (digitalRead(botoes[i]) == LOW) {
        delay(10); // pequena pausa para evitar travamento
      }

      delay(200); 
    }

    botoesAnteriores[i] = leituraBotao;
  }
}
