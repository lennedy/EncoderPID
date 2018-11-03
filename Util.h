class Util{
private:
		int tempoAtual;
		int tempoAnterior;
public:
	Util(){
		tempoAtual=0;
		tempoAnterior=0;	
	}

	bool esperou(int milisegundos){
		tempoAtual = millis();
		if(tempoAtual-tempoAnterior > milisegundos){
			tempoAnterior = tempoAtual;
			return true;
		}
		return false;
	}

};
