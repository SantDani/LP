#include "Hash.h"
#include <math.h>



Hash::Hash(int sizeInicial,const  string& descripcio)
{
	m_numElements = sizeInicial;
	m_descripcioDefecte = descripcio;
	m_diccionari.resize(m_numElements);
	for (int i = 0; i < m_numElements; i++)
	{
		m_diccionari[i].first = "";
		m_diccionari[i].second = "";
	}
}

Hash::~Hash()
{
}

int Hash::getIndiceCodigo(string s) const
{
	unsigned long valor = 0;
	for (int i = 0; i < s.size(); i++)
	{
		valor+= (s[i]*pow(2,i));
		valor = valor%m_numElements;
	}	
	return valor;
}

bool Hash::find(const string& clau, string& definicio) const
{
	int index = getIndiceCodigo(clau);
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

void Hash::insert(const string& clau, const string& descripcio)
{
	int index=getIndiceCodigo(clau);
	
	if (m_diccionari[index].first == clau)
	{
		//Element trobat
		//Entenem que es una modificacio de la seva descripcio
		m_diccionari[index].second = descripcio;
		throw "COLISIO, elemento modificado";
	}
	else
	{		//Elemento no encontrado
			//Inserim un nou element
			m_diccionari[index].first = clau;
			m_diccionari[index].second = descripcio;
		
	}
}

string& Hash::operator[](const string& clau)
{
	int index = getIndiceCodigo(clau);
	
	if (m_diccionari[index].first == clau)
	{
		//Element trobat
		return m_diccionari[index].second;
	}
	else
	{//Element no trobat, l'inserim
		string definicioDefecte = "Elemento no existe";
		m_diccionari[index].first = clau;
		m_diccionari[index].second = definicioDefecte	;
		return m_diccionari[index].second;
	}
}

ostream& operator<<(ostream &out, const Hash& h)
{
	for (int i = 0; i < h.m_diccionari.size(); i++)
	{
		if (h.m_diccionari[i].first!="")
		{
			out<< "POS: " <<i <<"\tCLAU:" << h.m_diccionari[i].first <<"\t\tVALOR: " << h.m_diccionari[i].second <<endl;
		}		
	}
	return out;
}

