#include <Arduino.h>

const int BAUT_RATE = 9600;
const int botao = A0; 

void setup() {
	Serial.begin(BAUT_RATE);
	pinMode(botao, INPUT);
}

void loop() {
	while (digitalRead(botao) == LOW) {
		Serial.println("Botao pressionado");
		delay(500);
	}
	Serial.println("Botao solto");
	delay(500);
}
