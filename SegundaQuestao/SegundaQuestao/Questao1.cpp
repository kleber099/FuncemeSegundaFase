/*#include "priorityUtils.h"

int main() {

	vector<int> pArray;
	pArray.push_back(3);
	pArray.push_back(1);
	pArray.push_back(2);
	
	vector<double> vArray;
	vArray.push_back(8000.0);
	vArray.push_back(1000.0);
	vArray.push_back(2500.0);
	
	double minimumVolume = 500.0;
	double maximumVolume = 8000.0;
	double currentVolume = 2650.0;

	PriorityUtils pu;
	vector<Tupla>tuplas = pu.zonesAvailableSupply(pArray, vArray, minimumVolume, maximumVolume, currentVolume);

	for (int i = 0; i < tuplas.size(); i++) {
		int prioridade;
		double volume;
		tie(prioridade, volume) = tuplas[i];
		printf("{ %d : %lf }", prioridade, volume);
	}

	getchar();
    return 0;
}
*/
