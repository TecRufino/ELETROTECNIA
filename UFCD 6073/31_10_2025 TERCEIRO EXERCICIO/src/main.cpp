#include <Arduino.h>

const int numBotoes = 5;
const int numLeds = 5;

// Pinos dos botões: CIMA, BAIXO, ESQUERDA, DIREITA, MEIO
const int botoes[numBotoes] = {2, 3, 4, 5, 6};
// Pinos dos LEDs correspondentes
const int leds[numLeds] = {8, 9, 10, 11, 12};

// Nomes dos botões
const char* nomesBotoes[numBotoes] = {"CIMA", "BAIXO", "ESQUERDA", "DIREITA", "MEIO"}; // BOTAO 1 = 0001. BOTAO 2 = 0010. BOTAO 3 = 0100. BOTAO 4 = 1000.

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < numBotoes; i++) {
    pinMode(botoes[i], INPUT_PULLUP);
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  int estado = 0;

  // Lê todos os botões e calcula estado (bitmask)
  for (int i = 0; i < numBotoes; i++) {
    if (digitalRead(botoes[i]) == LOW) {
      estado |= (1 << i);
    }
  }

  // Apaga todos os LEDs
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], LOW);
  }

  // Acende LEDs conforme estado
  for (int i = 0; i < numLeds; i++) {
    if (estado & (1 << i)) {
      digitalWrite(leds[i], HIGH);
    }
  }

  // Identifica combinação com switch-case
  switch (estado) {
    case 0:
      Serial.println("Nenhum botão pressionado");
      break;
    case 1:
      Serial.println("CIMA");
      break;
    case 2:
      Serial.println("BAIXO");
      break;
    case 4:
      Serial.println("ESQUERDA");
      break;
    case 8:
      Serial.println("DIREITA");
      break;
    case 16:
      Serial.println("MEIO");
      break;
    case 3:
      Serial.println("CIMA + BAIXO");
      break;
    case 5:
      Serial.println("CIMA + ESQUERDA");
      break;
    case 9:
      Serial.println("CIMA + DIREITA");
      break;
    case 17:
      Serial.println("CIMA + MEIO");
      break;
    case 6:
      Serial.println("BAIXO + ESQUERDA");
      break;
    case 10:
      Serial.println("BAIXO + DIREITA");
      break;
    case 18:
      Serial.println("BAIXO + MEIO");
      break;
    case 12:
      Serial.println("ESQUERDA + DIREITA");
      break;
    case 20:
      Serial.println("ESQUERDA + MEIO");
      break;
    case 24:
      Serial.println("DIREITA + MEIO");
      break;
    // Adicione mais combinações conforme necessário
    case 31:
      Serial.println("TODOS OS BOTÕES");
      break;
    default:
      Serial.print("Combinação personalizada: ");
      for (int i = 0; i < numBotoes; i++) {
        if (estado & (1 << i)) {
          Serial.print(nomesBotoes[i]);
          Serial.print(" ");
        }
      }
      Serial.println();
      break;
  }

  delay(200);
}