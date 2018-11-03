#include "ControleMotor.h"


//Encoder ControleMotor::encoder(ENCODER_CONTADOR, ENCODER_DIRECAO);
//Motor ControleMotor::motor(MOTOR_PWM,MOTOR_DIRECAO);

ControleMotor::ControleMotor():motor(10,9),encoder(12,11),pid(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT)
 {}



void ControleMotor::config(){
	Setpoint = 100;

  //turn the PID on
  pid.SetMode(AUTOMATIC);
  pid.SetOutputLimits(-100, 100);
   Serial.begin(9600);
   encoder.config();
   motor.config();    
	


}

void ControleMotor::loop(){

 encoder.lerPulso();
  Input = encoder.getAngulo();
  pid.Compute();
  motor.acionar(Output);

	if(esperou(1000)){

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

bool ControleMotor::esperou(int milisegundos){
	static int tempoAtual=0;
	static int tempoAnterior=0;

	tempoAtual = millis();
	if(tempoAtual-tempoAnterior > milisegundos){
		tempoAnterior = tempoAtual;
		return true;
	}
	return false;
}
