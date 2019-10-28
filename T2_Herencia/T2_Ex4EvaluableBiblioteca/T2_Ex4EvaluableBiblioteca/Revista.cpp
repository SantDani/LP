#include "Revista.h"
#include "Publicacio.h"
#include <vector>
#include "Exemplar.h"
using namespace std;
Revista::Revista(string codi, string titol, string periodicitat, int nExemplars, vector<int>& lExemplar ) : Publicacio(codi, titol)
{
	m_periodicitat = periodicitat; 
	m_lExemplar = lExemplar;
	m_lDisponible.resize(lExemplar.size(), true);
	m_nExemplars = lExemplar.size();
	m_dataPrestec.resize(nExemplars, Data(0, 0, 0));
	
}

bool Revista::prestar(int codi, Data dataPrestec)
{
	int cont = 0;
	
	if (m_nExemplars > 0) 
	{
		while (cont < m_lExemplar.size())
		{
			if (m_lExemplar[cont] == codi)
			{
				if (m_lDisponible[cont])
				{
					m_dataPrestec[cont] = dataPrestec;
					m_lDisponible[cont] = false;
					return true;
				}
				else
					return false;
			}
			cont++;

		}
	}
	

	return false;
}
