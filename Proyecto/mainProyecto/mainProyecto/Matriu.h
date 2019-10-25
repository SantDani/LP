#pragma once
#include <vector>
#include <ostream>

using namespace std;

class Matriu
{
public:
	//Constructores
	Matriu();
	Matriu(string nomFitxer);
	Matriu(int nFiles, int nCol);
	Matriu(const Matriu& m);
	~Matriu();

	//Get - Set
	int getNFiles() const { return m_nFiles; }
	int getNColumnes() const { return m_nColumnes; }
	bool getValor(int fila, int columna, int& valor);
	void setValor(int fila, int columna, float valor);

	//Funciones
	void liberarMemoria();
	void inicializarMatriz(int nFiles, int nCol);
	void resize(int nFiles, int nColumnes);
	void transpose();
	void init(int nFiles, int nCol);
	
	
	//Sobrecargas
	Matriu& operator*(float num);
	vector<float>& operator*(vector<float> vect);
	Matriu& operator=(const Matriu& m);
	Matriu operator+(const Matriu& m);
	Matriu operator+(float s);
	bool operator==(const Matriu& m);
	friend ostream& operator<<(ostream& out, Matriu& m);

private:
	void ordenar();
	void swap(vector<float> &vec, int posActual);
	
	int m_nFiles;
	int m_nColumnes;
	

	vector<float> m_vecFilaX;
	vector<float> m_vecColY;
	vector<float> m_vecValue;

	int const DEFAULT_VALUE = 1;
};