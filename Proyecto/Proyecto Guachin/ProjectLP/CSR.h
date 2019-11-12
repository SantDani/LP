#pragma once
#include "Matriu.h"
#include <vector>
#include <cmath>
#include<fstream>
#include <iostream>
#include <ostream>
#include <string>
class MatriuSparse
{
public:
	MatriuSparse();
	~MatriuSparse();
	MatriuSparse(string nomFitxer);
	MatriuSparse(int nFiles, int nCol);
	MatriuSparse(const MatriuSparse& m);


	//Get - Set
	int getNFiles() const { return m_nFiles; }
	int getNColumnes() const { return m_nColumnes; }
	int getNElements() const { return m_nElements; }
	void inicializarMatriz(int nFiles, int nCol);
	void init(int nFiles, int nCol);
	
	
	bool getVal(int fila, int columna, float& valor);
	void setVal(int fila, int columna, int valor);
	


	//Funciones
	/*
		void liberarMemoria();

	void resize(int nFiles, int nColumnes);
	void transpose();
	*/




	//Sobrecargas
	MatriuSparse operator*(float num);
	MatriuSparse operator/(float num);
	vector<float> operator*(vector<float> vect);
	MatriuSparse& operator=(const MatriuSparse& m);
//	MatriuSparse operator+(const MatriuSparse& m);
	//MatriuSparse operator+(float s);
	//bool operator==(const MatriuSparse& m);
	friend ostream& operator<<(ostream& out, MatriuSparse& m);



private:
	void conseguirPos(const int &valorFil, const int &columna,  int &valorColumna,vector<int>::iterator  &posColumna,vector<float>::iterator  &posValor);
	void resize(int fila, int columna, int valor);
	int m_nFiles;
	int m_nColumnes;
	int m_nElements;
	vector<float> m_valor;
	vector<int> m_columnes;
	vector<int> m_indexFils;

};

