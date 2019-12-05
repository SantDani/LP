#include "Tree.hpp"
#include<iostream>
#include <string>

int main()
{
	cout << "=======================" << endl;
	cout << "IMPRIMINT ARBRE ORDENAT" << endl;
	cout << "=======================" << endl;
	Tree<int> tOrd("arbreOrdenat.txt");
	cout <<tOrd;
	
	
	//Valor existeix 
	cout << "Cercant valor existent: 92" << endl;
	Tree<int>* tsol1=nullptr;
	if (tOrd.cerca(92,tsol1))
	{
		cout << "OK Valor 92 trobat" << endl;
	}
	else
	{
		cout << "ERROR Valor 92 NO trobat" << endl;
	}


	//Valor NO existeix 
	cout << "Cercant valor NO existent: 106" << endl;
	Tree<int>* tsol2=nullptr;
	if (!tOrd.cerca(106, tsol2))
	{
		cout << "OK Valor 106 NO trobat" << endl;
	}
	else
	{
		cout << "ERROR Valor 106 trobat??" << endl;
	}
	

	cout << "==========================" << endl;
	cout << "IMPRIMINT ARBRE OPERACIONS" << endl;
	cout << "==========================" << endl;

	Tree<string> tOp("arbreOps.txt");
	//cout << tOp;
	
	cout << "MOSTRA EXPRESSIO" << endl;
	tOp.mostraExpressio();

	cout << "AVALUANT EXPRESSIO" << endl;
	cout << tOp.avalua();

	
	cout << endl;

	return 0;
}