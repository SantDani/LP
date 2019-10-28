#include <iostream>
#include "Llibre.h"
#include "Electrodomestic.h"
#include <list>
#include "Main.h"
using namespace std;

int main()
{
	//muestraSinVirtual();

	Producte p;
	p.setCodi("CODI_1");
	p.setPreu(10);

	Llibre l;
	l.setCodi("CODI_2");
	l.setPreu(20);
	l.setTitol("TITOL_1");
	l.setAutor("AUTOR_1");
	l.setnPagines(100);

	Electrodomestic e;
	e.setCodi("CODI_3");
	e.setPreu(300);
	e.setMarca("MARCA_1");
	e.setModel("MODEL_1");
	e.setVolum(50);
	
	list<Producte*> llistaProductes;
	llistaProductes.push_back(&p);
	llistaProductes.push_back(&l);
	llistaProductes.push_back(&e);
	list<Producte*>::iterator it;
	for (it = llistaProductes.begin(); it != llistaProductes.end(); it++)
	{
		(*it)->mostra();
		cout << endl;
	}


/*	LlistaProductes llista;


	Llibre l1("CODI_1", 10, "TITOL_1", "AUTOR_1", 100);
	llista.afegeixLlibre(l1);
	Llibre l2("CODI_2", 20, "TITOL_2", "AUTOR_2", 200);
	llista.afegeixLlibre(l2);
	Llibre l3("CODI_3", 30, "TITOL_3", "AUTOR_3", 300);
	llista.afegeixLlibre(l3);

	Electrodomestic e1("CODI_4", 400, "MARCA_1", "MODEL_1", 50);
	llista.afegeixElectrodomestic(e1);
	Electrodomestic e2("CODI_5", 400, "MARCA_1", "MODEL_1", 50);
	llista.afegeixElectrodomestic(e2);
	Electrodomestic e3("CODI_6", 400, "MARCA_1", "MODEL_1", 50);
	llista.afegeixElectrodomestic(e3);

	llista.mostra();

	cout << "Preu producte amb codi: " << l1.getCodi() << endl;
	cout << llista.getPreuProducte(l1.getCodi(), 20) << endl;
	cout << "Preu producte amb codi: " << e1.getCodi() << endl;;
	cout << llista.getPreuProducte(e1.getCodi(), 2) << endl;

	cout << "Eliminant Llibre" << endl;
	llista.eliminaProducte(l1.getCodi());
	cout << "Eliminant Electrodomestic" << endl;
	llista.eliminaProducte(e1.getCodi());

	llista.mostra();
*/

	return 0;
}

void muestraSinVirtual()
{
	Producte p;
	p.setCodi("CODI_1");
	p.setPreu(10);

	Llibre l;
	l.setCodi("CODI_2");
	l.setPreu(20);
	l.setTitol("TITOL_1");
	l.setAutor("AUTOR_1");
	l.setnPagines(100);

	Electrodomestic e;
	e.setCodi("CODI_3");
	e.setPreu(300);
	e.setMarca("MARCA_1");
	e.setModel("MODEL_1");
	e.setVolum(50);

	list<Producte> llistaProductes;
	llistaProductes.push_back(p);
	llistaProductes.push_back(l);
	llistaProductes.push_back(e);
	list<Producte>::iterator it;
	for (it = llistaProductes.begin(); it != llistaProductes.end(); it++)
	{
		it->mostra();
		cout << endl;
	}
}
