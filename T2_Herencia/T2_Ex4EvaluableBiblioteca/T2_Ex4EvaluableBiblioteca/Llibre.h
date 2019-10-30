#pragma once
#include "Publicacio.h"
#include <string>

using namespace std;
class Llibre : public Publicacio
{
public:
	Llibre() { m_nCopias = 0; m_nDiasPrestec = 0; m_nAlquilados = 0; }
	Llibre(string codi, string titol, string autor, int nCopias, int nDiasPrestec)
		:Publicacio(codi, titol) 
	{
		m_autor = autor; m_nCopias = nCopias; m_nDiasPrestec = nDiasPrestec; 
		m_nAlquilados = 0;
	}
	Llibre(const Llibre& l)
		: Publicacio(l) {
		m_autor = l.m_autor; m_nCopias = l.m_nCopias; m_nDiasPrestec = l.m_nDiasPrestec; m_nAlquilados = 0;
	}
	Llibre* clone() { return new Llibre(*this); }

	// Get -Set
	int getNumAlquilados() { return m_nAlquilados; }
	int getNumDiasPrestec() { return m_nDiasPrestec; }

	string getAutor() { return m_autor; }
	bool prestar(int codi);
	void devolver();
	string getTipoClase() { return "L"; }

private:
	string m_autor;
	int m_nCopias;
	int m_nDiasPrestec;
	int m_nAlquilados;

};

