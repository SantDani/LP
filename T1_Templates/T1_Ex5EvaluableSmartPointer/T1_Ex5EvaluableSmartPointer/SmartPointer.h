#pragma once
#include <iostream>
using namespace std;

template <class T>
class SmartPointer
{
public:
	SmartPointer() { m_apuntador == nullptr; }
	SmartPointer(const SmartPointer& sp) { m_apuntador = sp; delete sp; }

	SmartPointer<T>& operator=(T* sp);
private:
	T * m_apuntador;
};

template<class T>
SmartPointer<T>& SmartPointer<T>::operator=(T* sp)
{
	if (m_apuntador == nullptr)
		delete m_apuntador;
	m_apuntador = sp;

	return *this;
}
