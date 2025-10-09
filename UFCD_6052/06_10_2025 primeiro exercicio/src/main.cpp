#include <Arduino.h>

// Estrutura para representar um botão
typedef struct {
  int pino; // Número do pino do botão
} Botao;

// Estrutura para representar um LED
typedef struct {
  int pino; // Número do pino do LED
} Led;

// Instâncias dos LEDs e botões com seus respectivos pinos
Led ledEsquerdo = {5};
Led ledDireito = {6};
Botao botao1 = {A0};
Botao botao2 = {A1};
int estado = 0; // Variável para armazenar o estado atual dos botões

void setup() {
  // Configura os pinos dos LEDs como saída
  pinMode(ledEsquerdo.pino, OUTPUT);
  pinMode(ledDireito.pino, OUTPUT);

  // Configura os pinos dos botões como entrada
  pinMode(botao1.pino, INPUT);
  pinMode(botao2.pino, INPUT);

  // Inicializa a comunicação serial
  Serial.begin(9600);
}

void loop() 
{
  // Lê o estado dos botões e define o estado correspondente
  if (digitalRead(botao1.pino) == HIGH && digitalRead(botao2.pino) == HIGH) {
    estado = 0; // Nenhum botão pressionado
  }
  else if (digitalRead(botao1.pino) == LOW && digitalRead(botao2.pino) == HIGH) {
    estado = 1; // Apenas botão 1 pressionado
  }
  else if (digitalRead(botao2.pino) == LOW && digitalRead(botao1.pino) == HIGH) {
    estado = 2; // Apenas botão 2 pressionado
  }
  else if (digitalRead(botao1.pino) == LOW && digitalRead(botao2.pino) == LOW) {
    estado = 3; // Ambos os botões pressionados
  }

  // Executa ações de acordo com o estado dos botões
  switch (estado) {
    case 1:
      digitalWrite(ledEsquerdo.pino, HIGH);  // Liga LED esquerdo
      digitalWrite(ledDireito.pino, LOW);    // Desliga LED direito
      Serial.println("LED esquerdo ligado, LED direito desligado - botao 1 pressionado");
      break;
    case 2:
      digitalWrite(ledEsquerdo.pino, LOW);   // Desliga LED esquerdo
      digitalWrite(ledDireito.pino, HIGH);   // Liga LED direito
      Serial.println("LED direito ligado, LED esquerdo desligado - botao 2 pressionado");
      break;
    case 3:
      digitalWrite(ledEsquerdo.pino, HIGH);  // Liga ambos os LEDs
      digitalWrite(ledDireito.pino, HIGH);
      Serial.println("Ambos os LEDs ligados - ambos botoes pressionados");
      break;
    default:
      digitalWrite(ledEsquerdo.pino, LOW);   // Desliga ambos os LEDs
      digitalWrite(ledDireito.pino, LOW);
      Serial.println("Ambos os LEDs desligados - nenhum botao pressionado");
      break;
  }
  delay(100); // Aguarda 1 segundo antes de repetir o loop
}