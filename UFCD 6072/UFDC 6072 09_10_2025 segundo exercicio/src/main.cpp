#include <Arduino.h>

unsigned long tempoatual = 0;
unsigned long tempoanterior = 0;

const int ledPin1 = 13;
const int ledPin2 = 12;
const int botaoPin = 7;

bool botaoPressionado = false;
bool ledsLigados = false;
unsigned long tempoBotaoPressionado = 0;
unsigned long tempoLedsLigados = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(botaoPin, INPUT_PULLUP); 
}

void loop() {
  tempoatual = millis();

  // Verifica se o botão foi pressionado
  if (digitalRead(botaoPin) == LOW && !botaoPressionado && !ledsLigados) {
    botaoPressionado = true;
    tempoBotaoPressionado = millis();
    Serial.println("Comando do RUFINO");
  }

  // Após 2 segundos segurando o botão, liga os LEDs
  if (botaoPressionado && (millis() - tempoBotaoPressionado >= 2000)) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    ledsLigados = true;
    tempoLedsLigados = millis(); // Marca o tempo em que os LEDs foram ligados
    botaoPressionado = false;
    Serial.println("RUFINO DEU O COMANDO PARA LIGAR OS LEDS");
  }

  // Após 10 segundos com os LEDs ligados, desliga
  if (ledsLigados && (millis() - tempoLedsLigados >= 10000)) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    ledsLigados = false;
    Serial.println("LEDs desligados após 10 segundos");
  }

  delay(50); 
}