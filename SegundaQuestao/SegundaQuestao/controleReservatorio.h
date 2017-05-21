#ifndef __CONTROLLER_RESERVATORIO__
#define __CONTROLLER_RESERVATORIO__

#include "reservatorio.h"
#include "Faixa.h"

#include <vector>

using namespace std;
using Tupla = tuple<int, double>;

/**
* Classe que relizar o controler da quantidade em cada zona de prioridade, recupera os dados necessários e e retorna o
* resultado calculado nas zonas
*/
class ControllerReservatorio
{
public:
	vector<Tupla> atualizar(Reservatorio reser, vector<Faixa> faixas);
};

#endif

