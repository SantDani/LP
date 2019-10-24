#pragma once
#include <string>

using namespace std;
/*
1 - Nuevo constructor dado un fichero de entrada, Parametros> fichero y la medida de la matriz en filas y columnas
	1.1 Se creara la matriz con todos los valores a 0
	1.2 Add los valores del fichero (poner los valores que aparecen a 1 )*/
class Matriu
{
public:
	//Constructores
	Matriu() : m_matriu(nullptr), m_nFiles(0), m_nColumnes(0) {}
	Matriu(int nFiles, int nCol);
	Matriu(const Matriu& m);
	~Matriu();
	Matriu(string nomFitxer, int nFilas, int nCol);
	Matriu(string nomFitxer);

	void crearMatrizDinamica(std::string& nomFitxer, int nFilas, int nCol);

	//funciones
	void liberarMemoria();
	void inicializarMatriz(int nFiles, int nCol);
	void init(int nFiles, int nCol);
	void resize(int nFiles, int nColumnes);
	void transpose();
	Matriu& operator=(const Matriu& m);
	void initValor(float valor);
	void setValor(int fila, int columna);
	void setValorMatrizDinamica(int fila, int columna, float valor);
	Matriu operator+(const Matriu& m);
	Matriu operator+(float s);
	Matriu operator*(int num);
	Matriu operator/(int num);
	bool operator==(const Matriu& m);
	friend ostream& operator<<(ostream & out, const Matriu& m);

	bool esBuida() const { return (m_matriu == nullptr); }
	int getNFiles() const { return m_nFiles; }
	int getNColumnes() const { return m_nColumnes; }
	float getValor(int fila, int columna) const;
	bool getValor(int fila, int columna, float& valor);

	

private:
	float** m_matriu;
	int m_nFiles;
	int m_nColumnes;

	int const MAX_COL = 2;
	int m_nRegistros;

};