#include "Motor.h"

Motor::Motor(int pwmPin, int direcaoPin):PWM_PIN(pwmPin), DIRECAO_PIN(direcaoPin){
	
}

void Motor::config(){
  pinMode(PWM_PIN,OUTPUT);
  pinMode(DIRECAO_PIN,OUTPUT);
}

void Motor::acionar(float percentualTensao){

	if(percentualTensao < -100) 
    percentualTensao = -100;	//se o valor passado em valor_por_cento for menor que -100 obriga-se o mmotor a ficar em -100
  if(percentualTensao >  100) 
    percentualTensao =  100;	//se o valor passado em valor_por_cento for maior que 100 obriga-se o mmotor a ficar em 100


	if(percentualTensao < 0){
		digitalWrite(DIRECAO_PIN, false);
	}else{
		digitalWrite(DIRECAO_PIN, true);
		percentualTensao = 100 - percentualTensao;
	}		

  analogWrite(PWM_PIN, 255*(abs(percentualTensao))/100.0);
	

}

