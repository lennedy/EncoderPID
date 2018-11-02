#include <Motor.h>

Motor motor(10,9);

void setup(){
	Serial.begin(9600);
}

void loop(){

	motor.acionar(50);
	delay(1000);
	motor.acionar(0);
	delay(1000);
	motor.acionar(-50);
	delay(1000);
	motor.acionar(0);
	delay(1000);

}
