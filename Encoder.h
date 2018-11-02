#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

#define PULSOS_POR_REVOLUCAO 823.1

class Encoder{

private:
	unsigned int CONTADOR_PIN;
	unsigned int SENTIDO_PIN;
	long numPulsos;
	long numPulsosAnterior;
	long tempoAnterior;
	float pulsosPorRevolucao;

	bool pinEdgeHigh();

	float calculaVelocidade();
	float calculaAngulo();
	
public:
	Encoder(unsigned int pin1, unsigned int pin2);
	void config();
	void lerPulso();

	inline long getNumPulsos(){return numPulsos;}
	inline float getVelocidade(){return calculaVelocidade();}
	inline float getAngulo(){return calculaAngulo();}

};

#endif
