#include "Encoder.h"

Encoder::Encoder(unsigned int pin1, unsigned int pin2):CONTADOR_PIN(pin1),SENTIDO_PIN(pin2){
	count=0;
}

void Encoder::config(){
  pinMode(CONTADOR_PIN,INPUT);
  pinMode(SENTIDO_PIN,INPUT);
}

void Encoder::pulso(){

  if(pinEdgeHigh()){
    if(digitalRead(SENTIDO_PIN))
      count++;
    else
      count--;
  }

}

bool Encoder::pinEdgeHigh(){
  static int valPin=0;
  static int valPinLast=0;
  valPin = digitalRead(CONTADOR_PIN);
  if(valPin != valPinLast){
    if(valPin == HIGH){
      valPinLast= valPin;
      return true;
    }
   }
   valPinLast= valPin;
   return false;
}
