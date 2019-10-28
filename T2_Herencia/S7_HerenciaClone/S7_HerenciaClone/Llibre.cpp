#include "Llibre.h"
#include <iostream>
using namespace std;


float Llibre::calculaDespesesEnviament()
{
	float despeses = Producte::calculaDespesesEnviament();
	if (m_nPagines > 500)
		despeses += 1;
	return despeses;
}

float Llibre::calculaPreu(int nUnitats)
{
	float preu = (m_preu * nUnitats) + calculaDespesesEnviament();
	if (nUnitats > 10)
		preu -= 0.05 * preu;
	else
		if (nUnitats > 100)
			preu -= 0.1 * preu;
	return preu;
}

void Llibre::mostra()
{
	Producte::mostra();
	cout << "Titol: " << m_titol << endl;
	cout << "Autor: " << m_autor << endl;
	cout << "N. pagines: " << m_nPagines << endl << endl;
}
