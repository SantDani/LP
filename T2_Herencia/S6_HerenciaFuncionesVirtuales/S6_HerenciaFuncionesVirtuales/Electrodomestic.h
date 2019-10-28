#pragma once
#pragma once
#include "Producte.h"
#include <string>
using namespace std;

class Electrodomestic : public Producte
{
public:
	Electrodomestic(): m_marca(""), m_model(""), m_volum(0.0) {}
	Electrodomestic(const string& codi, float preu, const string&marca, const string& model, float volum): Producte(codi, preu), m_marca(marca), m_model(model), m_volum(volum) {}
	Electrodomestic(const Electrodomestic& e) : Producte(e) { m_marca = e.m_marca; m_model = e.m_model; m_volum = e.m_volum; }
	~Electrodomestic() {}

	void setMarca(const string& marca) { m_marca = marca; }
	void setModel(const string& model) { m_model = model; }
	void setVolum(float volum) { m_volum = volum; }
	string getMarca() { return m_marca; }
	string getModel() { return m_model; }
	float getVolum() { return m_volum; }

	float calculaDespesesEnviament();
	float calculaPreu(int nUnitats);
	void mostra();
private:
	string m_marca;
	string m_model;
	float m_volum;
};
