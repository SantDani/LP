#pragma once

#include "Producte.h"
#include <iostream>
using namespace std;

float Producte::calculaDespesesEnviament()
{
	float despeses;

	if (m_preu < 100)
		despeses = 1.0;
	else
		despeses = 0.01 * m_preu;
	if (despeses > 5)
		despeses = 5;
	return despeses;
}


void Producte::mostra()
{
	cout << "---------------------------" << endl;
	cout << "Codi: " << m_codi << endl;
	cout << "Preu: " << m_preu << endl;
}

