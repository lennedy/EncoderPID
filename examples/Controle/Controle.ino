#include <ControleMotor.h>

ControleMotor contrPos;
Util tempo;
bool primeira;

void setup(){
  Serial.begin(9600);
  contrPos.config();
  contrPos.setConstantes(1, 0.5, 0.1);
}

void loop(){
  
	contrPos.loop();

	if(tempo.esperou(1000)){
		Serial.print("Angulo: ");
		Serial.println(contrPos.getAngulo());
		if(primeira){
			contrPos.setSetpoint(90);
			primeira=false;
		}
		else{
			contrPos.setSetpoint(0);
			primeira=true;
		}
	}
}
