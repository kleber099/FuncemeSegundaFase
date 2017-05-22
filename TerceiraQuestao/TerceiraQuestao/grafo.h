#ifndef __GRAFO__
#define __GRAFO__

#include "vertice.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Classe que representa o grafo, implementação baseada na lista de adjacência
*/
class Grafo
{
private:
	string strSaida;

	vector<Vertice>vertices;
	ValorVertice getFornecedor();
	void Grafo::percorrerGrafo(ValorVertice &fornecedor);
	double valorMenorCliente();
	ValorVertice Grafo::primeiroCliente();
	void formatarTexto(ValorVertice cliente, ValorVertice fornecedor);

public:
	Grafo();
	void adicionarVertice(Vertice vertice);
	int adicionarAresta(Vertice v1, Vertice v2);
	void entregarProdutos();

};

#endif