#ifndef __PRIORITY_ZONE__
#define __PRIORITY_ZONE__

/**
* Classe que armazena a prioridade e o volume de uma Zona de Prioridade
*/
class PriorityZone
{
protected:
	double m_availableVolume;
	int m_priority;

public:
	PriorityZone(double availableVolume, int priority);
	double getAvailableVolume();
	int getPriority();
	bool operator < (const PriorityZone& priorityZone);
};

#endif