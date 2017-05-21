#ifndef __PRIORITY_UTILS__
#define __PRIORITY_UTILS__

#include "priorityZone.h"

#include <array>
#include <vector>

using namespace std;

using VectorOfPriorityZones = vector<PriorityZone>;

using Tupla = tuple<int, double>;

/**
* Classe utilitária que avalia as Zonas de Prioridades, os volumes presentes um Reservatório que são informados
*
*/
class PriorityUtils
{
private:
	void preencherZonas(const double minimumVolume, const double currentVolume, const vector<int> pArray, const vector<double> vArray, VectorOfPriorityZones& zonasPrioridades, int* nivel);
	void calcularVolumeZonas(const double currentVolume, const int nivel, VectorOfPriorityZones zonasPrioridades, vector<double>& volumeZonas);
	void getTuplas(vector<double> volumeZonas, vector<Tupla>& tuplas);

public:
	/** @brief
	* Retorna o volume de água disponível em cada zona de prioridade
	* @param pArray é um vetor contendo as prioridades de cada zona
	* @param vArray é o limite superior de cada zona
	* @param minimumVolume é o volume mínimo do reservatório
	* @param maximumVolume é o volume máximo do reservatório
	* @param currentVolume é o volume atual do reservatório
	*/
	vector<Tupla> zonesAvailableSupply(vector<int> pArray, vector<double> vArray, double minimumVolume, double maximumVolume, double currentVolume);
};

#endif /** __PRIORITY_UTILS__ **/
