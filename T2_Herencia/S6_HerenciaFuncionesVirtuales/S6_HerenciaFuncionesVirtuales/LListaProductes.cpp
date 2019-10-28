#include "LListaProductes.h"
#include <iostream>

void LListaProductes::afegeixLlibre(const Llibre& l)
{
	Llibre* llibre = new Llibre(l);
	m_lProducte.push_back(llibre);
}

void LListaProductes::afegeixElectrodomestic(const Electrodomestic& e)
{
	Electrodomestic *ele = new Electrodomestic(e);
	m_lProducte.push_back(ele);
}

bool LListaProductes::EliminaProducte(const string& codi)
{
	bool trobat = false;
	list<Producte*>::iterator itActual = m_lProducte.begin();

	while (!trobat && itActual != m_lProducte.end())
	{
		string normalGet = (*itActual)->getCodi();
		
		if ((*itActual)->getCodi() == codi)
		{
			delete *itActual;//elimino el elemento PRoducto
			trobat = true;
			m_lProducte.erase(itActual);//elimino la direccion de memoria del eelemento
		}
		else
			itActual++;
	}

	return trobat;
}

float LListaProductes::getPreuProducte(const string& codi, int nUnitats) const
{
	float preu = 0.0;
	bool trobat = false;

	list<Producte*>::const_iterator itActual = m_lProducte.begin();

	while (!trobat && itActual != m_lProducte.end())
	{
		string normalGet = (*itActual)->getCodi();

		if ((*itActual)->getCodi() == codi)
		{
			//preu = (*itActual)->calcularPreu(nUnitats);
		}
		else
			itActual++;
	}

	return preu;
}

void LListaProductes::mostra() const
{
	list<Producte*>::const_iterator itActual = m_lProducte.begin();

	while ( itActual != m_lProducte.end())
	{
		(*itActual)->mostra();
		itActual++;
	}
	cout << endl;
}

LListaProductes::~LListaProductes()
{
	list<Producte*>::iterator it = m_lProducte.begin();

	for (; it != m_lProducte.end(); it++)
	{
		delete* it;
	}
}


