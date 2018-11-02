class Util{
public:
	bool esperou(int milisegundos){
		static int tempoAtual=0;
		static int tempoAnterior=0;
	
		tempoAtual = millis();
		if(tempoAtual-tempoAnterior > milisegundos){
			tempoAnterior = tempoAtual;
			return true;
		}
		return false;
	}

};
