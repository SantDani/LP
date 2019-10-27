#pragma once

#include "Racional.h"

class ConjuntRacionals
{
public:

	ConjuntRacionals() { m_nElements;  };
	ConjuntRacionals(int m_nElements);
	~ConjuntRacionals();
	ConjuntRacionals& operator=(ConjuntRacionals& c);
	void afegeix(const Racional& r);
private:
	int m_maxElements;
	Racional* m_conjunt;
	int m_nElements;

};
