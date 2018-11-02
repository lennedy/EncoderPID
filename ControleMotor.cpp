#include "ControleMotor.h"
#include "PID_v1.h"
#include "Pinagem.h"

ControleMotor::ControleMotor():	encoder(ENCODER_CONTADOR, ENCODER_DIRECAO), 
																motor(MOTOR_PWM,MOTOR_DIRECAO),
																pid(&Setpoint, &Input, &Output,Kp,Ki,Kd, DIRECT)
{}


void ControleMotor::config(){
	encoder.config();
	motor.config();

  Setpoint = 100;

  //turn the PID on
  pid.SetMode(AUTOMATIC);
}

void ControleMotor::loop(){
  Input = encoder.getVelocidade();
  pid.Compute();
  motor.acionar(Output);
}
