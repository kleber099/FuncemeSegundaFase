#include "reservatorio.h"

/**
* Construtor de um Reservatorio
*
* @param inicial Volume corrente do reservatório
* @param minimo Volume mínimo do reservatório
* @param maximo Volume máximo do reservatório
*/
Reservatorio::Reservatorio(double inicial, double minimo, double maximo)
{
	this->inicial = inicial;
	this->minimo = minimo;
	this->maximo = maximo;
}

/**
* Retorna o volume corrente do reservatório
*/
double Reservatorio::getInicial()
{
	return this->inicial;
}

/**
* Retorna o volume mínimo do reservatório
*/
double Reservatorio::getMinimo()
{
	return this->minimo;
}

/**
* Retorna o volume máximo do reservatório
*/
double Reservatorio::getMaximo()
{
	return this->maximo;
}

/**
* Realiza a validação dos dados do reservatório
* @return 0 - OK
*/
int Reservatorio::validar()
{
	//Caso o volume correte, minimo ou máximo forem 0 retorna erro
	if (this->minimo == 0.0 || this->inicial == 0.0 || this->maximo == 0.0)
	{
		return -1;

	}
	else if (this->inicial <= this->minimo) //Volume corrente tem que ser maior que o minimo
	{
		return -2;
	}
	else if (this->inicial >= this->maximo) //Volume corrente tem que ser menir que o máximo
	{
		return -3;
	}

	return 0;
}