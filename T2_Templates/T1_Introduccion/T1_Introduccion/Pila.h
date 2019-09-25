#pragma once

template <class T>
class Pila
{
public:

	Pila();
	~Pila();
	void push(const T& valor);
	void pop() { m_top--; };
	T top() const { return m_pila[m_top]; }
	bool esBuida() const { return (m_top == -1); }

private:

	T* m_pila;
	int m_top;
	int m_maxElements;
	static const int MAX_ELEMENTS = 5;
};


template<class T>
Pila<T>::Pila()
{
	m_maxElements = MAX_ELEMENTS;
	m_pila = new T[m_maxElements];
	m_top = -1;
}

template<class T>
Pila<T>::~Pila()
{
	delete[] m_pila;
}

template<class T>
void Pila<T>::push(const T& valor)
{
	if ((m_top + 1) >= m_maxElements)
	{
		T* aux = new T[m_maxElements * 2];
		for (int i = 0; i < m_maxElements; i++)
		{
			aux[i] = m_pila[i];

		}
		delete[] m_pila;
		m_pila = aux;
		m_maxElements *= 2;
	}
	m_top++;
	m_pila[m_top] = valor;
}