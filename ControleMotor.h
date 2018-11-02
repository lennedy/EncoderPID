#ifndef CONTROLE_MOTOR_H
#define CONTROLE_MOTOR_H

#include "Encoder.h"
#include "Motor.h"
#include "PID_v1.h"

class ControleMotor{
private:
	double Kp=2, Ki=5, Kd=1;
	double Setpoint, Input, Output;
	float tempoAmostragem;
	Encoder encoder;
	Motor motor;
	PID pid;

public:
	ControleMotor();

	void config();

	void loop();

};

#endif
