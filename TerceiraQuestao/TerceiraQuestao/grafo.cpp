#include "grafo.h"
#include <string>

Grafo::Grafo()
{

}

/**
* Adiciona um um Vertice no Grafo
*/
void Grafo::adicionarVertice(Vertice vertice)
{

	vertices.push_back(vertice);
}

/**
* Adiciona uma aresta ao grafo, uma aresta � associado a um vertice
*/
int Grafo::adicionarAresta(Vertice v1, Vertice v2)
{

	int indice = 0;
	for (size_t i = 0; i < vertices.size(); i++)
	{
		ValorVertice valorVertice = vertices[i].getValor();
		ValorVertice valorVertice1 = v1.getValor();

		if (valorVertice.getId() == valorVertice1.getId())
		{
			break;
		}

		indice++;
	}

	ValorVertice valorVertice2 = v2.getValor();
	vertices[indice].adicionarAresta(valorVertice2);

	return 0;
}

/**
* Percorre o grafo para entregar os produtos do fornecedor para o cliente
*/
void Grafo::entregarProdutos()
{

	//recupera o fornecedor no grafo
	ValorVertice fornecedor = getFornecedor();

	//recupera o valor com o menor demanda
	double menorCliente = valorMenorCliente();

	//enquanto hover produtos no fornecedor para o cliente de menor demanda, ser� continuado fornecendo produtos
	while (fornecedor.getValor() >= menorCliente)
	{
		percorrerGrafo(fornecedor);
	}

	cout << strSaida;

}

/**
* Retorna o Fornecedor no Grafo
*/
ValorVertice Grafo::getFornecedor()
{

	ValorVertice valorVertice;

	for (size_t i = 0; i < vertices.size(); i++)
	{

		ValorVertice valorVertice = vertices[i].getValor();

		if (valorVertice.getTipo() == Fornecedor) {
			return valorVertice;
		}

		vector<ValorVertice> arestas = vertices[i].getArestas();

		for (size_t j = 0; j < arestas.size(); j++)
		{
			ValorVertice valorVertice = arestas[j];

			if (valorVertice.getTipo() == Fornecedor) {
				return valorVertice;
			}
		}
	}

	return valorVertice;
}

/**
* Retorna o valor do menor cliente no grafo
*/
double Grafo::valorMenorCliente()
{
	ValorVertice clienteAtual = primeiroCliente();

	for (size_t i = 0; i < vertices.size(); i++)
	{
		ValorVertice valorVertice = vertices[i].getValor();

		if (valorVertice.getTipo() == Cliente && valorVertice.getValor() < clienteAtual.getValor())
		{
			clienteAtual = valorVertice;
		}

		vector<ValorVertice> arestas = vertices[i].getArestas();

		for (size_t j = 0; j < arestas.size(); j++)
		{
			ValorVertice valorVertice = arestas[j];

			if (valorVertice.getTipo() == Cliente && valorVertice.getValor() < clienteAtual.getValor())
			{
				clienteAtual = valorVertice;
			}
		}
	}

	return clienteAtual.getValor();
}

/**
* Retorna o primeiro cliente encontrado no grafo
*/
ValorVertice Grafo::primeiroCliente()
{

	for (size_t i = 0; i < vertices.size(); i++) 
	{
		ValorVertice valorVertice = vertices[i].getValor();

		if (valorVertice.getTipo() == Cliente)
		{
			return valorVertice;
		}

		vector<ValorVertice> arestas = vertices[i].getArestas();

		for (size_t j = 0; j < arestas.size(); j++)
		{
			ValorVertice valorVertice = arestas[j];

			if (valorVertice.getTipo() == Cliente)
			{
				return valorVertice;
			}
		}
	}
}

/**
* Percorre o grafo, o fornecedor entrega os produtos para todos os clientes conforme a demanda e
* quantidade que o fornecedor tem.
*/
void Grafo::percorrerGrafo(ValorVertice &fornecedor)
{

	for (size_t i = 0; i < vertices.size(); i++)
	{

		ValorVertice valorVertice = vertices[i].getValor();

		if (valorVertice.getTipo() == Cliente)
		{

			ValorVertice cliente = valorVertice;

			if (fornecedor.getValor() >= cliente.getValor())
			{
				double sub = cliente.getValor();
				formatarTexto(cliente, fornecedor);

				vertices[i].incrementar();
				fornecedor.subtrair(sub);
			}


			if (fornecedor.getValor() < cliente.getValor() && cliente.isFornecer())
			{
				vertices[i].fimFornecedor();
				formatarTexto(vertices[i].getValor(), fornecedor);
			}
		}

		vector<ValorVertice> arestas = vertices[i].getArestas();

		for (size_t j = 0; j < arestas.size(); j++)
		{
			ValorVertice valorVertice = arestas[j];

			if (valorVertice.getTipo() == Cliente)
			{

				ValorVertice cliente = valorVertice;

				if (fornecedor.getValor() >= valorVertice.getValor())
				{
					double sub = cliente.getValor();

					formatarTexto(cliente, fornecedor);

					vertices[i].incrementarAresta(j);
					fornecedor.subtrair(sub);
				}

				if (fornecedor.getValor() < cliente.getValor() && cliente.isFornecer())
				{
					vertices[i].fimFornecedor(j);
					formatarTexto(vertices[i].getArestas()[j], fornecedor);

				}
			}
		}
	}
}

/**
* Formata o texto de saida do grafo
*/
void Grafo::formatarTexto(ValorVertice cliente, ValorVertice fornecedor)
{

	static int passo = 1;
	double sub = cliente.getValor();

	string strPasso = to_string(passo);
	string strValor = to_string(fornecedor.getValor());
	string strSub = to_string(sub);
	string strId = to_string(cliente.getId());

	if (fornecedor.getValor() >= cliente.getValor())
	{
		this->strSaida.append("Passo ").append(strPasso).append("\n================\n")
			.append("F(").append(strPasso).append(")").append(" = ").append(strValor).append("\n")
			.append("F libera ").append(strSub).append(" para ").append("C").append(strId).append("\n");

	}
	else
	{
		string strPasseio = to_string(cliente.getPasseio());
		this->strSaida.append("Passo ").append(strPasso).append("\n================\n")
			.append("F(").append(strPasso).append(")").append(" = ").append(strValor).append("\n")
			.append("F nao consegue mais liberar para ").append("C").append(strId).append("\n\n")
			.append("Quantidade de vezes que F foi capaz de liberar produtos para ").append("C").append(strId).append(" = ").append(strPasseio).append(" vezes").append("\n\n");
	}

	passo++;
}
