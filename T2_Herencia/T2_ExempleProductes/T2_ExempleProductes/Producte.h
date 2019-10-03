#pragma once
#include <string>
using namespace std;

class Producte
{
public:
	Producte() {//imprimir que tipo de constructor es}//inicializar los valores
	~Producte() {}

	Producte(string codi, float preu) { m_codi = codi, m_preu = preu; }
	void setCodi(const string& codi) { m_codi = codi; }
	void setPreu(float preu) { m_preu = preu; }

	string getCodi() { return m_codi; }
	float getPreu() { return m_preu; }
private:
	string m_codi;
	float m_preu;
};