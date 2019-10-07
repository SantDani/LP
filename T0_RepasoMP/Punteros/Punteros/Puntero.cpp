#include "Puntero.h"


/* Punteros - Declaracion de Punteros

n& = La direccion de n
n* = La variable cuya direccion esta almacenada en n
*/

#include <iostream>
#include <conio.h>

using namespace std;
void Puntero::ex1ParImpar(int &num)
{
	int  * dir_numero;

	dir_numero = &num;//guardamos la posicion de memoria de la variable numero

	bool par = false;
	if (*dir_numero % 2 == 0)
	{
		par = true;
		cout << "El numero " << *dir_numero << " es par" << endl;
		cout << "La direccion de meomoria es " << dir_numero << endl <<endl;

	}
	else
	{

		cout << "El numero" << *dir_numero << " es impar" << endl;
		cout << "La direccion de meomoria es " << dir_numero << endl << endl;

	}
}


/*Ex3:
Rellenar un array de 10 num., 
posterorimente utilizando punteros indicar cuales son num. pares y su sposicion de mmemoria*/
void Puntero::ex3ParImparByArray()
{
	int const sizeVec = 10;
	int vecNum[sizeVec], *dir_numero;

	for (int i = 1; i < sizeVec + 1 ; i++)
	{
		vecNum[i-1] = i;
	}
	
	dir_numero = vecNum;


	for (int i = 0; i < sizeVec ; i++)
	{
	
		bool par = false;
		if (*dir_numero % 2 == 0)
		{
			par = true;
			cout << "El numero " << *dir_numero << " es par" << endl;
			cout << "La direccion de meomoria es " << dir_numero << endl << endl;

		}
		dir_numero++;
	}
	


	
}

//Funcion: PROTOTIPO
void PedirNotas();
void mostrarNotas();
//Funcion: DECLARACIOn
#include<stdlib.h> //libreria par new y delete-----------------------------------------------------------
//variables
int numCalificaciones, *dir_calificaciones;
void pedirNotas()
{
	cout << "Digite el numero de calificaciones: " ;
	cin >> numCalificaciones;

	//New reseva la memoria
	dir_calificaciones = new int[numCalificaciones];

	for (int i = 0; i < numCalificaciones; i++)
	{
		cout << "Ingrese nota del estudiande " << i << " : " << endl;
		//cin >> dir_calificaciones[i];
		dir_calificaciones[i] = numCalificaciones - i - 1;

	}
	 
}
void mostrarNotas()
{
	for (int i = 0; i < numCalificaciones; i++)
	{
		cout << " Nota estudiante " << i << " : " << *dir_calificaciones << endl;
		dir_calificaciones++;
		
		
	}
}



int main()
{
	pedirNotas();
	mostrarNotas();
	//getch();
	return 0;
}

