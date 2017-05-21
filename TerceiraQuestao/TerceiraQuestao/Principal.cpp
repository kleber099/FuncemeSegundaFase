#include "grafo.h"

int main() {

	Grafo g;

	Vertice cliente1(3, Cliente);
	Vertice cliente2(1, Cliente);
	Vertice cliente3(2, Cliente);
	Vertice fornecedor(10, Fornecedor);
	Vertice juncao(4, Juncao);

	g.adicionarVertice(fornecedor);
	g.adicionarAresta(fornecedor, cliente1);
	g.adicionarAresta(fornecedor, juncao);
	
	g.adicionarVertice(juncao);
	g.adicionarAresta(juncao, cliente2);
	g.adicionarAresta(juncao, cliente3);


	g.entregarProdutos();

	getchar();
    return 0;
}

