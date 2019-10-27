#pragma once
#include "Punt.h"


class Node
{
public:
	Node(const Punt& pt) { m_valor = pt; }
	void setValor(const Punt& pt) { m_valor = pt; };
	void setNext(Node* next) { m_next = next; }
	Punt getValor() const { return m_valor; }
	Node* getNext() const { return m_next; }
private:
	Punt m_valor;
	Node* m_next;
};
