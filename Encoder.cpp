#include "Encoder.h"

Encoder::Encoder(unsigned int pin1, unsigned int pin2):CONTADOR_PIN(pin1),SENTIDO_PIN(pin2){
	numPulsos=0;
}

void Encoder::config(){
  pinMode(CONTADOR_PIN,INPUT);
  pinMode(SENTIDO_PIN,INPUT);
}

void Encoder::lerPulso(){
	//Serial.println("teste");
  if(pinEdgeHigh()){
    if(digitalRead(SENTIDO_PIN))
      numPulsos++;
    else
      numPulsos--;
  }

}

bool Encoder::pinEdgeHigh(){
  static int valPin=0;
  static int valPinLast=0;
  valPin = digitalRead(CONTADOR_PIN);
  if(valPin != valPinLast){
    if(valPin == HIGH){
      valPinLast= valPin;
      return true;
    }
   }
   valPinLast= valPin;
   return false;
}

float Encoder::calculaVelocidade(){
	const long pulsosAtuais = getNumPulsos();
	const long tempoAtual = millis(); 

	long deltaS = pulsosAtuais 	- numPulsosAnterior;
	long deltaT = tempoAtual 		- tempoAnterior;
	
	float velocidade = deltaS/((float)deltaT);

	
	tempoAnterior	=	tempoAtual;
	numPulsosAnterior	=	pulsosAtuais;

	return velocidade;
}
