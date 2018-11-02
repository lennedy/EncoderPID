#include "ControleMotor.h"
#include "PID_v1.h"
#include "Pinagem.h"

Encoder ControleMotor::encoder(ENCODER_CONTADOR, ENCODER_DIRECAO);
Motor ControleMotor::motor(MOTOR_PWM,MOTOR_DIRECAO);

ControleMotor::ControleMotor():pid(&Setpoint, &Input, &Output,Kp,Ki,Kd, DIRECT)
{}


void ControleMotor::config(bool contrVelocidade){
	encoder.config();
	motor.config();

	Setpoint = 100;

	//turn the PID on
	pid.SetMode(AUTOMATIC);
	pid.SetOutputLimits(-100, 100);
	this->contrVelocidade=contrVelocidade;

	if(contrVelocidade){
		Kp=0, Ki=0, Kd=0;
	}
	else{
		Kp=2, Ki=5, Kd=0;
	}
	pid.SetTunings(Kp, Ki, Kd);
}

void ControleMotor::loop(){
	encoder.lerPulso();
	if(util.esperou(100)){
		if(contrVelocidade){
			Input = encoder.getVelocidade();
		}
		else{
			Input = encoder.getAngulo();
		}
		pid.Compute();
		motor.acionar(Output);
	}
}
