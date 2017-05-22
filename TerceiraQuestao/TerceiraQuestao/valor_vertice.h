
#ifndef __VALOR_VERTICE__
#define __VALOR_VERTICE__

//Definição dos tipos na enum V_TIPO
enum V_TIPO { Fornecedor, Juncao, Cliente };

/**
* Classe que armazena o valor de um vertice, cotem um id, o tipo, valor e dados para controle
*/
class ValorVertice
{
private:
	int id;
	double valor;
	V_TIPO tipo;
	int passeio = 0;
	bool fornecer;

public:
	ValorVertice()
	{
	}

	ValorVertice(double valor, V_TIPO tipo)
	{
		static int gerarID = 0;
		gerarID++;
		this->id = gerarID;
		this->valor = valor;
		this->tipo = tipo;
		this->passeio = 0;
		this->fornecer = true;
	}

	int getId();
	double getValor();
	V_TIPO getTipo();
	void subtrair(double valor);
	void incrementarPasseio();
	int getPasseio();
	bool isFornecer();
	void fimFornecer();
};

#endif