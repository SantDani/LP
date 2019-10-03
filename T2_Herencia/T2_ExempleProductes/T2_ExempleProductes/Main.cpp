#include <iostream>
#include "Llibre.h"
#include "Electrodomestic.h"
using namespace std;

int main()
{
	Producte p;
	p.setCodi("CODI_1");
	p.setPreu(10);
	cout << "Dades Producte: " << endl;
	cout << "Codi: " << p.getCodi() << endl;
	cout << "Preu: " << p.getPreu() << endl;

	Llibre l;
	l.setCodi("CODI_2");
	l.setPreu(20);
	l.setTitol("TITOL_1");
	l.setAutor("AUTOR_1");
	l.setnPagines(100);
	cout << endl << "Dades Llibre: " << endl;
	cout << "Codi: " << l.getCodi() << endl;
	cout << "Preu: " << l.getPreu() << endl;
	cout << "Titol: " << l.getTitol() << endl;
	cout << "Autor: " << l.getAutor() << endl;
	cout << "N. Pagines: " << l.getNPagines() << endl;

	Electrodomestic e;
	e.setCodi("CODI_3");
	e.setPreu(300);
	e.setMarca("MARCA_1");
	e.setModel("MODEL_1");
	e.setVolum(50);
	cout << endl << "Dades Electrodomestic: " << endl;
	cout << "Codi: " << e.getCodi() << endl;
	cout << "Preu: " << e.getPreu() << endl;
	cout << "Marca: " << e.getMarca() << endl;
	cout << "Model: " << e.getModel() << endl;
	cout << "Volum: " << e.getVolum() << endl;


}