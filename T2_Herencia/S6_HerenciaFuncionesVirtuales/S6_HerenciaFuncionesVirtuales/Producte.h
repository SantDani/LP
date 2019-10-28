#pragma once
#include <string>
using namespace std;

class Producte
{
public:
	Producte(): m_codi(""), m_preu(0) {}
	Producte(const string& codi, float preu) : m_codi(codi), m_preu(preu) {}
	Producte(const Producte& p) { m_codi = p.m_codi; m_preu = p.m_preu; }
	~Producte() {}

	void setCodi(const string& codi) { m_codi = codi; }
	void setPreu(float preu) { m_preu = preu; }
	string getCodi() { return m_codi; }
	float getPreu() { return m_preu; }

	float calculaDespesesEnviament();
	virtual void mostra();
	virtual float calcularPreu(int nUnitats);
private:
	string m_codi;
protected:
	float m_preu;
};