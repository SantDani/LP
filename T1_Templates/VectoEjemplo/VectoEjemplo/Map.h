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
