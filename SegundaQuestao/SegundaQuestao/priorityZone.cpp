#include "priorityZone.h"

/**
* Construtor de uma Zona de prioridade
*
* @param availableVolume Volume da Zona de Prioridade
* @param priority Prioridade da Zona de Prioridade
*/
PriorityZone::PriorityZone(double availableVolume,
	int priority) : m_availableVolume(availableVolume),
	m_priority(priority)
{
}

/**
* Retorna o volume da Zona de prioridade
* @return Volume da Zona de Prioridade
*/
double PriorityZone::getAvailableVolume()
{
	return m_availableVolume;
}

/**
* Retorna a prioridade da Zona de prioridade
* @return Prioridade da Zona de Prioridade
*/
int PriorityZone::getPriority()
{
	return m_priority;
}

/**
* Sobreescrevendo o operador <, é utilizadod na função sort, para ordenar por m_priority
* @param availableVolume Volume da Zona de Prioridade
*/
bool PriorityZone::operator < (const PriorityZone& priorityZone)
{
	return (m_priority < priorityZone.m_priority);
}