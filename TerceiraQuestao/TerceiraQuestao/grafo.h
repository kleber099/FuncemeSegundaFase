#ifndef __GRAFO__
#define __GRAFO__

#include "vertice.h"

#include <iostream>
#include <vector>
#include <algorithm> // função find

using namespace std;

class Grafo
{
	private:
		string strSaida;

		vector<Vertice>vertices; // ponteiro para um array contendo as listas de adjacências
		ValorVertice getFornecedor();
		void Grafo::percorrerGrafo(ValorVertice &fornecedor);
		double valorMenorCliente();
		ValorVertice Grafo::primeiroCliente();
		void formatarTexto(ValorVertice cliente, ValorVertice fornecedor);
		int validarGrafo();

	public:
		Grafo(); // construtor
		void adicionarVertice(Vertice vertice);
		int adicionarAresta(Vertice v1, Vertice v2);
		void entregarProdutos();
	
};

#endif