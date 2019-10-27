#include "Matriu.h"
#include <math.h>
#include <iostream>
#include "main.h"
#include <vector>
using namespace std;

int main()
{
	//testEx6();
	//testVector();
	
	//testConstructorAsignacion();
	string fichero = "Xarxa1.txt";

	Matriu m(fichero);
	 
	cout << m;

	m.setValor(7, 7, 6);
	cout << "\n\n luego de add en la pos 7 7 valor 6" << endl;
	cout << m;
	//testAddElementVector();

	
	
	

	return 0;
}

void testAddElementVector()
{
	// initialising the vector 
	vector<int> vec = { 10, 20, 30, 40 };
	int numero = 25;
	vector<int>::iterator it = vec.begin();
	int cont = 0;

	bool trobat = false;
	while (it != vec.end() && !trobat)
	{

		if (numero < (*it))
		{
			trobat = true;
		}
		if (!trobat)
		{
			cont++;
			it++;
		}

	}
	vec.insert(vec.begin() + cont, numero);
	for (auto it = vec.begin(); it != vec.end(); ++it)
		cout << *it << "\t";
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



