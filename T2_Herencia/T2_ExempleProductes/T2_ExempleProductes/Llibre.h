#pragma once
#include "Producte.h"
#include <string>
using namespace std;

class Llibre: public Producte
{
public:

	void setTitol(string titol) { m_titol = titol; }
	void setAutor(string autor) { m_autor = autor; }
	void setnPagines(int numPag) { m_numPagines = numPag; }
	
	string	getTitol() const { return m_titol; }
	string	getAutor() const { return m_autor; }
	int		getNPagines() const { return m_numPagines; }

	
private:
	string m_titol;
	string m_autor;
	int m_numPagines;

};

