/**/

#include<iostream>
#include<conio.h>
#include<stdlib.h>// new y delete
using namespace std;

void pedirDatos(int **&puntero,int &, int&);
void mostrarMatriz(int ** puntero, int nFilas, int nCol);
void liberarMemoria(int** puntero, int nFilas, int nCol);
void sumar(int** puntero, int** puntero2, int nFilas, int nCol);



int main()
{
	int** puntero_matriz = NULL, ** puntero_matriz2 = NULL;//apunta a una matriz

	int nFilas, nCol;
	pedirDatos(puntero_matriz,nFilas, nCol);
	pedirDatos(puntero_matriz2, nFilas, nCol);
	sumar(puntero_matriz, puntero_matriz2, nFilas, nCol);
	mostrarMatriz(puntero_matriz, nFilas, nCol);


	system("pause");
	liberarMemoria(puntero_matriz, nFilas, nCol);
	liberarMemoria(puntero_matriz2, nFilas, nCol);
	
	
	
	return 0;
}

void pedirDatos(int **&puntero, int &nFilas, int &nCol)
{
	

	cout << "Ponga el numero de Filas: ";
	cin >> nFilas;
	cout << "Ponga el numero de Columnas: ";
	cin >> nCol;

	puntero = new int *[nFilas]; //Reservando memoria para las filas

	for (int i = 0; i < nFilas; i++)
	{
		puntero[i] = new int[nCol]; //Reservando memoria para las columnas
	}

	cout << "Introducir elementos de la matriz:	" << endl;

	int cont = 1;
	for (int i = 0; i < nFilas; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			cout << "Escriba el numero[" << i << "][" << j << "]: ";
			//cin >> *(*(puntero_matriz + i) + j);// puntero matriz[i][j]
			//*(*(puntero_matriz + i) + j) = i + j;

			puntero[i][j] = cont++;
		}
	}
}

void mostrarMatriz(int** puntero, int nFilas, int nCol)
{
	cout << "\n\n Imprimiendo matriz: \n";

	for (int i = 0; i < nFilas; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			//cout << *(*(puntero_matriz + i) + j);
			cout << puntero[i][j] << "\t";
		}
		cout << endl;
	}
}

void liberarMemoria(int** puntero, int nFilas, int nCol)
{
	//Eliminar todo, filas y col
	for (int i = 0; i < nFilas; i++)
		delete[] puntero[i]; //eliminar numero de columnas
	delete[] puntero;// eliminar numero de filas
}

void sumar(int** puntero, int** puntero2, int nFilas, int nCol)
{
	for (int i = 0; i < nFilas; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			//cout << *(*(puntero_matriz + i) + j);
			puntero[i][j] = puntero[i][j] + puntero2[i][j];
		}
		
	}
}