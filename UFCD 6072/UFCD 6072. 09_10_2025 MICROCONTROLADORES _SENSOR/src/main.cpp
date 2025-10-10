#include <Arduino.h>

unsigned long tempoatual = 0;
unsigned long tempoanterior = 0;

const int ledPin1 = 13;
const int ledPin2 = 12;
const int botaoPin = 7;

bool botaoPressionado = false;
unsigned long tempoBotaoPressionado = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(botaoPin, INPUT_PULLUP); 
}

void loop() {
  tempoatual = millis();

  
  if (digitalRead(botaoPin) == LOW && !botaoPressionado) {
    botaoPressionado = true;
    tempoBotaoPressionado = millis(); // Marca o tempo do botao precionado
    Serial.println("Comando do RUFINO");
  }

  // Após 2 segundos apertando o botao, acende os dois LEDs
  if (botaoPressionado && (millis() - tempoBotaoPressionado >= 2000)) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    botaoPressionado = false; // Reseta o estado
    Serial.println("RUFINO DEU O COMANDO PARA LIGAR OS LEDS"); // comando a executar depois da ordem do Rufino
  
  }

  delay(50); 
}