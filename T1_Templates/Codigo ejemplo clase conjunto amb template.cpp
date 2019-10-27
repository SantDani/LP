#pragma once
#include <iostream>
using namespace std;

template <class T>
class Conjunt
{
public:
	Conjunt();
	~Conjunt();
	bool afegeix(const T& valor);
	bool elimina(const T& valor);
	bool existeix(const T& valor) const;
	bool esBuit() const { return (m_nElements == 0); }
	void mostra() const;
private:
	T* m_elements;
	int m_nElements;
	int m_maxElements;
	static const int MAX_ELEMENTS = 5;

	int cercaElement(const T& valor) const;
};

template <class T>
Conjunt<T>::Conjunt()
{
	m_maxElements = MAX_ELEMENTS;
	m_elements = new T[m_maxElements];
	m_nElements = 0;
}

template <class T>
Conjunt<T>::~Conjunt()
{
	delete[] m_elements;
}

template <class T>
bool Conjunt<T>::afegeix(const T& valor)
{
	bool afegit = false;
	if (!existeix(valor))
	{
		afegit = true;
		if (m_nElements == m_maxElements)
		{
			T* aux = new T[m_maxElements * 2];
			for (int i = 0; i < m_maxElements; i++)
				aux[i] = m_elements[i];
			delete[]m_elements;
			m_elements = aux;
			m_maxElements *= 2;
		}
		m_elements[m_nElements] = valor;
		m_nElements++;
	}
	return afegit;
}

template <class T>
bool Conjunt<T>::elimina(const T& valor)
{
	bool eliminat = false;
	int posicio = cercaElement(valor);
	if (posicio >= 0)
	{
		eliminat = true;
		for (int i = posicio; i < (m_nElements - 1); i++)
			m_elements[i] = m_elements[i + 1];
		m_nElements--;
	}
	return eliminat;
}

template <class T>
bool Conjunt<T>::existeix(const T& valor) const
{
	bool trobat = false;
	int posicio = cercaElement(valor);
	if (posicio >= 0)
		trobat = true;
	return trobat;
}

template <class T>
int Conjunt<T>::cercaElement(const T& valor) const
{
	bool trobat = false;
	int posicio = 0;
	while (!trobat && (posicio < m_nElements))
	{
		if (m_elements[posicio] == valor)
			trobat = true;
		else
			posicio++;
	}
	if (trobat)
		return posicio;
	else
		return -1;
}

template <class T>
void Conjunt<T>::mostra() const
{
	cout << "Elements del conjunt: " << endl;
	for (int i = 0; i < m_nElements; i++)
		cout << m_elements[i] << endl;
}