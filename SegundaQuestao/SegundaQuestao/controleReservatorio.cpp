#include "controleReservatorio.h"
#include "priorityUtils.h"

/**
* Construtor de uma Zona de prioridade
*
* @param reser Contém os dados do reservatório que vem da interface gráfica
* @param faixas Vetor de faixas que vem da interface gráfica
* @return vector<Tupla> Retona as tupas no formato Tupla<prioridade, volume>, nela contém os valores calculados em cada zona
*/
vector<Tupla> ControllerReservatorio::atualizar(Reservatorio reser, vector<Faixa> faixas) {

	vector<int> pArray;		//vetor de prioridade
	vector<double> vArray;	//vetor de volumes

	//percorrendo as faixa e construindo o vetor de prioridades e volumes
	for (size_t i = 0; i < faixas.size(); i++) {
		pArray.push_back(faixas[i].getPrioridade());
		vArray.push_back(faixas[i].getFaixaSuperior());
	}

	//recuperando os dados do reservatório
	double minimumVolume = reser.getMinimo();
	double maximumVolume = reser.getMaximo();
	double currentVolume = reser.getInicial();

	//recuperando o calculo das zonas de prioridades
	PriorityUtils pu;
	vector<Tupla>tuplas = pu.zonesAvailableSupply(pArray, vArray, minimumVolume, maximumVolume, currentVolume);

	return tuplas;

}