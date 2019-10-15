#include "Hash.h"
#include <math.h>

Hash::Hash(int numIni, const string& descripcioDefecte)
{
	m_maxElements = numIni;
	m_descripcioDefecte=descripcioDefecte;
	
	m_diccionari.resize(m_maxElements,pair<string,string>("",""));
	m_numOcupats = 0;
}

Hash::~Hash()
{
}

int Hash::codi(string s) const
{
	unsigned long valor = 0;
	for (int i = 0; i < s.size(); i++)
	{
		valor+= (s[i]*pow(2,i));
		valor = valor%m_maxElements;
	}	
	return valor;
}


void Hash::insertIntern(const string& clau, const string& descripcio)
{
	int index= codi(clau);
	if (m_diccionari[index].first == "")
	{
		//Inserim element a posicio buida
		m_diccionari[index].first = clau;
		m_diccionari[index].second = descripcio;
		m_numOcupats++;
	}
	else //Sino esta buida es COLLISIO
		throw "COL.LISIO";
}

bool Hash::find(const string& clau, string& definicio) const
{
	int index = codi(clau);
	bool trobat = false;
	if (m_diccionari[index].first == clau)
	{
		definicio = m_diccionari[index].second;
		trobat = true;
	}
	else
	{
		definicio = "";
	}	
	return trobat;
}

bool Hash::esborra(const string& clau)
{
	int index = codi(clau);
	bool trobat = false;
	if (m_diccionari[index].first == clau)
	{
		m_diccionari[index].first = "";
		m_diccionari[index].second = "";
		trobat = true;
		m_numOcupats--;
	}
	
	return trobat;
}

void Hash::insert(const string& clau, const string& descripcio)
{
	int index=codi(clau);
	
	if (m_diccionari[index].first == clau)
	{
		//Element trobat
		//Entenem que es una modificacio de la seva descripcio
		m_diccionari[index].second = descripcio;
	}
	else
	{   //Inserim un nou element
		insertIntern(clau, descripcio);				
	}
}

string& Hash::operator[](const string& clau)
{
	int index = codi(clau);
	
	if (m_diccionari[index].first == clau)
	{
		//Element trobat
		return m_diccionari[index].second;
	}
	else
	{//Element no trobat, l'inserim
		insertIntern(clau, m_descripcioDefecte);
		return m_descripcioDefecte;
	}
}

ostream& operator<<(ostream &out, const Hash& h)
{
	for (int i = 0; i < h.m_diccionari.size(); i++)
	{
		if (h.m_diccionari[i].first!="")
		{
			out<< "POS: " <<i <<"  CLAU: " << h.m_diccionari[i].first <<"  VALOR: " << h.m_diccionari[i].second <<endl;
		}		
	}
	return out;
}

