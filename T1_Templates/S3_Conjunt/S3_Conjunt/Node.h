#pragma once
#include "Racional.h"
class Node
{
public:
	Node() : m_valor(int()), m_next(NULL) {};
	~Node() { m_next = NULL; };
	Node(const int & valor) : m_valor(valor), m_next(NULL) {}
	Node* getNext() const { return m_next; }
	void setNext(Node* next) { m_next = next; }
	int getValor() const { return m_valor; }
	void setValor(const int& valor) { m_valor = valor; }
private:
	int m_valor;
	Node* m_next;
};

