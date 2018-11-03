#include <ControleMotor.h>

ControleMotor contrPos;

void setup(){
  Serial.begin(9600);
  contrPos.config();
}

void loop(){
  
	contrPos.loop();
}
