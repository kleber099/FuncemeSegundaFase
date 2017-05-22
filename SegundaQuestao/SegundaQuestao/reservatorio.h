#ifndef __RESERVATORIO__
#define __RESERVATORIO__

#include "retorno.h"

/**
* Classe que armazena os dados do Reservatório, contém volume corrente, minimo e máximo, essa classe armazena os dados
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

