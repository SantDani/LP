#pragma once
#include <string>
#include <iostream>

using namespace std;

//Metodo burbuj ordenar
template <class T>
void ordena(T vector[], int nElements)
{
	for (int i = 0; i < nElements; i++)
	{
		for (int j = 0; j < nElements - 1; j++)
		{
			if (vector[j] > vector[j + 1])
			{
				T aux = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = aux;
			}
		}
	}
}

template <class T>
void mostrar(T vector[], int nElements) 
{
	for (int j = 0; j < nElements ; j++)
	{
		cout << vector[j] << "\t";
	}
	cout << endl;
}

template <class T>
bool cercaBinaria(T vector[], const T& valor, int nElements)
{

	int mitad, i;
	int inf = 0;
	int sup = nElements - 1;
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
		}
		else
			if (vector[mitad] > valor)
			{
				sup = mitad - 1;
			}
			else //(vector[mitad] < valor) 
			{
				inf = mitad + 1;
			}
		i++;
	}
	return encontrado;
}


