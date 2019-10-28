#include "LlistaProductes.h"
#include "Producte.h"
#include <iostream>
using namespace std;

LlistaProductes::LlistaProductes(const LlistaProductes& lp)
{
	//eliminar actual
	list<Producte*>::const_iterator  it = lp.m_productes.begin();
	for  (;  it != lp.m_productes.end(); it++)
	{
		m_productes.push_back((*it)->clone());
	}


}

LlistaProductes& LlistaProductes::operator=(LlistaProductes& lp)
{
	if (this != &lp)
	{
		list<Producte*>::iterator it = m_productes.begin();

		while (it != m_productes.end())
		{
			delete* it;
			it = m_productes.erase(it);
			
		}
		
		for (it = lp.m_productes.begin(); it != lp.m_productes.end(); it++)
		{
			m_productes.push_back((*it)->clone());
		}
	}
	return *this;
}

void LlistaProductes::vaciarListaProductos(std::list<Producte*>::iterator& it)
{
	while (it != m_productes.end())
	{
		delete* it;
		it = m_productes.erase(it);
		mostra();
	}
}

LlistaProductes::~LlistaProductes()
{
	if (m_productes.size() > 0)
	{
		list<Producte*>::const_iterator it;
		for (it = m_productes.begin(); it != m_productes.end(); it++)
			delete* it;
	}
}

void LlistaProductes::liberarMemoriaListaProductos()
{
	
	
}

void LlistaProductes::afegeixLlibre(const Llibre& l)
{
	m_productes.push_back(new Llibre(l));
}

void LlistaProductes::afegeixElectrodomestic(const Electrodomestic& e)
{
	m_productes.push_back(new Electrodomestic(e));
}

bool LlistaProductes::eliminaProducte(const string& codi)
{
	list<Producte*>::iterator it = m_productes.begin();
	bool trobat = false;
	while (!trobat && (it != m_productes.end()))
	{
		if ((*it)->getCodi() == codi)
			trobat = true;
		else
			it++;
	}
	if (trobat)
	{
		delete *it;
		m_productes.erase(it);
	}
	return trobat;
}

float LlistaProductes::getPreuProducte(const string& codi, int nUnitats) const
{
	float preu = -1.0;
	list<Producte*>::const_iterator it = m_productes.begin();
	bool trobat = false;
	while (!trobat && (it != m_productes.end()))
	{
		if ((*it)->getCodi() == codi)
			trobat = true;
		else
			it++;
	}
	if (trobat)
		preu = (*it)->calculaPreu(nUnitats);
	return preu;
}

void LlistaProductes::mostra() const
{
	cout << "***********************START ****************************"  << endl;
	list<Producte*>::const_iterator it;
	for (it = m_productes.begin(); it != m_productes.end(); ++it)
		(*it)->mostra();
	cout << "**************************END **************************"<< endl << endl ;
}