/* Projeto: Campainha elétrica sem fio com Xbee
   Autor: Domingos R S Jr

   */
    
const int buzzer=8;  //Buzzer no pino 8
int cont =0, x=0;
int pinRGB[] = {9,10,11};  // Arrau dos pinos do Led RGB
char dado;                 //Armazena dados seriais que entram
int freq=240;              //Frequencia inicial do buzzer NOTE_A2=110Hz

void setup()
{
  Serial.begin(9600); 
  for (cont=0;cont<3;cont++) // Os pinos do Ler RGB como saída
  {
    pinMode(pinRGB[cont], OUTPUT);
  }
}

//função escolhe que escolhe a cor aleatória
void CorAleatoria()
{
   if (dado == '1') // botão do tramissor aciononado 
    {
      analogWrite(pinRGB[0],random(255));
      analogWrite(pinRGB[1],random(255));
      analogWrite(pinRGB[2],random(255));      
    }
    else if (dado== '0') // botão do tramissor desaciononado 
    {
      analogWrite(pinRGB[0],0);
      analogWrite(pinRGB[1],0);
      analogWrite(pinRGB[2],0);
    }
}

void mudafrequencia() // altera a frequencia do buzzer
{
 if (freq == 240)
    {
       freq = 120;
    } 
    else  
    {
       freq = 240;
    }
}
  
void loop()
{
  if (Serial.available() > 0)
  {
    dado = Serial.read();  // Lê os dados da porta serial
    
    if (dado == '1') // botão acionado
    {
      CorAleatoria();
      mudafrequencia();
      tone(buzzer,freq); // desliga o buzzer     
    }
    else if (dado == '0') // botão acionado
    {
     CorAleatoria();
     mudafrequencia();
     noTone(buzzer); // desliga o buzzer
    }
  }
    
} 
