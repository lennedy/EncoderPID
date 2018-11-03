#include <ControleMotor.h>

ControleMotor contrVel;
Util tempo;
bool primeira;

void setup(){
  Serial.begin(9600);
  contrVel.config();
  contrVel.setConstantes(1, 0.5, 0.1);
}

void loop(){
  
	contrVel.loop();

	if(tempo.esperou(1000)){
		Serial.print("Velocidade: ");
		Serial.println(contrVel.getVelocidade());
	/*	if(primeira){
			contrVel.setSetpoint(90);
			primeira=false;
		}
		else{
			contrVel.setSetpoint(0);
			primeira=true;
		}*/
	}
}
