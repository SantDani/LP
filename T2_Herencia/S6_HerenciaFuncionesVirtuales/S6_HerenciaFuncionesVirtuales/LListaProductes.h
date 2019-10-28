#pragma once
#include "Llibre.h"
#include "Electrodomestic.h"
#include <list>
class LListaProductes
{
public:
	void afegeixLlibre(const Llibre& l);
	void afegeixElectrodomestic(const Electrodomestic& e);
	bool EliminaProducte(const string& codi);
	float getPreuProducte(const string& codi, int nUnitats) const;
	void mostra()const;

	~LListaProductes();
private:

	list<Producte*> m_lProducte;

};

