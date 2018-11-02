#ifndef CONTROLE_MOTOR_H
#define CONTROLE_MOTOR_H

#include "Encoder.h"
#include "Motor.h"
#include "PID_v1.h"
#include "Util.h"

class ControleMotor{
private:
	double Kp=2, Ki=5, Kd=1;
	double Setpoint, Input, Output;
	float tempoAmostragem;
	static Encoder encoder;
	static Motor motor;
	PID pid;
	Util util;
	bool contrVelocidade;

public:
	ControleMotor();

	void config(bool contrVelocidade=true);

	void loop();

};

#endif
