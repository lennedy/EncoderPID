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

  double Kp=1, Ki=0.5, Kd=0;
  PID pid;
  double Setpoint, Input, Output;

public:
	ControleMotor();

	void config();

	void loop();

	inline void setSetpoint(double setpoint){ this->Setpoint=setpoint;	}
	inline float getAngulo(){return encoder.getAngulo();}

};

#endif
