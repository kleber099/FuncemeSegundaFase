#include "priorityUtils.h"

/**
* Retorna o volume de água disponível em cada zona de prioridade
* @param pArray é um vetor contendo as prioridades de cada zona
* @param vArray é o limite superior de cada zona
* @param minimumVolume é o volume mínimo do reservatório
* @param maximumVolume é o volume máximo do reservatório
* @param currentVolume é o volume atual do reservatório
* @return Retorna um vetor de Tupla<prioridade,volume>
*/
vector<Tupla> PriorityUtils::zonesAvailableSupply(vector<int> pArray, vector<double> vArray, double minimumVolume, double maximumVolume, double currentVolume) {

	VectorOfPriorityZones zonasPrioridades;

	//preencher as zonas de prioridades e retorna o ultimo nivel que o volume atual ultrapassa
	int nivel = 0;
	preencherZonas(minimumVolume, currentVolume, pArray, vArray, zonasPrioridades, &nivel);

	//ordena as zonas de prioridades
	sort(zonasPrioridades.begin(), zonasPrioridades.end());

	//calcula a quantidade de agua armazena em cada zona de prioridade
	vector<double>volumesFaixas(zonasPrioridades.size(), 0.0);
	calcularVolumeZonas(currentVolume, nivel, zonasPrioridades, volumesFaixas);

	//criar as tuplas de retornos no formato <prioridade,volume>
	vector<Tupla>tuplas;
	getTuplas(volumesFaixas, tuplas);

	return tuplas;
}

/**
* Preenche as Zonas de Prioridade informadas, retorna o último nível que contém água 
* @param minimumVolume Volume mínimo do reservatório
* @param currentVolume Volume corrente do reservatório
* @param pArray Vetor que contém uma prioridade em cada índice
* @param vArray Vetor que contém um volume em cada índice
* @param &zonasPrioridades Armazena as zonas de prioridades por meio de um objeto PriorityZone
* @param &nivel Armazena o último nível que contém água 
*/
void PriorityUtils::preencherZonas(const double minimumVolume, const double currentVolume, const vector<int> pArray, const vector<double> vArray, VectorOfPriorityZones& zonasPrioridades, int* nivel) 
{
	//Armazena a prioridade 0, com o valor mínimo do reservatório
	PriorityZone prioridadeZero(minimumVolume, 0);
	zonasPrioridades.push_back(prioridadeZero);

	//Percorrendo o vetor de prioridade, recuperando cada prioridade e volume
	//e adicionando no vetor de prioridades
	for (size_t i = 0; i < pArray.size(); i++) 
	{
		double volume = vArray[i];
		int prioridade = pArray[i];

		PriorityZone zona(volume, prioridade);
		zonasPrioridades.push_back(zona);

		//Atualização do nível, recuperando o último nivel que contém água
		if (currentVolume > volume && prioridade > *nivel) 
		{
			*nivel = prioridade;
		}
	}
}

/**
* Calcula o valor presente em cada Zona de Prioridade
* @param currentVolume Volume corrente do reservatóri
* @param nivel Último nível que contém água
* @param zonasPrioridades Contém a prioridade e o volume em cada zona
* @param &volumeZonas Armazena o volume calcuado em cada zona
*/
void PriorityUtils::calcularVolumeZonas(const double currentVolume, const int nivel, VectorOfPriorityZones zonasPrioridades, vector<double>& volumeZonas) 
{
	bool ultrapassou = false; //falso caso o volume da  última zona for maior que o volume corrente
	double volumeAtual = currentVolume;

	//Verificando se o volume da última zona for menor que o corrente volume
	int indiceUltimaZona = zonasPrioridades.size() - 1;
	if (currentVolume > zonasPrioridades[indiceUltimaZona].getAvailableVolume()) 
	{
		ultrapassou = true;
	}


	if (ultrapassou) 
	{
		//Armazendo o volume em cada zona
		for (int i = nivel; i > 0; i--) {
			double volume = zonasPrioridades[i].getAvailableVolume() - zonasPrioridades[i - 1].getAvailableVolume();
			volumeZonas[i] = volume;
		}
	}
	else
	{
		//Armazendo o volume em cada zona
		for (int i = nivel; i >= 0; i--) 
		{
			double volume = volumeAtual - zonasPrioridades[i].getAvailableVolume();

			if (volume < 0.0 && nivel == 0) {
				volumeZonas[i + 1] = 0.0;
			}
			else
			{
				volumeZonas[i + 1] = volume;
			}

			volumeAtual = zonasPrioridades[i].getAvailableVolume();
		}
	}
}

/**
* Retorna um vetor de Tupla<prioridade, volume> de cada zona
* @param volumeZonas Volume calculado em cada zona
* @param &tuplas Tuplas<prioridade, volume>
*/
void PriorityUtils::getTuplas(vector<double> volumeZonas, vector<Tupla>& tuplas)
{
	vector<Tupla>::iterator it = tuplas.begin();

	//percorre os volumes calculados e preenche as tuplas
	for (int i = volumeZonas.size() - 1; i > 0; i--)
	{
		Tupla tupla = make_tuple(i, volumeZonas[i]);
		it = tuplas.insert(it, tupla);
	}
}