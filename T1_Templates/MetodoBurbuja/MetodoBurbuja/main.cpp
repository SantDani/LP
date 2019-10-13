#include<iostream>
#include <stdlib.h>
#include <time.h>
#include "cerca_ordenacio.h"
#include "main.h"

using namespace std;

const char* stringToChar(string nom);
int main()
{
	int const cant = 5;
	/*Numero actual es mayor que el siguiente*/

	int numeros[] = { 4,1,2,3,5 };
	cout << "Desordenados" << endl;
	mostrar(numeros, cant);
	ordena(numeros, cant);
	cout << "despues de ordenar" << endl;
	
	mostrar(numeros, cant);


	string nomPersona[cant] = { "NOM_D",  "NOM_E", "NOM_B", "NOM_C",  "NOM_A" };
	
	cout << "Desordenados" << endl;
	mostrar(nomPersona, cant);
	ordena(nomPersona, cant);
	cout << "despues de ordenar" << endl;

	mostrar(nomPersona, cant);

	string nomPersona2[cant] = { "J",  "i", "h", "g",  "f" };

	cout << "Desordenados" << endl;
	mostrar(nomPersona2, cant);
	ordena(nomPersona2, cant);
	cout << "despues de ordenar" << endl;

	mostrar(nomPersona2, cant);



	

	



	string palabra1 = "NOM_D";
	string palabra2 = "NOM_E";
	bool res = (palabra1 < palabra2);
	if (res)
		cout << "Primera palabra mayor " << (palabra1) <<  endl;
	else
		cout << "Segunda palabra mayor " << (palabra2) << endl;
	return 0;
}

const char* stringToChar(string nom)
{

	

	std::string str = nom;

	char* c = const_cast<char*>(str.c_str());
	//std::cout << c;

	
	return c;
}

void ordenarBurbuja(int& i, const int& cant, int& j, int  numeros[5], int& aux)
{
	for (i = 0; i < cant; i++)
	{
		for (j = 0; j < cant - 1; j++)
		{
			if (numeros[j] > numeros[j + 1])
			{
				aux = numeros[j];
				numeros[j] = numeros[j + 1];
				numeros[j + 1] = aux;
			}
		}
	}
}
