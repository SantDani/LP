#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

template<class TClau, class TValor>
class Map
{
public:
	//Constructores
	Map();
	Map(const Map<TClau, TValor>& m);
	Map(TClau clau, TValor valor);

	//Funciones
	void afegeix(const TClau &clau, const TValor &valor);
	int longitud() const;
	bool esBuit();

	//Operadores
	Map<TClau, TValor>& operador = (Map<TClau, TValor> & Map);
	
	TValor& operator[](const int& posicio) ;

	TValor& operator[](const TClau& clau);
	const TValor& operator[](const TClau& clau) const ;

private:

	vector<pair<TClau, TValor>> m_vector;
	const TClau m_defectoClau;
	const TValor m_defectoValor;

};





template<class TClau, class TValor>
inline Map<TClau, TValor>::Map(const Map<TClau, TValor>& m)
{
	m_vector = m.m_vector;
	m_defectoClau = m.m_defectoClau;
	m_defectoValor = m.m_defectoValor;
	return *this;
}

template<class TClau, class TValor>
inline void Map<TClau, TValor>::afegeix(const TClau& clau, const TValor& valor)
{
	typename vector<pair<TClau, TValor>>::iterator itActual = m_vector.begin();

	bool trobat = false;

	while (itActual != m_vector.end() && !trobat)
	{
		if (itActual->frist > clau)
		{
			//insertamos wey porque ya sabes no existe
			pair<TClau, TValor> newPair(clau, valor);
			m_vector.insert(itActual, newPair);
			trobat = true;
		}
		else
		{
			//en este caso que no es mas enano comprobasmos si es igual 
			if (clau == itActual->frist)
			{
				//es igual pues substituimos el valor
				itActual->second = valor;
				trobat = true;
			}
			else
			{
				//no cumple ninguna condicion, veamos el siguiente
				itActual++;
			}
		}
	}
}

template<class TClau, class TValor>
inline TValor& Map<TClau, TValor>::operator[](const int& posicio)
{
	int size = m_vector.size();

	if (posicio > 0 && posicio < size)
	{
		return m_vector[posicio].frist;
	}
	else
		return m_defectoValor;//inicializado en constructor
}

template<class TClau, class TValor>
inline const TValor& Map<TClau, TValor>::operator[](const TClau& clau) const
{
	//busqueda binaria
	TClau max = m_vector.size()-1;
	TClau min = 0;
	TClau medio = 0;
	int pos = 0;
	bool trobat = false;
	while (pos < m_vector.size() && !trobat)
	{
		medio = (max + min) / 2;
		if (m_vector[medio].frist == clau)
		{
			trobat = true;
			return m_vector[medio].second;
		}
		else
		{
			if (clau < m_vector[medio].frist)
			{
				max = medio - 1;
			}
			else//en este caso mayor
			{
				min = medio + 1;
			}
		}
	}
	//si no se ha encontrado
	return m_defectoValor;
}

