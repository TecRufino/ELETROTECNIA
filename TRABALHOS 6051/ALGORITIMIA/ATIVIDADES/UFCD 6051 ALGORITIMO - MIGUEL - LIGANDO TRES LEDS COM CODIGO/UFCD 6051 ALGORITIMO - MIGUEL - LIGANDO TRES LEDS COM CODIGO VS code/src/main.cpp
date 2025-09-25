void setup()
{
  pinMode(LED_BUILTIN, OUTPUT); //configurar o pino de saida
  
  pinMode(10, OUTPUT);//configurar o pin 10 como saida
  pinMode(11, OUTPUT);//configurar o pin 11 como saida
  pinMode(12, OUTPUT);//configurar o pin 12 como saida

}

void loop() // ciclo que o comando dado vai fazer 
{
  digitalWrite(LED_BUILTIN, HIGH); // ligar o led
  digitalWrite(10, HIGH); // liga o pin 10
  delay(600);
  digitalWrite(11, HIGH); // liga o pin 11
  delay(600);
  digitalWrite(12, HIGH); // liga o pin 12
  delay(600); // Wait for 600 millisecond(s) // tempo de espera 
  
  digitalWrite(LED_BUILTIN, LOW); // deligar o led 
  digitalWrite(10, LOW);  // desliga o pin 10
  delay(600);
  digitalWrite(11, LOW);  // desliga o pin 11
  delay(600);
  digitalWrite(12, LOW);  // desliga o pin 12
  delay(600); // Wait for 600 millisecond(s)

}