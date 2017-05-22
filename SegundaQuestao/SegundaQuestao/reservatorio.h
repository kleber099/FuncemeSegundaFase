#ifndef __RESERVATORIO__
#define __RESERVATORIO__

#include "retorno.h"

/**
* Classe que armazena os dados do Reservat�rio, cont�m volume corrente, minimo e m�ximo, essa classe armazena os dados
* da interface
*/
class Reservatorio
{
private:
	double inicial;
	double minimo;
	double maximo;

public:
	Reservatorio(double inicial, double minimo, double maximo);
	double getInicial();
	double getMinimo();
	double getMaximo();
	RET validar();

};

#endif

