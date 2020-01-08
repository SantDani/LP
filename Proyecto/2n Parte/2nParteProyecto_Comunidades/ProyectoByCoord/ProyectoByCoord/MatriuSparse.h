#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <vector>
#include <ostream>
//includes 2n parte
#include <map>
#include "Tree.hpp"

using namespace std;

class MatriuSparse
{
public:
	//Constructores
	MatriuSparse();
	MatriuSparse(string nomFitxer);
	MatriuSparse(int nFiles, int nCol);
	MatriuSparse(const MatriuSparse& m);
	

	//Get - Set
	/*pare el getNColumnes() y getNFiles() se les suma uno porque en la matriuSparse se comienza a contar desde 0.
	Por lo tanto, si quieres saber las filas y columnas comenznado a contar desde 1 se le suma 1 a la fila y col.*/
	int getNFiles() const { return m_nFiles + 1; }
	int getNColumnes() const { return m_nColumnes + 1; }
	bool getVal(int fila, int columna,  float& valor) ;
	bool getBinario(float& valor, int fila, int col);
	bool getInteractivo(float& valor, int fila, int col);
	bool setVal(int fila, int columna, float valor);
	
	
	//Funciones
	void addElementoMatriz(std::vector<int>::iterator& itFila, int& fila, std::vector<int>::iterator& itCol, int& columna, std::vector<float>::iterator& itValor, float& valor);
	bool resize(int fila, int columna);
	bool filaColMayor(int fila, int columna);
	void init(int nFiles, int nColumnes);

	//Sobrecargas
	MatriuSparse& operator*(float num);
	vector<float> operator*(vector<float> vect);
	MatriuSparse& operator=(const MatriuSparse& m);
	MatriuSparse& operator/(float divisor);
	
	friend ostream& operator<<(ostream& out, const MatriuSparse& m);

	//--------------------------------------------------------START - 2n parte --------------------------------------------------------  
	void clear(); 

	/*Tendremos tantas aristas como valores aparezcan en nuestra matriz, esta es simetrica*/
	int getNValues() const { return m_vecValue.size(); } // devolvemos el numero de aristas (relacion entre dos nodos)
	void calculaGrau(vector<int>& graus) const;
	void creaMaps(vector<map<pair<int, int>, double>>& vMaps) const; 
	void calculaDendograms(vector<Tree<double>*> vDenograms) const;//funcion no implementada por lo tanto no esta declarada en .cpp
	
	int getValFila(int pos) { return m_vecFila[pos]; }//dada una posicion devuelve el valor de esta fila
	int getValCol(int pos) { return m_vecCol[pos]; }//dada una posicion devuelve el valor de esta col

	//--------------------------------------------------------END - 2n parte --------------------------------------------------------  

private:
	
	int m_nFiles;
	int m_nColumnes;

	vector<int> m_vecFila;
	vector<int> m_vecCol;
	vector<float> m_vecValue;

	int const DEFAULT_VEC_VALUE_0 = 0;
	int const DEFAULT_VEC_VALUE_1 = 1;

};