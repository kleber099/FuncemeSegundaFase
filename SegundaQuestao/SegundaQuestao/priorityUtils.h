#ifndef __PRIORITY_UTILS__
#define __PRIORITY_UTILS__

#include "priorityZone.h"

#include <array>
#include <vector>

using namespace std;

using VectorOfPriorityZones = vector<PriorityZone>;

using Tupla = tuple<int, double>;

/**
* Classe utilit�ria que avalia as Zonas de Prioridades, os volumes presentes um Reservat�rio que s�o informados
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
	* Retorna o volume de �gua dispon�vel em cada zona de prioridade
	* @param pArray � um vetor contendo as prioridades de cada zona
	* @param vArray � o limite superior de cada zona
	* @param minimumVolume � o volume m�nimo do reservat�rio
	* @param maximumVolume � o volume m�ximo do reservat�rio
	* @param currentVolume � o volume atual do reservat�rio
	*/
	vector<Tupla> zonesAvailableSupply(vector<int> pArray, vector<double> vArray, double minimumVolume, double maximumVolume, double currentVolume);
};

#endif /** __PRIORITY_UTILS__ **/
