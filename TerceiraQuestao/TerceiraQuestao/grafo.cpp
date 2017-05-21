#include "grafo.h"
#include <string>

Grafo::Grafo()
{

}

void Grafo::adicionarVertice(Vertice vertice) {

	vertices.push_back(vertice);
}

int Grafo::adicionarAresta(Vertice v1, Vertice v2)
{
	
	int indice = 0;
	for (size_t i = 0; i < vertices.size(); i++) {

		ValorVertice valorVertice = vertices[i].getValor();
		ValorVertice valorVertice1 = v1.getValor();

		if (valorVertice.getId() == valorVertice1.getId()) {
			break;
		}

		indice++;
	}

	ValorVertice valorVertice2 = v2.getValor();
	vertices[indice].adicionarAresta(valorVertice2);

	return 0;
}

void Grafo::entregarProdutos() {

	ValorVertice fornecedor = getFornecedor();
	double menorCliente = valorMenorCliente();

	while (fornecedor.getValor() >= menorCliente) {
		percorrerGrafo(fornecedor);
	}

	cout << strSaida;

}

ValorVertice Grafo::getFornecedor() {

	ValorVertice valorVertice;

	for (size_t i = 0; i < vertices.size(); i++) {

		ValorVertice valorVertice = vertices[i].getValor();

		if (valorVertice.getTipo() == Fornecedor) {
			return valorVertice;
		}

		vector<ValorVertice> arestas = vertices[i].getArestas();

		for (size_t j = 0; j < arestas.size(); j++) {
			ValorVertice valorVertice = arestas[j];

			if (valorVertice.getTipo() == Fornecedor) {
				return valorVertice;
			}
		}
	}
		
	return valorVertice;
}

double Grafo::valorMenorCliente() {

	ValorVertice clienteAtual = primeiroCliente();
	
	for (size_t i = 0; i < vertices.size(); i++) {

		ValorVertice valorVertice = vertices[i].getValor();

		if (valorVertice.getTipo() == Cliente && valorVertice.getValor() < clienteAtual.getValor()) {
			clienteAtual = valorVertice;
		}

		vector<ValorVertice> arestas = vertices[i].getArestas();

		for (size_t j = 0; j < arestas.size(); j++) {
			ValorVertice valorVertice = arestas[j];

			if (valorVertice.getTipo() == Cliente && valorVertice.getValor() < clienteAtual.getValor()) {
				clienteAtual = valorVertice;
			}
		}
	}

	return clienteAtual.getValor();
}

ValorVertice Grafo::primeiroCliente() {

	for (size_t i = 0; i < vertices.size(); i++) {

		ValorVertice valorVertice = vertices[i].getValor();

		if (valorVertice.getTipo() == Cliente) {
			return valorVertice;
		}

		vector<ValorVertice> arestas = vertices[i].getArestas();

		for (size_t j = 0; j < arestas.size(); j++) {
			ValorVertice valorVertice = arestas[j];

			if (valorVertice.getTipo() == Cliente) {
				return valorVertice;
			}
		}
	}
}

void Grafo::percorrerGrafo(ValorVertice &fornecedor) {

	for (size_t i = 0; i < vertices.size(); i++) {

		ValorVertice valorVertice = vertices[i].getValor();

		if (valorVertice.getTipo() == Cliente) {
			
			ValorVertice cliente = valorVertice;

			if (fornecedor.getValor() >= cliente.getValor()) {
				double sub = cliente.getValor();
				formatarTexto(cliente, fornecedor);
				
				vertices[i].incrementar();
				fornecedor.subtrair(sub);
			}

		
			if (fornecedor.getValor() < cliente.getValor() && cliente.isFornecer()) {
				
				vertices[i].fimFornecedor();
				formatarTexto(vertices[i].getValor(), fornecedor);

			}
		}

		vector<ValorVertice> arestas = vertices[i].getArestas();

		for (size_t j = 0; j < arestas.size(); j++) {
			ValorVertice valorVertice = arestas[j];

			if (valorVertice.getTipo() == Cliente) {

				ValorVertice cliente = valorVertice;
				
				if (fornecedor.getValor() >= valorVertice.getValor()) {
					double sub = cliente.getValor();

					formatarTexto(cliente, fornecedor);

					vertices[i].incrementarAresta(j);
					fornecedor.subtrair(sub);
				}

				if (fornecedor.getValor() < cliente.getValor() && cliente.isFornecer()) {
					
					vertices[i].fimFornecedor(j);
					
					formatarTexto(vertices[i].getArestas()[j], fornecedor);

				}			
			}
		}
	}
}

void Grafo::formatarTexto(ValorVertice cliente, ValorVertice fornecedor) {

	static int passo = 1;
	double sub = cliente.getValor();

	string strPasso = to_string(passo);
	string strValor = to_string(fornecedor.getValor());
	string strSub = to_string(sub);
	string strId = to_string(cliente.getId());

	if (fornecedor.getValor() >= cliente.getValor()) {

		this->strSaida.append("Passo ").append(strPasso).append("\n================\n")
			.append("F(").append(strPasso).append(")").append(" = ").append(strValor).append("\n")
			.append("F libera ").append(strSub).append(" para ").append("C").append(strId).append("\n");
	
	} else {

		string strPasseio = to_string(cliente.getPasseio());
		this->strSaida.append("Passo ").append(strPasso).append("\n================\n")
			.append("F(").append(strPasso).append(")").append(" = ").append(strValor).append("\n")
			.append("F nao consegue mais liberar para ").append("C").append(strId).append("\n\n")
			.append("Quantidade de vezes que F foi capaz de liberar produtos para ").append("C").append(strId).append(" = ").append(strPasseio).append(" vezes").append("\n\n");
	}

	passo++;
}

int Grafo::validarGrafo() {

	int quantCli = 0;
	int quantFor = 0;
	int quantJun = 0;

	for (size_t i = 0; i < vertices.size(); i++) {
		
		int quantCliAresta = 0;
		int quantForAresta = 0;
		int quantJunAresta = 0;

		ValorVertice valorVertice = vertices[i].getValor();

		if (valorVertice.getTipo() == Juncao) {
			quantJun++;

		}
		else if (valorVertice.getTipo() == Cliente) {
			quantCli++;

		}
		else if (valorVertice.getTipo() == Fornecedor) {
			quantFor++;
		}

		vector<ValorVertice> arestas = vertices[i].getArestas();

		for (size_t j = 0; j < arestas.size(); j++) {
			ValorVertice valorAresta = arestas[j];

			if (valorVertice.getTipo() == Fornecedor && valorAresta.getTipo() == Fornecedor) {
				return -1;

			} else if (valorVertice.getTipo() == Juncao && valorAresta.getTipo() == Juncao) {
				return -2;
			}

			if (valorAresta.getTipo() == Juncao) {
				quantJunAresta++;

			} else if (valorAresta.getTipo() == Cliente) {
				quantCliAresta++;

			} else if (valorAresta.getTipo() == Fornecedor) {
				quantForAresta++;
			}
		}

		if (valorVertice.getTipo() == Fornecedor && (quantJunAresta != 1 && quantCliAresta != 1)) {
			return -3;
		}

		quantFor += quantForAresta;
		quantCli += quantCliAresta;
		quantJun += quantJunAresta;
	}

	if (quantFor != 1) {
		return -4;
	}

	if (quantCli == 0) {
		return -5;
	}

	return 0;
}
