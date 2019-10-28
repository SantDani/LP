#pragma once
#include <string>
#include <iostream>
using namespace std;
/* Esta clase al tener una o mas funciones virtuales pura se convierte 
en una clase ABSTRACRA.
	1- NO se pueden crear objetos de Producto
	2- SI se pueden declarar apuntadores a objetos de las clases abstractas (manipular objetos de las clases derivadas)
		Producte *p = new Llibre;
		...
		p->mostra();
	3- Las clases abstratas perimiet definir una interface publica que todas las clases derivadas 
		han de tener i redefinir de forma especifica.*/
class Producte
{
public:
	Producte(): m_codi(""), m_preu(0) {}
	Producte(const string& codi, float preu) : m_codi(codi), m_preu(preu) {}
	Producte(const Producte& p) { m_codi = p.m_codi; m_preu = p.m_preu; }
	virtual ~Producte() { cout << "Destructor Producte" << endl; }

	void setCodi(const string& codi) { m_codi = codi; }
	void setPreu(float preu) { m_preu = preu; }
	string getCodi() { return m_codi; }
	float getPreu() { return m_preu; }
	//MODD pasa a ser funcion pura
	//virtual float calculaPreu(int nUnitats) { return m_preu * nUnitats; }
	//MODD pasa a ser funcion pura
	//float calculaDespesesEnviament();
	//MODD pasa a ser funcion pura
	//virtual void mostra();

	//Metodo Clone, este devuelve un apuntador a un nuevo objeto dinamico de la clase inicializada como una copia del objeto actual
		//virtual Producte* clone() { return new Producte(*this); } = 0;
	//Modificamos el clone anterior para que sea una funcion virutal pura
		//Estas solo las llaman las clases derivadas y por tanto ellas mimsas las definen.
	virtual Producte* clone()  = 0;
	virtual float calculaPreu(int nUnitat) = 0;
	virtual float calculaDespesesEnviament() = 0;
	virtual void mostra() = 0;


private:
	string m_codi;
protected:
	float m_preu;
};