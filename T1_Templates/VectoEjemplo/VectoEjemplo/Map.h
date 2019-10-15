#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <utility>
#include "Persona.h"
#include "cerca_ordenacio.h"

using namespace std;

template<class TClau, class TValor>
class Map
{
public:
	//Constructores
	Map() : m_map(NULL), m_valor(NULL) {}
	Map(const Map& map);

	vector<TClau, TValor> getMap() { return m_map; }
	~Map();
	//Funciones
	int longitud() const ;
	bool esBuid() const ;
	void afegeix(TClau clau, TValor);

	//Sobrecargas
	TValor& operator[](const TClau& clau);
	TValor& operator[](const TClau& clau) const;

	TValor& operator[](const int& posicio);
	TValor& operator[](const int& posicio) const;
	Map<TClau, TValor>& operator=(const Map<TClau, TValor>& map) ;
	

private:
	vector <TClau, TValor> m_map;
	TValor m_valor;
};



template<class TClau, class TValor>
inline Map<TClau, TValor>::Map(const Map& map)
{
	for (int i = 0; i < longitud(); i++)
	{
		m_map[i] = map[i];
	}
	return *this;
}

template<class TClau, class TValor>
inline TValor& Map<TClau, TValor>::operator[](const TClau& clau)
{
	//TValor valorObtenido = NULL;
	//Persona persona;
	//bool resultado = cercaBinaria(m_map,clau, longitud(), persona);
	//
	//if (resultado)
	//	return persona.getEdat();

	//return persona.getEdat() ;//no me gusta


}

template<class TClau, class TValor>
inline TValor& Map<TClau, TValor>::operator[](const TClau& clau) const
{
	TValor valorObtenido = NULL;
	Persona persona;
	bool resultado = cercaBinaria(m_map, clau, longitud(), persona);

	if (resultado)
		return persona.getEdat();

	return persona;//no me gusta
}

template<class TClau, class TValor>
inline TValor& Map<TClau, TValor>::operator[](const int& posicio)
{

	if (posicio > 0 && posicio < longitud())
	{
		return get<1>(m_map[posicio]);
	}
	return *m_valor; // return m_valor;

}

template<class TClau, class TValor>
inline TValor& Map<TClau, TValor>::operator[](const int& posicio) const
{
	if (posicio > 0 && posicio < longitud())
	{
		return get<1>(m_map[posicio]);
	}
	return *m_valor; // return m_valor;

}

template<class TClau, class TValor>
inline Map<TClau, TValor>& Map<TClau, TValor>::operator=(const Map<TClau, TValor>& map)
{
	if (!(m_map == map))
	{
		for (int i = 0; i < longitud(); i++)
		{
			m_map[i] = map[i];
		}
	}
	return *this;
}

template<class TClau, class TValor>
 void Map<TClau, TValor>::afegeix(TClau clau, TValor valor)
{
	//Persona p(clau, valor);
	//bool encontrado = false;
	//encontrado = cercaBinaria(m_map);
	//if(!encontrado)
		m_map.push_back(pair<clau, valor>);
	//else


	
	//ordenar
	ordena(m_map, longitud());
}

template<class TClau, class TValor>
int Map<TClau, TValor>::longitud() const
{
	return m_map.size();
}

template<class TClau, class TValor>
bool Map<TClau, TValor>::esBuid() const
{
	if (longitud() == 0)
		return true;
	else
		return false;
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

template<class T>
void moverMayor(T*& vector, int j, int& nElements)
{
	T aux = vector[j];
	vector[j] = vector[j + 1];
	vector[j + 1] = aux;
	//mostrar(nElements, vector);
}


template<class T>
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