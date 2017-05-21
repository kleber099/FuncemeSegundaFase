#include "priorityUtils.h"

/**
* Retorna o volume de �gua dispon�vel em cada zona de prioridade
* @param pArray � um vetor contendo as prioridades de cada zona
* @param vArray � o limite superior de cada zona
* @param minimumVolume � o volume m�nimo do reservat�rio
* @param maximumVolume � o volume m�ximo do reservat�rio
* @param currentVolume � o volume atual do reservat�rio
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
* Preenche as Zonas de Prioridade informadas, retorna o �ltimo n�vel que cont�m �gua 
* @param minimumVolume Volume m�nimo do reservat�rio
* @param currentVolume Volume corrente do reservat�rio
* @param pArray Vetor que cont�m uma prioridade em cada �ndice
* @param vArray Vetor que cont�m um volume em cada �ndice
* @param &zonasPrioridades Armazena as zonas de prioridades por meio de um objeto PriorityZone
* @param &nivel Armazena o �ltimo n�vel que cont�m �gua 
*/
void PriorityUtils::preencherZonas(const double minimumVolume, const double currentVolume, const vector<int> pArray, const vector<double> vArray, VectorOfPriorityZones& zonasPrioridades, int* nivel) 
{
	//Armazena a prioridade 0, com o valor m�nimo do reservat�rio
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

		//Atualiza��o do n�vel, recuperando o �ltimo nivel que cont�m �gua
		if (currentVolume > volume && prioridade > *nivel) 
		{
			*nivel = prioridade;
		}
	}
}

/**
* Calcula o valor presente em cada Zona de Prioridade
* @param currentVolume Volume corrente do reservat�ri
* @param nivel �ltimo n�vel que cont�m �gua
* @param zonasPrioridades Cont�m a prioridade e o volume em cada zona
* @param &volumeZonas Armazena o volume calcuado em cada zona
*/
void PriorityUtils::calcularVolumeZonas(const double currentVolume, const int nivel, VectorOfPriorityZones zonasPrioridades, vector<double>& volumeZonas) 
{
	bool ultrapassou = false; //falso caso o volume da  �ltima zona for maior que o volume corrente
	double volumeAtual = currentVolume;

	//Verificando se o volume da �ltima zona for menor que o corrente volume
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