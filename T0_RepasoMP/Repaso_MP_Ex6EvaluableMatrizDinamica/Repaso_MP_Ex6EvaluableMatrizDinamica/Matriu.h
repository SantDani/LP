#pragma once


class Matriu
{
public:
	//Constructores
	Matriu() : m_matriu(nullptr), m_nFiles(0), m_nColumnes(0) {}
	//Matriu(int nFiles, int nColumnes) : m_matriu(nullptr), m_nFiles(0), m_nColumnes(0) {resize(nFiles, nColumnes);}
	Matriu(int nFiles, int nCol);
	Matriu(const Matriu& m);
	~Matriu();

	void liberarMemoria();
	void inicializarMatriz(int nFiles, int nCol);

	void resize(int nFiles, int nColumnes);
	void transpose();
	Matriu& operator=(const Matriu& m);
	void initValor(float valor);
	void setValor(int fila, int columna, float valor);
	Matriu operator+(const Matriu& m);
	Matriu operator+(float s);
	bool operator==(const Matriu& m);

	bool esBuida() const { return (m_matriu == nullptr); }
	int getNFiles() const { return m_nFiles; }
	int getNColumnes() const { return m_nColumnes; }
	float getValor(int fila, int columna) const;
private:
	float** m_matriu;
	int m_nFiles;
	int m_nColumnes;

};