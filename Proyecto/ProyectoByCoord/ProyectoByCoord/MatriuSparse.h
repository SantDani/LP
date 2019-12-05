#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <vector>
#include <ostream>

using namespace std;

class MatriuSparse
{
public:
	//Constructores
	MatriuSparse();
	MatriuSparse(string nomFitxer);
	MatriuSparse(int nFiles, int nCol);
	MatriuSparse(const MatriuSparse& m);
	//~MatriuSparse() ;

	//Get - Set
	int getNFiles() const { return m_nFiles; }
	int getNColumnes() const { return m_nColumnes; }
	bool getVal(int fila, int columna,  float& valor) ;
	bool setVal(int fila, int columna, float valor);
	void addElementoMatriz(std::vector<int>::iterator& itFila, int& fila, std::vector<int>::iterator& itCol, int& columna, std::vector<float>::iterator& itValor, float& valor);
	bool resize(int fila, int columna);
	bool filaColMayor(int fila, int columna);
	
	//Funciones
	void inicializarMatriz(int nFiles, int nCol);
	void init(int nFiles, int nColumnes);
	bool existe(int nFila, int nCol);

	//Sobrecargas
	MatriuSparse& operator*(float num);
	vector<float> operator*(vector<float> vect);
	MatriuSparse& operator=(const MatriuSparse& m);
	MatriuSparse& operator/(float divisor);
	bool operator==(const MatriuSparse& m);
	friend ostream& operator<<(ostream& out, MatriuSparse& m);

private:
	void ordenar();
	void swap(vector<float>& vec, int posActual);
	void swap(vector<int>& vec, int posActual);

	int m_nFiles;
	int m_nColumnes;


	vector<int> m_vecFila;
	vector<int> m_vecCol;
	vector<float> m_vecValue;

	int const DEFAULT_VEC_VALUE_0 = 0;
	int const DEFAULT_VEC_VALUE_1 = 1;
};