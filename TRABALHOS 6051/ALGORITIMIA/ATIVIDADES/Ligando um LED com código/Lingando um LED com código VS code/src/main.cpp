; PlatformIO Project Configuration File
;// C++ code
//
int ledPin = 3;


void setup() //É o lugar perfeito para colocar todas as instruções que só precisam ser executadas uma vez
{
  pinMode(ledPin, OUTPUT); //"O pino que eu chamei de ledPin deve ser usado para enviar energia para algo."
}

void loop() // fica rodando repetidamente para sempre
{
  digitalWrite(ledPin, HIGH);//( ligado)É o nome da variável que você usou para se referir ao pino físico do Arduino (por exemplo, o pino 3).
  delay(1000); // Wait for 1000 millisecond(s)é um comando muito comum no Arduino que diz ao programa para parar e esperar.
  digitalWrite(ledPin, LOW);//( desligado) é um comando básico do Arduino que serve para desligar um componente eletrônico.
  delay(1000); // Wait for 1000 millisecond(s)
}
;  