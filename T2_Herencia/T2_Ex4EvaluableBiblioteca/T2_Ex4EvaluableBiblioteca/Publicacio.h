#pragma once
#include <string>
#include "Data.h"
using namespace std;
class Publicacio
{
public:
	//Constructors
	Publicacio() { m_codi = ""; m_titol = "";}
	Publicacio(string codi, string titol) { m_codi = codi; m_titol = titol; }
	Publicacio(const Publicacio& p) { m_codi = p.m_codi; m_titol = p.m_titol; }
	virtual Publicacio* clone() = 0;

	//Get- Set
	string getCodi() { return m_codi; }
	string getTitol() { return m_titol; }

	
	virtual string getTipoClase() { return  "P"; };
	virtual  int getNumDiasPrestec() { return -1; };
	virtual bool prestar(int codi , Data dataPrestec) { return 0; };
	virtual bool prestar(int codi) { return 0; };
	string getAutor() { return getAutor(); };
	
	
	
private:
	string m_codi;
	string m_titol;
};

