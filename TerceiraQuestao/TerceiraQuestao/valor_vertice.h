
#ifndef __VALOR_VERTICE__
#define __VALOR_VERTICE__

enum V_TIPO { Fornecedor, Juncao, Cliente };

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