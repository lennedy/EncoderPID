#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

class Encoder{

private:
	unsigned int CONTADOR_PIN;
	unsigned int SENTIDO_PIN;
	long count;

	bool pinEdgeHigh();

public:
	Encoder(unsigned int pin1, unsigned int pin2);
	void config();
	void pulso();

};

#endif
