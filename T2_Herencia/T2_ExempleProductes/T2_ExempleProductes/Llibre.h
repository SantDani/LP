#pragma once
#include "Producte.h"
#include <string>
using namespace std;

class Llibre: public Producte
{
public:
	//Constructores
	//Constructor por defecto
	Llibre() { m_titol = ""; m_autor = ""; m_numPagines = 0; }
	//Constructor por valores
	Llibre(string codi, float preu, string titol, string autor, int numPag)
		:Producte(codi, preu) { m_titol = titol; m_autor = autor; m_numPagines = numPag; }
	//Constructor copia
	Llibre(const Llibre& l) 
		: Producte(l) { m_titol = l.m_titol; m_autor = m_autor; m_numPagines = l.m_numPagines; }
	~Llibre();

	//Get - Set
	void setTitol(string titol) { m_titol = titol; }
	void setAutor(string autor) { m_autor = autor; }
	void setnPagines(int numPag) { m_numPagines = numPag; }
	string	getTitol() const { return m_titol; }
	string	getAutor() const { return m_autor; }

	//Funciones
	int	getNPagines() const { return m_numPagines; }

	
private:
	string m_titol;
	string m_autor;
	int m_numPagines;
};

