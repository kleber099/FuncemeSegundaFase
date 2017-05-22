#ifndef __VERTICE__
#define __VERTICE__

#include "valor_vertice.h"

#include <iostream>
#include <vector>

using namespace std;

/**
* Classe que representa o vertice, cont�m um valor e uma lista de arestas que s�o do tipo ValorVertice
*/
class Vertice {
private:
	ValorVertice valor;
	vector<ValorVertice> arestas;

public:
	Vertice(ValorVertice valor);
	Vertice(double valor, V_TIPO tipo);
	ValorVertice getValor();
	void adicionarAresta(ValorVertice valor);
	vector<ValorVertice> getArestas();
	void incrementar();
	void incrementarAresta(int indice);
	void fimFornecedor();
	void fimFornecedor(int indice);
};
#endif
