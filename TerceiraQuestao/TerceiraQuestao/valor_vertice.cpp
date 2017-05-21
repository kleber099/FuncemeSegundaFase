#include "valor_vertice.h"

int ValorVertice::getId() {
	return this->id;
}

double ValorVertice::getValor() {
	return this->valor;
}

V_TIPO ValorVertice::getTipo() {
	return this->tipo;
}

void ValorVertice::subtrair(double valor) {

	if (valor <= this->valor) {
		this->valor -= valor;

		this->passeio++;
	}
}

void ValorVertice::incrementarPasseio() {
	this->passeio++;
}

int ValorVertice::getPasseio() {
	return this->passeio;
}

bool ValorVertice::isFornecer() {
	return this->fornecer;
}

void ValorVertice::fimFornecer() {
	this->fornecer = false;
}