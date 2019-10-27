#include "Racional.h"

ostream& operator<<(ostream& out, const Racional& r)
{
	out << r.m_numerador << "/" << r.m_denominador;
	return out;
}
