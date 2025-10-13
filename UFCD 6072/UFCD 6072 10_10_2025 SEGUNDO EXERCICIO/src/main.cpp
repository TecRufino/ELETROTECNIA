#include <Arduino.h>
//estrutura temporizador
struct Temporizador
{
  unsigned long int tempo_anterior;
  unsigned long int intervalo;
  
};
//estrutura rele 
struct rele
{
  int valor;//valor do rele
  int periferico;//pino do rele
  Temporizador temporizador;//estrutura temporizador
};
rele rele1;// 1 rele
rele rele2;// 2 rele
rele rele3;// 3 rele





void setup()
{
  Serial.begin(9600);
  rele1.temporizador.intervalo = 5000; //5 segundos
  rele2.temporizador.intervalo = 7000;//10 segundos
  rele3.temporizador.intervalo = 9000;//15 segundos
  rele1.temporizador.tempo_anterior = millis();//inicia o tempo anterior com o tempo atual
  rele2.temporizador.tempo_anterior = millis();//inicia o tempo anterior com o tempo atual
  rele3.temporizador.tempo_anterior = millis();//inicia o tempo anterior com o tempo atual
  rele1.periferico = 12;//pino do rele 1
  rele2.periferico = 11;//pino do rele 2
  rele3.periferico = 10;//pino do rele 3
  pinMode(rele1.periferico, OUTPUT);//configura o pino do rele 1 como saída
  pinMode(rele2.periferico, OUTPUT);//configura o pino do rele 2 como saída
  pinMode(rele3.periferico, OUTPUT);//configura o pino do rele 3 como saída

  digitalWrite(rele1.periferico, LOW);// OS RELES COMEÇAM DESLIGADOR 
  digitalWrite(rele2.periferico, LOW);// OS RELES COMEÇAM DESLIGADOR
  digitalWrite(rele3.periferico, LOW);// OS RELES COMEÇAM DESLIGADOR
}



void loop()
{
  if (millis() - rele1.temporizador.tempo_anterior > rele1.temporizador.intervalo)
  {
    Serial.println("RUFINO DEU O COMANDO PARA RELE 1 LIGADO");
    // alterna o estado do rele1
    if (digitalRead(rele1.periferico) == LOW)//se o rele estiver desligado
    {
      digitalWrite(rele1.periferico, HIGH);//liga o rele
    }
    else
    {
      digitalWrite(rele1.periferico, LOW);//desliga o rele
    }
    rele1.temporizador.tempo_anterior = millis();//atualiza o tempo anterior
  }





  if (millis() - rele2.temporizador.tempo_anterior > rele2.temporizador.intervalo)//se o tempo atual - tempo anterior for maior que o intervalo do rele2
  {
    Serial.println("RUFINO DEU O COMANDO PARA RELE 2 LIGADO");//mensagem no monitor serial
   
    if (digitalRead(rele2.periferico) == LOW)//se o rele2 estiver desligado
    {
      digitalWrite(rele2.periferico, HIGH);//liga o rele2
    }
    else//se o rele2 estiver ligado
    {
      digitalWrite(rele2.periferico, LOW);//desliga o rele2
    }
    rele2.temporizador.tempo_anterior = millis();//atualiza o tempo anterior
}

if (millis() - rele3.temporizador.tempo_anterior > rele3.temporizador.intervalo)//se o tempo atual - tempo anterior for maior que o intervalo do rele3
{ 
  Serial.println("RUFINO DEU O COMANDO PARA RELE 3 LIGADO");//mensagem no monitor serial

  if(digitalRead(rele3.periferico) == LOW)//se o rele3 estiver desligado
  {
    digitalWrite(rele3.periferico, HIGH);//liga o rele3
  }
  else//se o rele3 estiver ligado
  {
    digitalWrite(rele3.periferico, LOW);//desliga o rele3
  }
  
  rele3.temporizador.tempo_anterior = millis();//atualiza o tempo anterior
  /* code */
}

} 
