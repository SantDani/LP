#include "Conjunt.h"
#include "Racional.h"
#include <iostream>
#include "main.h"
using namespace std;

int main()
{
	//testInt();
	testRacionales();
	return 0;
}

void testRacionales()
{
	Conjunt<Racional> cRacionals;
	Racional r;
	r.setDenominador(1);
	r.setDenominador(2);
	cRacionals.afegeix(r);
	cRacionals.mostra();
	if (cRacionals.existeix(r))
	//	cRacionals.elimina(r);
	cRacionals.mostra();
	for (int i = 0; i < 10; i++)
	{
		r.setNumerador(i);
		r.setDenominador(i + 1);

		cRacionals.afegeix(r);
	}
	cRacionals.mostra();


	cout << "eliminar elementos add by blucle" << endl;
	for (int i = 0; i < 10; i++)
	{
		r.setNumerador(i);
		r.setDenominador(i + 1);

		cRacionals.elimina(r);
	}
	cRacionals.mostra();
}

void testInt()
{
	Conjunt<int> c;


	for (int i = 0; i < 10; i++)
		c.afegeix(i);
	c.mostra();
	c.elimina(4);
	c.elimina(6);
	c.mostra();
}
