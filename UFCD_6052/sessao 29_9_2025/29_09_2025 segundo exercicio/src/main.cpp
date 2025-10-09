#include <Arduino.h>

const int BAUT_RATE = 9600;
const int botao = A0; 
const int led = 13; // LED no pino 13

void setup() {
	Serial.begin(BAUT_RATE);
	pinMode(botao, INPUT);
	pinMode(led, OUTPUT);
}

void loop() {
	if (digitalRead(botao) == LOW) {
		Serial.println("Botao pressionado");
		digitalWrite(led, HIGH); // Acende o LED
	} else {
		Serial.println("Botao solto");
		digitalWrite(led, LOW); // Apaga o LED
	}
	delay(500);
}