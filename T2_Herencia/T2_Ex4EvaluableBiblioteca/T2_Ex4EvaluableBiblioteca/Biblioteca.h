#pragma once
#include "Data.h"
#include "Llibre.h"
#include "Revista.h"
#include <string>
#include <list>
#include "Prestec.h"
using namespace std;

class Biblioteca
{
public:
	Biblioteca() {}
	~Biblioteca() {}

	void afegirLlibre(const Llibre& l);
	void afegirRevista(const Revista& r);
	void llegirPublicacions(const string& nomFitxer);

	virtual bool prestar(const string& idUsuari, const string& codi, const Data& dataPrestec, Data& dataRetorn, int nExemplar = 0);
	bool retornar(const string& idUsuari, const string& codi, const Data& data, bool &dataCorrecta, int nExmplar = 0);
private:

	list<Publicacio*> m_lPublicacio;
	list<Prestec> m_lPrestec;
	const string LLIBRE = "L";
	const string REVISTA = "R";

	
};

