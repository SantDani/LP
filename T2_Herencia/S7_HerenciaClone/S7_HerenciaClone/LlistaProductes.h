#pragma once
#include "Producte.h"
#include "Llibre.h"
#include "Electrodomestic.h"
#include <list>
using namespace std;

class LlistaProductes
{
public:
	LlistaProductes() {}
	
	~LlistaProductes();
	void liberarMemoriaListaProductos();
	void afegeixLlibre(const Llibre& l);
	void afegeixElectrodomestic(const Electrodomestic& e);
	bool eliminaProducte(const string& codi);
	float getPreuProducte(const string& codi, int nUnitats) const;
	void mostra() const;

	//add constructor copia by Clone
	LlistaProductes(const LlistaProductes& lp);
	//operador de asignacion
	LlistaProductes& operator=(LlistaProductes& lp);
	void vaciarListaProductos(std::list<Producte*>::iterator& it);
private:
	list<Producte*> m_productes;
};