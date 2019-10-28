#include <iostream>
#include "Llibre.h"
#include "Electrodomestic.h"
#include "LlistaProductes.h"
#include <list>
#include "Main.h"
using namespace std;

int main()
{
	LlistaProductes llista;


	Llibre l1 ("CODI_1", 10, "TITOL_1", "AUTOR_1", 100);
	llista.afegeixLlibre(l1);
	Llibre l2 ("CODI_2", 20, "TITOL_2", "AUTOR_2", 200);
	llista.afegeixLlibre(l2);
	Llibre l3 ("CODI_3", 30, "TITOL_3", "AUTOR_3", 300);
	llista.afegeixLlibre(l3);

	Electrodomestic e1("CODI_4", 400, "MARCA_1", "MODEL_1", 50);
	llista.afegeixElectrodomestic(e1);
	Electrodomestic e2("CODI_5", 400, "MARCA_1", "MODEL_1", 50);
	llista.afegeixElectrodomestic(e2);
	Electrodomestic e3("CODI_6", 400, "MARCA_1", "MODEL_1", 50);
	llista.afegeixElectrodomestic(e3);

	llista.mostra();

	cout << "fin mostrar datos por defecto" << endl;

	//testSinClonarNiAsignacion(l1, llista, e1);

	testCopiaAsignacion(llista);



}

void testCopiaAsignacion(LlistaProductes& llista)
{
	LlistaProductes llistaCopia(llista);
	cout << "despues de utilizar constructor copia" << endl;
	llistaCopia.mostra();


	LlistaProductes llistaAssig;
	llistaAssig.afegeixLlibre(Llibre("CODI_5", 20, "TITOL_2", "AUTOR_2", 2000000));
	llistaAssig.afegeixLlibre(Llibre("CODI_11", 20, "TITOL_11", "AUTOR_11", 2000000));
	llistaAssig.afegeixLlibre(Llibre("CODI_12", 20, "TITOL_12", "AUTOR_12", 2000000));
	llistaAssig.afegeixLlibre(Llibre("CODI_13", 20, "TITOL_13", "AUTOR_13", 2000000));
	llistaAssig = llista;
	llistaAssig.mostra();
}

void testSinClonarNiAsignacion(Llibre& l1, LlistaProductes& llista, Electrodomestic& e1)
{
	cout << "Preu producte amb codi: " << l1.getCodi() << endl;
	cout << llista.getPreuProducte(l1.getCodi(), 20) << endl;
	cout << "Preu producte amb codi: " << e1.getCodi() << endl;;
	cout << llista.getPreuProducte(e1.getCodi(), 2) << endl;

	cout << "Eliminant Llibre" << endl;
	llista.eliminaProducte(l1.getCodi());
	cout << "Eliminant Electrodomestic" << endl;
	llista.eliminaProducte(e1.getCodi());

	llista.mostra();
}
