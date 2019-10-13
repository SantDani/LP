#include "Conjunt.h"
using namespace std;


ConjuntRacionals::ConjuntRacionals(int nElements)
{
	m_maxElements	= nElements;
	m_conjunt		= new Racional[nElements];
	m_nElements		= 0;

}

ConjuntRacionals::~ConjuntRacionals()
{
	delete[] m_conjunt;//corchetes para eliminar toda la array
}

ConjuntRacionals& ConjuntRacionals::operator=(ConjuntRacionals& c)
{
	m_maxElements	= c.m_maxElements;
	m_nElements		= c.m_nElements;

	if(m_conjunt != NULL)
		delete[] m_conjunt;
	m_conjunt = new Racional[c.m_maxElements];

	for (int i = 0; i < c.m_maxElements; i++)
	{
		m_conjunt[i] = c.m_conjunt[i];
	}

	return *this;// WHY apuntador.... oesase ya estaba declarado como apuntador
}

void ConjuntRacionals::afegeix(const Racional& r)
{
	m_conjunt[m_nElements] = r;
	m_nElements++;
}
