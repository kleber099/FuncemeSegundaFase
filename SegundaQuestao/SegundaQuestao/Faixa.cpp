#include "Faixa.h"
#include "retorno.h"

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
* Realiza a validação dos dados da Faixa
* @return 0 - OK
*/
RET Faixa::validar()
{
	//volume da faixa não pode ser menor que 0
	if (this->faixaSuperior <= 0.0) {
		return RET_ERRO_FAIXA;
	}

	return RET_OK;
}

