/* Projeto: Campainha elétrica sem fio com Xbee
   Autor: Domingos R S Jr

   */

//Código que encaminha o processamento do botão pressionado
const int botao =12; //botao no pino 12

void setup()
{
  // Se tiver usando o Uno usa o serial
  Serial.begin(9600); //Inicia a porta serial
}

void loop()
{
  Serial.println(digitalRead(botao)); // Envia o estado do botão
  delay(100); //Pequeno atraso para não inundar o receptor
}
