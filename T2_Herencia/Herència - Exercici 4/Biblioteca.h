#pragma once
#include "Data.h"
#include <string>
using namespace std;

class Biblioteca
{
public:
	Biblioteca() {}
	~Biblioteca() {}

	void llegirPublicacions(const string& nomFitxer);
	bool prestar(const string& idUsuari, const string& codi, const Data& dataPrestec, Data& dataRetorn, int nExemplar = 0);
	bool retornar(const string& idUsuari, const string& codi, const Data& data, bool &dataCorrecta, int nExmplar = 0);
private:



};

