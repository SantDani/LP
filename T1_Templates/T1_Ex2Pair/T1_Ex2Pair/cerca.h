#pragma once
#include <utility>
using namespace std;

template <class TClau, class TValor>
bool cercaBinaria(pair<TClau, TValor> vector[], 
	const TClau& clau, int nElements, TValor& valor)
{
	int inferior, superior, medio;
	inferior = 0;
	superior = nElements;

	bool encontrado = false;
	while (inferior <= superior)
	{
		medio = (superior + inferior) / 2;
		//string nombre = get<0>(vector[medio]);
		if (get<0>(vector[medio]) == clau)
		{
			valor = get<1>(vector[medio]);
			return true; //encontrado!
		}
		else
		{
			if (get<0>(vector[medio]) > clau)
				superior = medio- 1;
			else
				inferior = medio + 1;
		}
			
	}
	return encontrado;
}

template<class TClau, class TValor>
void mostrar(pair<TClau, TValor> vector[], int nElements)
{
	for (int i = 0; i < nElements; i++)
	{
		cout << "Clau: "<< vector[i].frist << " valor: " << vector[i].second << endl;
	}
}