#include <ControleMotor.h>

ControleMotor contrVel, contrPos;

void setup(){
	contrVel.config(true);
  contrPos.config(false);
}

void loop(){
  
	contrPos.loop();

}
