#include "Matriu.h"
#include <math.h>
#include <iostream>
#include "main.h"
using namespace std;

int main()
{
	//testEx6();
	//testVector();
	
	//testConstructorAsignacion();
	string fichero = "Xarxa1.txt";
	Matriu m(fichero);
	vector<float> vecAux(3, 1);
	vector<float> res= m * vecAux;
	


	return 0;
}

void testConstructorAsignacion()
{
	Matriu m;
	cout << "matriz vacia" << endl;
	cout << m;

	Matriu m2(10, 10);
	cout << "matriz inicializada" << endl;
	cout << m2;
	m = m2;
	cout << " m = m2 " << endl;


	cout << m;
}

void testVector()
{
	vector<float> vecNum;
	vecNum.resize(10, 1);

	cout << "vector inicializado con 10 elementos y valor 1" << endl;
	mostrarVector(vecNum);

	vecNum.resize(10);

	for (int i = 0; i < vecNum.size(); i++)
	{
		vecNum[i] = i;
	}
	cout << "\nvector he add valores secuenciales" << endl;
	mostrarVector(vecNum);


	vector<float> vecAux;
	vecAux.resize(vecNum.size());

	for (int i = 0; i < vecNum.size(); i++)
	{
		vecAux[i] = vecNum[i];
	}
	cout << "\nMostrar vector Aux" << endl;
	mostrarVector(vecAux);
}

void mostrarVector(std::vector<float>& vecNum)
{
	for (int i = 0; i < vecNum.size(); i++)
	{
		cout << vecNum[i] << "\t";
	}
}



