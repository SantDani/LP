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
				{
					moverMayor(vector, j, nElements);

				}
			}
			if (vector[j] > vector[j + 1])
			{
				moverMayor(vector, j, nElements);
			}
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


template <class T>
bool cercaBinaria(T vector[], const T& valor, int nElements)
{

	int mitad, i;
	int inf = 0;
	int sup = nElements-1;
	i = 0;

	bool encontrado = false;
	

	while ((inf <= sup))
	{
		//falta ver porque no encuntra los elementos de persona
		mitad = (inf + sup) / 2;
		if (vector[mitad] == valor)
		{
			encontrado = true;
			return encontrado;
		}else 
			if (vector[mitad] > valor )
			{
				sup = mitad - 1;
			} 
			else //(vector[mitad] < valor) 
			{
				inf = mitad +1;
			}
		i++;
	}
	return encontrado;
}

