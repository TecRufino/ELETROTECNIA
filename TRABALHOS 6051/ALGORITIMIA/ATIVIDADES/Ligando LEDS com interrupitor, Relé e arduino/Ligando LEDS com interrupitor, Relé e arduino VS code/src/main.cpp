int rele = A0;       // Pino do relé
int botao = 2;       // Pino do botão
unsigned long tempoAnterior = 0;
int intervalo = 3000;

void setup() {
  pinMode(rele, OUTPUT);
  pinMode(botao, INPUT_PULLUP); // Usa resistor interno
  digitalWrite(rele, LOW);
}

void loop() {
  // Verifica se o botão está pressionado
  if (digitalRead(botao) == LOW) {
    intervalo = 300;  // Pisca rápido enquanto pressionado
  } else {
    intervalo = 2000; // Pisca lento quando solto
  }

  // Controle de tempo sem delay
  unsigned long tempoAtual = millis();
  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;
    digitalWrite(rele, !digitalRead(rele)); // Alterna estado do relé
  }
}