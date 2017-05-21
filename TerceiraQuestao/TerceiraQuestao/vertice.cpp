#include "vertice.h"
#include "valor_vertice.h"

Vertice::Vertice(ValorVertice valor)
{
	this->valor = valor;
}

Vertice::Vertice(double valor, V_TIPO tipo) {
	ValorVertice valorVetice(valor, tipo);
	this->valor = valorVetice;

}

ValorVertice Vertice::getValor() {
	return this->valor;
}

void Vertice::adicionarAresta(ValorVertice valor) {
	arestas.push_back(valor);
}

vector<ValorVertice> Vertice::getArestas(){

	return this->arestas;
}

void Vertice::incrementar() {
	this->valor.incrementarPasseio();
}

void Vertice::incrementarAresta(int indice) {
	this->arestas[indice].incrementarPasseio();
}

void Vertice::fimFornecedor() {
	this->valor.fimFornecer();
}

void Vertice::fimFornecedor(int indice) {
	this->arestas[indice].fimFornecer();
}