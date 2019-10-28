#pragma once
#include <string>
#include "Data.h"

using namespace std;
class Prestec
{
public:
	Prestec(string codiUsuari, string codiPubl, Data dataPrestec, Data dataRetorn,
		int nDiesPrestec , int nRevisa)
	{
		m_codiUsuari = codiUsuari; m_codiPublicacio = codiPubl;
		m_dataPrestec = dataPrestec; m_dataRetorn = dataRetorn; 
		m_nDiesPrestec = nDiesPrestec; m_nRevista = nRevisa;
	}

private:
	string m_codiUsuari;
	string m_codiPublicacio;
	
	Data m_dataPrestec;
	Data m_dataRetorn;
	//per els llibres
	int m_nDiesPrestec;
	//per la revista
	int m_nRevista;
};

