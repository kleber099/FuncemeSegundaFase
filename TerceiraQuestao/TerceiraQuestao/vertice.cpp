#include "vertice.h"
#include "valor_vertice.h"

/**
* Construtor um Vertice
*
* @param valor ValorVertice, cria um novo vertice 
*/
Vertice::Vertice(ValorVertice valor)
{
	this->valor = valor;
}

/**
* Construtor um Vertice, recebe um valor e o tipo e cria internamente um tipo
* ValorVertice
* @param valor double o valor associado a um ValorVertice
* @param tipo V_TIPO tipo do vertice
*/
Vertice::Vertice(double valor, V_TIPO tipo) {
	ValorVertice valorVetice(valor, tipo);
	this->valor = valorVetice;

}

/**
* Retorna um ValorVertice, que contém os dados do vertice
*/
ValorVertice Vertice::getValor() {
	return this->valor;
}

/**
* Adicionando uma nova aresta do tipo ValorVertice
*/
void Vertice::adicionarAresta(ValorVertice valor) {
	arestas.push_back(valor);
}

/**
* Retorna todas as arestas associado ao vertice
*/
vector<ValorVertice> Vertice::getArestas() {

	return this->arestas;
}

/*
* Incrementa o passeio do vertice
*/
void Vertice::incrementar() {
	this->valor.incrementarPasseio();
}

/*
* Incrementa o passeio de uma aresta do vertice
*/
void Vertice::incrementarAresta(int indice) {
	this->arestas[indice].incrementarPasseio();
}

/*
* Marcar o fim, para o fornecedor não fornecer dados ao cliente para o vertice
*/
void Vertice::fimFornecedor() {
	this->valor.fimFornecer();
}

/*
* Marcar o fim, para o fornecedor não fornecer dados ao cliente para uma aresta de um vertice
*/
void Vertice::fimFornecedor(int indice) {
	this->arestas[indice].fimFornecer();
}