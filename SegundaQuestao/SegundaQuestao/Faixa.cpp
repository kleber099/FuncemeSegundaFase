#include "Faixa.h"

/**
* Construtor de uma Faixa
*
* @param prioridade Prioridade uma faixa
* @param faixaSuperior Volume da faixa
*/
Faixa::Faixa(int prioridade, double faixaSuperior)
{
	this->prioridade = prioridade;
	this->faixaSuperior = faixaSuperior;
}

/**
* Retorna a prioridade da Faixa
* @return Prioridade da Faixa
*/
int Faixa::getPrioridade()
{
	return this->prioridade;
}

/**
* Retorna o volume da Faixa
* @return Volume da Faixa
*/
double Faixa::getFaixaSuperior()
{
	return this->faixaSuperior;
}

/**
* Realiza a valida��o dos dados da Faixa
* @return 0 - OK
*/
int Faixa::validar()
{
	//volume da faixa n�o pode ser menor que 0
	if (this->faixaSuperior <= 0.0) {
		return -4;
	}

	return 0;
}

