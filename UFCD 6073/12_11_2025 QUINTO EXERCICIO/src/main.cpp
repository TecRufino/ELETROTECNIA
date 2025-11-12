#include <Arduino.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configuração do DHT22
#define DHTPIN 6
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Botões
const int botao1 = 2;
const int botao2 = 3;
const int botao3 = 4;
const int botao4 = 5;

// LEDs (agora 4)
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;

int ultimoEstado = -1;
unsigned long ultimoTempo = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();

  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
  pinMode(botao4, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Sistema Iniciado");
  delay(2000);
  lcd.clear();
}

void loop() {
  int estado = 0;

  if (digitalRead(botao1) == LOW) estado += 1;
  if (digitalRead(botao2) == LOW) estado += 2;
  if (digitalRead(botao3) == LOW) estado += 4;
  if (digitalRead(botao4) == LOW) estado += 8;

  // Atualiza LEDs sem piscar
  digitalWrite(led1, (estado & 1) ? HIGH : LOW);
  digitalWrite(led2, (estado & 2) ? HIGH : LOW);
  digitalWrite(led3, (estado & 4) ? HIGH : LOW);
  digitalWrite(led4, (estado & 8) ? HIGH : LOW);

   // Atualiza temperatura/umidade a cada 1 segundo
  if (millis() - ultimoTempo > 1000) {
    float temperatura = dht.readTemperature();
    float umidade = dht.readHumidity();

    lcd.setCursor(0, 1);
    lcd.print("                "); // Limpa linha
    lcd.setCursor(0, 1);

    if (isnan(temperatura) || isnan(umidade)) {
      lcd.print("Erro DHT22");
    } else {
      lcd.print("T:");
      lcd.print(temperatura);
      lcd.print("C U:");
      lcd.print(umidade);
      lcd.print("%");
    }
    ultimoTempo = millis();
    
  // Atualiza LCD apenas se estado mudou
  if (estado != ultimoEstado) {
    lcd.setCursor(0, 0);
    lcd.print("                "); // Limpa linha
    lcd.setCursor(0, 0);

    switch (estado) {
      case 0: lcd.print("Nenhum Botao"); break;
      case 1: lcd.print("Botao 1"); break;
      case 2: lcd.print("Botao 2"); break;
      case 3: lcd.print("Botoes 1 e 2"); break;
      case 4: lcd.print("Botao 3"); break;
      case 5: lcd.print("Botoes 1 e 3"); break;
      case 6: lcd.print("Botoes 2 e 3"); break;
      case 7: lcd.print("Botoes 1,2,3"); break;
      case 8: lcd.print("Botao 4"); break;
      case 9: lcd.print("Botoes 1 e 4"); break;
      case 10: lcd.print("Botoes 2 e 4"); break;
      case 11: lcd.print("Botoes 1,2,4"); break;
      case 12: lcd.print("Botoes 3 e 4"); break;
      case 13: lcd.print("Botoes 1,3,4"); break;
      case 14: lcd.print("Botoes 2,3,4"); break;
      case 15: lcd.print("Todos os botoes"); break;
    }
    ultimoEstado = estado;
  }

 
  }
}