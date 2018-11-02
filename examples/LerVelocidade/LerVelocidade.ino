#include <ControleMotor.h>

Encoder e;

void setup(){
  Serial.begin(9600);
  m.config();
}

void loop(){
  e.lerPulso();
	if(esperou(1000)){
  	Serial.println(e.getVelocidade());
	}	
}

bool esperou(int milisegundos){
	static int tempoAtual=0;
	static int tempoAnterior=0;
	
	tempoAtual = millis();
	if(tempoAtual-tempoAnterior > milisegundos){
		tempoAnterior = tempoAtual;
		return true;
	}
	return false;
}
