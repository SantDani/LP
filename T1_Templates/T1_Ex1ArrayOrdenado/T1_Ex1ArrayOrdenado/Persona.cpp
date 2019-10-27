#include "Persona.h"
#include <string>
#include<iostream>

using namespace std;
ostream& operator<<(ostream &out, const Persona& p)
{
	out << "(" << p.m_nom << ", " << p.m_edat << ")";
	return out;
}

bool Persona::operator>(const Persona& persona)
{
	bool mayor = false;

	if (m_edat == persona.m_edat) 
	{
		//cout << "string to char -------------------" << endl;
		//cout << stringToChar(m_nom) << " es mayor " << stringToChar(persona.m_nom) << endl;
		string m_nombre = m_nom;
		string personaNombre = persona.m_nom;
		bool res= (m_nom > persona.m_nom);
		if (res)
		{
			//cout << "Detectado que es mayor" << endl;
			//cout << "\t"<< *this << " es mayor " << persona.getNom() << endl;
			mayor = true;
		}
			
	}
	else if(m_edat > persona.m_edat)
		mayor = true;
	
	return mayor;
}

bool Persona::operator<(const Persona& persona)
{
	bool menor = false;

	if (m_edat == persona.m_edat)
	{
		//cout << "string to char -------------------" << endl;
		//cout << stringToChar(m_nom) << " es mayor " << stringToChar(persona.m_nom) << endl;

		if (m_nom < persona.m_nom)
		{
			//cout << "Detectado que es mayor" << endl;
			//cout << "\t"<< *this << " es mayor " << persona << endl;
			menor = true;
		}

	}
	else if (m_edat < persona.m_edat)
		menor = true;

	return menor;
}



bool Persona::operator==(const Persona& persona)
{
	return ((m_edat == persona.m_edat) && (m_nom == persona.m_nom));
}

Persona Persona::operator=(const Persona& persona)
{
	m_edat = persona.m_edat;
	m_nom = persona.m_nom;
	return *this;
}



