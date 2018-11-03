#ifndef CONTROLE_MOTOR_H
#define CONTROLE_MOTOR_H

#include "Encoder.h"
#include "Motor.h"
#include "PID_v1.h"
#include "Util.h"
#include "Pinagem.h"

class ControleMotor{
private:
  Encoder encoder;
  Motor motor;
	Util util;
	Util util2;

  double Kp=1, Ki=0.5, Kd=0.1;
  PID pid;
  double Setpoint, Input, Output;
	int amostragem; //tempo de amostragem em milissegundos
	bool controleVelocidade;

public:
	ControleMotor();

	void config();

	void loop();

	inline void enableContrVelocidade(){controleVelocidade=true;}
	inline void enableContrPosicao(){controleVelocidade=false;}

	inline void setSetpoint(double setpoint){ this->Setpoint=setpoint;	}
	inline void setConstantes(double kp, double ki, double kd){pid.SetTunings(kp,ki,kd);}

	inline float getAngulo(){return encoder.getAngulo();}
	inline float getVelocidade(){return encoder.getVelocidade();}

};

#endif
