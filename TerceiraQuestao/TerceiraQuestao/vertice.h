#ifndef __VERTICE__
#define __VERTICE__

#include "valor_vertice.h"

#include <iostream>
#include <vector>

using namespace std;

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
