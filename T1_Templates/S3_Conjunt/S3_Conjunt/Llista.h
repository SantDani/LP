#pragma once
#include "Node.h"
class Llista
{
public:
	Llista() { m_primer = NULL; }
	~Llista();
	bool esBuida() const { return m_primer == NULL; }
	Node* getInici() const { return m_primer; }
	Node* insereixNext(const int& valor, Node* posicio);
	Node* eliminaNext(Node* posicio);
private:
	Node* m_primer;
};
