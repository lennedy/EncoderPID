#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>
#include "Util.h"

#define PULSOS_POR_REVOLUCAO 823.1

class Encoder{

private:
	unsigned int CONTADOR_PIN;
	unsigned int SENTIDO_PIN;
	long numPulsos;
	long numPulsosAnterior;
	long tempoAnterior;
	float pulsosPorRevolucao;
	float velocidade;

	bool pinEdgeHigh();

	float calculaVelocidade();
	float calculaAngulo();
	Util tempo;
	
public:
	Encoder(unsigned int pin1, unsigned int pin2);
	void config();
	void lerPulso();

	inline long getNumPulsos(){return numPulsos;}
	inline float getVelocidade(){return velocidade;}
	inline float getAngulo(){return calculaAngulo();}

};

#endif
