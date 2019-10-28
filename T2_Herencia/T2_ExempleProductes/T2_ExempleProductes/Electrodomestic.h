#pragma once
#pragma once
#include "Producte.h"
#include <string>
using namespace std;

class Electrodomestic: public Producte
{
public:
	//Consructores
	//Constructor por defecto
	Electrodomestic() : m_marca(""), m_model(""), m_volumM3(0.0) {};
	//Constructor con valores
	Electrodomestic(string codi, float preu, string marca, string model, float volum)
		: Producte(codi, preu) {m_marca = marca; m_model = model; m_volumM3 = volum;};
	//Constructor copia
	Electrodomestic(const Electrodomestic& e)
		: Producte(e){m_marca = e.m_marca; m_model = e.m_model; m_volumM3 = e.m_volumM3;};
	//destructor
	~Electrodomestic();

	//Get
	string getMarca() const { return m_marca; }
	string getModel() const { return m_model; }
	float getVolum() const { return m_volumM3; }
	//Set
	void setMarca(string marca) { m_marca = marca; }
	void setModel(string model) { m_model = model; }
	void setVolum(float volum) { m_volumM3 = volum; }

	
private:
	string m_marca;
	string m_model;
	float m_volumM3;
};
