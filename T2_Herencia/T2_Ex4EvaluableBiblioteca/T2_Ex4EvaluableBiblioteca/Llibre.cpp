#include "Llibre.h"

#include "Publicacio.h"
#include <string>
#include <iostream>

using namespace std;

bool Llibre::prestar(int codi)
{
	bool prestar = false;

	if (m_nAlquilados < m_nCopias) 
	{
		m_nAlquilados++;
		prestar = true;
	}

	return prestar;
}

void Llibre::devolver()
{
	if (m_nAlquilados <= 0)
		cout << "error al devolver, ya que, no se pueden devolver mas" << endl;
	else
	{
		m_nAlquilados--;
	}
}
