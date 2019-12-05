#include "MatriuSparse.h"
#include <math.h>
#include <iostream>

#include <vector>
#include "myMain.h"
using namespace std;

int main()
{
	//testEx6();
	

	//testConstructorAsignacion();
	string fichero = "Xarxa1.txt";

	MatriuSparse m(fichero);

	cout << m;

	//testMultiplicarByEscalar(m);

	testVector(m);

	//testGetSet(m);
	//testAddElementVector();

	return 0;
}

void testMultiplicarByEscalar(MatriuSparse& m)
{
	MatriuSparse mMultNum;


	mMultNum = m * 11;

	cout << mMultNum;
}

void testGetSet(MatriuSparse& m)
{
	m.setVal(7, 7, 6);
	m.setVal(0, 4, 7);
	m.setVal(0, 0, 1000);
	m.setVal(4, 4, 20000);
	m.setVal(10, 10, 445);
	m.setVal(10, 8, 2);
	m.setVal(10, 7, 1);
	m.setVal(10, 10, 3);

	cout << "\n\n luego de add en la pos 7 7 valor 6" << endl;
	cout << m;
	float valor = 0;
	bool trobat = m.getVal(10, 10, valor);
	cout << trobat << " valor " << valor << endl;

	trobat = m.getVal(11, 11, valor);
	cout << trobat << " valor " << valor << endl;
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
	MatriuSparse m;
	cout << "matriz vacia" << endl;
	cout << m;

	MatriuSparse m2(10, 10);
	cout << "matriz inicializada" << endl;
	cout << m2;
	m = m2;
	cout << " m = m2 " << endl;

	cout << m;
}

void testVector(MatriuSparse& m)
{
	vector<float> vecNum;
	vecNum.resize(10, 1);

	cout << "vector inicializado con 10 elementos y valor 1" << endl;
	mostrarVector(vecNum);

	

	/*for (int i = 0; i < vecNum.size(); i++)
	{
		vecNum[i] = i;
	}
	cout << "\nvector he add valores secuenciales" << endl;
	mostrarVector(vecNum);
	*/
	


	vector<float> vecAux;
	vecAux = m * vecNum;

	cout << "\ndespues de la multiplicacion" << endl;
	mostrarVector(vecAux);
}

void mostrarVector(std::vector<float>& vecNum)
{
	for (int i = 0; i < vecNum.size(); i++)
	{
		cout << vecNum[i] << "\t";
	}
}



