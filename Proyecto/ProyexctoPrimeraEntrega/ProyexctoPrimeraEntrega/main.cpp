#include "Matriu.h"
#include <math.h>
#include <iostream>

using namespace std;

const int MAX_ELEMENTS = 4;

void mostraBool(bool logic)
{
	if (logic)
		cout << "TRUE";
	else
		cout << "FALSE";
}

void escriuValors(float valors[][MAX_ELEMENTS], int nFiles, int nColumnes)
{
	cout << endl << "Comment :=>> [" << endl;
	for (int i = 0; i < nFiles; i++)
	{
		cout << "Comment :=>> [";
		for (int j = 0; j < nColumnes; j++)
			cout << valors[i][j] << " ";
		cout << "]" << endl;
	}
	cout << "Comment :=>> ]" << endl;
}

void escriuValorsMatriu(const Matriu& m)
{
	cout << endl << "Comment :=>> [" << endl;
	for (int i = 0; i < m.getNFiles(); i++)
	{
		cout << "Comment :=>> [";
		for (int j = 0; j < m.getNColumnes(); j++)
			cout << m.getValor(i, j) << " ";
		cout << "]" << endl;
	}
	cout << "Comment :=>> ]" << endl;
}





int main()
{
	// find
	string nomFitxer = "Xarxa1.txt";
	Matriu m(nomFitxer);
	//escriuValorsMatriu(m);
	//m.setValor(1, 1);
	cout << m;
	
	//float valor;
	//if (m.getValor(9, 9, valor))
	//{
	//	cout << "valor: " << valor << endl;
	//}
	//else 
	//{
	//	cout << "valor no esta en la matriz";
	//	//m.setValor(20, 30);
	//}
	//evaluacionEx();
	//escriuValorsMatriu(m);
	//cout << m << endl << endl;
	//cout << m.getNColumnes();

	return 0;
}


