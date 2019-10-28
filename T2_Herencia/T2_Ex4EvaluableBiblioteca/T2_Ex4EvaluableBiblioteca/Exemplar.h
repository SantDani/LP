#pragma once
#include "Revista.h"
#include "Publicacio.h"
#include <string>
#include<list>

using namespace std;
class Exemplar 
{
public: 
	Exemplar();
	//Exemplar() { m_codiRevista = 0; m_disponible = true; };
	Exemplar(int codi, bool disponible = true) { m_codiRevista = codi; m_disponible = disponible; }

	int getCodi() { return m_codiRevista; }
	bool getDisponible() { return m_disponible; }
	void setDisponible(bool disponible) { m_disponible = false; };
	
private:
	
protected:
	int m_codiRevista;
	bool m_disponible;
	Data m_prestec;
};

