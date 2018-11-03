#include "ControleMotor.h"


//Encoder ControleMotor::encoder(ENCODER_CONTADOR, ENCODER_DIRECAO);
//Motor ControleMotor::motor(MOTOR_PWM,MOTOR_DIRECAO);

ControleMotor::ControleMotor():motor(MOTOR_PWM,MOTOR_DIRECAO),encoder(ENCODER_CONTADOR,ENCODER_DIRECAO),pid(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT)
 {}

void ControleMotor::config(){
	Setpoint = 100;
	amostragem = 50; // 50 milissegundos

  //turn the PID on
  pid.SetMode(AUTOMATIC);
  pid.SetOutputLimits(-100, 100);
  encoder.config();
  motor.config();    
	
}

void ControleMotor::loop(){

	encoder.lerPulso();
	if(util2.esperou(amostragem)){
		Input = encoder.getAngulo();
		pid.Compute();
		motor.acionar(Output);
	}

	if(util.esperou(1000)){

		Serial.print("kp: ");
		Serial.print(pid.GetKp());
		Serial.print("; ki: ");
		Serial.print(pid.GetKi());						
		Serial.print("; kd: ");
		Serial.print(pid.GetKd());			
		Serial.print("; output: ");
		Serial.print(Output);
		Serial.print("; input: ");
		Serial.print(Input);
		Serial.print("; Setpoint: ");
		Serial.println(Setpoint);
	}
}


