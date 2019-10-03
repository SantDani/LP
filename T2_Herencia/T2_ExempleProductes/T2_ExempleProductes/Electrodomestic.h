#pragma once
#pragma once
#include "Producte.h"
#include <string>
using namespace std;

class Electrodomestic: public Producte
{
public:
	//Consructores
	Electrodomestic() : m_marca("") , m_model(""), m_volumM3(0){};
	~Electrodomestic();
	Electrodomestic(string codi, float preu, string marca, string model, float volum) : Producte(codi, preu), m_marca(marca) , m_model(model), m_volumM3(volum){};
	Electrodomestic(const Electrodomestic& e): Producte(e) {  };

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
