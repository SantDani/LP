#pragma once
#include <cstddef>

using namespace std;
class Nodo
{
public:
	Nodo() : m_valor(int()), m_next(NULL) {};
	~Nodo() { m_next = NULL; };
	Nodo(const int& valor) : m_valor(valor), m_next(NULL) {}
	Nodo* getNext() const { return m_next; }
	void setNext(Nodo* next) { m_next = next; }
	int getValor() const { return m_valor; }
	void setValor(const int& valor) { m_valor = valor; }
private:
	int m_valor;
	Nodo* m_next;
};

