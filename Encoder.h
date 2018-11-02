#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

class Encoder{

private:
	unsigned int CONTADOR_PIN;
	unsigned int SENTIDO_PIN;
	long numPulsos;
	long numPulsosAnterior;
	long tempoAnterior;


	bool pinEdgeHigh();

	float calculaVelocidade();

public:
	Encoder(unsigned int pin1, unsigned int pin2);
	void config();
	void lerPulso();

	inline long getNumPulsos(){return numPulsos;}
	inline float getVelocidade(){return calculaVelocidade();}

};

#endif
