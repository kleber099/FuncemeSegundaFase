#include "reservatorio.h"

/**
* Construtor de um Reservatorio
*
* @param inicial Volume corrente do reservat�rio
* @param minimo Volume m�nimo do reservat�rio
* @param maximo Volume m�ximo do reservat�rio
*/
Reservatorio::Reservatorio(double inicial, double minimo, double maximo)
{
	this->inicial = inicial;
	this->minimo = minimo;
	this->maximo = maximo;
}

/**
* Retorna o volume corrente do reservat�rio
*/
double Reservatorio::getInicial()
{
	return this->inicial;
}

/**
* Retorna o volume m�nimo do reservat�rio
*/
double Reservatorio::getMinimo()
{
	return this->minimo;
}

/**
* Retorna o volume m�ximo do reservat�rio
*/
double Reservatorio::getMaximo()
{
	return this->maximo;
}

/**
* Realiza a valida��o dos dados do reservat�rio
* @return 0 - OK
*/
int Reservatorio::validar()
{
	//Caso o volume correte, minimo ou m�ximo forem 0 retorna erro
	if (this->minimo == 0.0 || this->inicial == 0.0 || this->maximo == 0.0)
	{
		return -1;

	}
	else if (this->inicial <= this->minimo) //Volume corrente tem que ser maior que o minimo
	{
		return -2;
	}
	else if (this->inicial >= this->maximo) //Volume corrente tem que ser menir que o m�ximo
	{
		return -3;
	}

	return 0;
}