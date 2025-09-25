// C++ code
//
int botao = 11;
int led = 13;

void setup() {
  pinMode(botao, INPUT);// entrada 
  pinMode(led, OUTPUT);// saida
}

void loop() {
  if (digitalRead(botao) == HIGH) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}