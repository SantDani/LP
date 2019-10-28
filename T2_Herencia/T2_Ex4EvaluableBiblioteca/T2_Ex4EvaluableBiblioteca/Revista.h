#pragma once
#include "Publicacio.h"
#include "Exemplar.h"
#include <string>
#include<vector>

using namespace std;
class Revista : public Publicacio
{
public:
	
	Revista(string codi, string titol, string periodicitat, int nExemplars, vector<int>& lExemplar);
	
	Revista(const Revista& r) 
		: Publicacio(r) 
	{
		m_periodicitat = r.m_periodicitat; m_lExemplar = r.m_lExemplar; 
		m_nExemplars = r.m_nExemplars;
		m_lDisponible = r.m_lDisponible;
		m_dataPrestec = r.m_dataPrestec;
		
	}
	Revista* clone() { return new Revista(*this); }

	string getTipoClase() { return "R"; }
	int getNumDiasPrestec() { return -1; };
	void setNumPrestec() {};
	bool prestar(int codi, Data dataPrestec);
private:
	string m_periodicitat;
	vector<int> m_lExemplar ;
	vector<bool> m_lDisponible;
	vector<Data> m_dataPrestec;
	int m_nExemplars;
};

