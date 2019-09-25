#pragma once

class PilaInt 
{
public:

	PilaInt();
	~PilaInt();
	
	void push(const int& valor);
	void pop() { m_top--; };
	int top() const { return m_pila[m_top]; }
	bool esBuida() const { return (m_top == -1); }
private:

	int* m_pila;
	int m_top;
	int m_maxElements;
	static const int MAX_ELEMENTS = 5;
};