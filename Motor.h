#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include <math.h>

class Motor{
private:
	const int PWM_PIN, DIRECAO_PIN;
public:
	Motor(int pwmPin, int direcaoPin);
	void config();
	void acionar(float tensao);
};

#endif

