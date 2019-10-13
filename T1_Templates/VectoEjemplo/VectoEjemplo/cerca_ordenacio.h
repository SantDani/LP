#pragma once
#include <string>
#include <iostream>
#include "Persona.h"


using namespace std;
template<class T>
void mostrar(int nElements, T* vector);
template<class T>
void moverMayor(T*& vector, int j, int& nElements);
template<class T>
void MayorMenorNombre(T* vector, int j);
template <class T>

void ordena(T vector[], int nElements)
{
	for (int i = 0; i < nElements; i++)
	{
		for (int j = 0; j < nElements - 1; j++)
		{
			//MayorMenorNombre(vector, j);
			if (std::is_same<T, Persona>::value)
			{
				if (!(vector[j] > vector[j + 1]))
					moverMayor(vector, j, nElements);

			}
			if (vector[j] > vector[j + 1])
				moverMayor(vector, j, nElements);
		}
	}
}

template<class T>
void MayorMenorNombre(T* vector, int j)
{
	T mayor = vector[j];
	T menor = vector[j + 1];
	cout << vector[j] << " es mayor que? " << vector[j + 1] << endl;
}

template<class T>
void moverMayor(T*& vector, int j, int& nElements)
{
	T aux = vector[j];
	vector[j] = vector[j + 1];
	vector[j + 1] = aux;
	//mostrar(nElements, vector);
}




template<class T>
void mostrar(int nElements, T* vector)
{
	//cout << "Luego de ordenar" << endl;
	for (int i = 0; i < nElements; i++)
	{

		cout << vector[i] << "\t";
	}
	cout << endl;
}


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
				superior = medio - 1;
			else
				inferior = medio + 1;
		}

	}
	return encontrado;
}

