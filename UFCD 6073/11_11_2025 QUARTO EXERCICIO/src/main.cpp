#include "DHT.h"
#include <LiquidCrystal_I2C.h>

// Configuração do LCD e do DHT 
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DHTPIN   6
#define DHTTYPE  DHT22
DHT dht(DHTPIN, DHTTYPE);


#define LED_VERDE    4   // Aquecimento ON
#define LED_VERMELHO 5   // Aquecimento OFF
#define LED_AMARELO  7   // Faixa neutra


float T0 = 24.0;   // Liga abaixo de T0
float T1 = 26.0;   // Desliga acima de T1


bool aquecimento = false;

void setup() {
  Serial.begin(115200);
  Serial.println(F("Termóstato Digital - DHT22"));
  Serial.println(F("Autor: Igor Rufino"));

  dht.begin();

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);

  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_VERMELHO, HIGH);
  digitalWrite(LED_AMARELO, LOW);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(F("Termostato DHT22"));
  lcd.setCursor(0, 1);
  lcd.print(F("Autor: Igor Rufino"));
  delay(1500);
  lcd.clear();
}

void loop() {
  float temperatura = dht.readTemperature();
  float humidade    = dht.readHumidity();

  if (isnan(temperatura) || isnan(humidade)) {
    Serial.println(F("Erro de leitura no DHT22"));
    lcd.setCursor(0, 0);
    lcd.print(F("Erro no sensor  "));
    lcd.setCursor(0, 1);
    lcd.print(F("Verifique cabos "));
    delay(2000);
    return;
  }

  // --- Controle com histerese ---
  if (temperatura > T1 && aquecimento) {
    aquecimento = false;
  }
  else if (temperatura < T0 && !aquecimento) {
    aquecimento = true;
  }

  // --- LEDs ---
  if (aquecimento) {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AMARELO, LOW);
  } else if (temperatura >= T0 && temperatura <= T1) {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AMARELO, HIGH);
  } else {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_AMARELO, LOW);
  }

  // --- Saída série ---
  Serial.print(F("Temp: "));
  Serial.print(temperatura, 1);
  Serial.print(F(" ºC  Hum: "));
  Serial.print(humidade, 1);
  Serial.print(F("%  Estado: "));
  Serial.println(aquecimento ? F("ON") : F("OFF"));

  // --- LCD ---
  lcd.setCursor(0, 0);
  lcd.print(F("T:"));
  lcd.print(temperatura, 1);
  lcd.print((char)223);
  lcd.print("C ");
  lcd.setCursor(9, 0);
  lcd.print(F("H:"));
  lcd.print(humidade, 0);
  lcd.print("% ");

  lcd.setCursor(0, 1);
  lcd.print(F("Aquec: "));
  lcd.print(aquecimento ? F("ON ") : F("OFF"));

  delay(1000);
}