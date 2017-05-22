#ifndef __FAIXA__
#define __FAIXA__

#include "retorno.h"

/**
* Classe que armazena uma Faixa, que cont�m uma prioridade e volume, essa classe armazena a prioridade
* e Volume de uma grid na interface gr�fica
*/
class Faixa
{
private:
	int prioridade;
	double faixaSuperior;


public:
	Faixa(int prioridade, double faixaSuperior);
	int getPrioridade();
	double getFaixaSuperior();
	RET validar();
};

#endif

