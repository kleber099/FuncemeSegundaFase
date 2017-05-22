#include "valor_vertice.h"

/**
* Retorna o id do ValorVertice
*/
int ValorVertice::getId()
{
	return this->id;
}

/**
* Retorna o id do ValorVertice
*/
double ValorVertice::getValor()
{
	return this->valor;
}

/**
* Retorna o tipo do ValorVertice
*/
V_TIPO ValorVertice::getTipo()
{
	return this->tipo;
}

/**
* Subrair o valor do VerticeValor, usado quando o tipo é Fornecedor
*/
void ValorVertice::subtrair(double valor)
{

	if (valor <= this->valor)
	{
		this->valor -= valor;
		this->passeio++;
	}
}

/**
* Incrementa o passeio, usado quando o tipo é Cliente
*/
void ValorVertice::incrementarPasseio()
{
	this->passeio++;
}

/**
* Retorna o passeio do cliente, usando quando o tipo é Cliente
*/
int ValorVertice::getPasseio()
{
	return this->passeio;
}

/**
* Retorna se o fornecedor pode ainda fornecer produtos para o Cliente
*/
bool ValorVertice::isFornecer()
{
	return this->fornecer;
}

/**
* Marcar para o fornecedor não mais forncer produtos ao Cliente
*/
void ValorVertice::fimFornecer()
{
	this->fornecer = false;
}