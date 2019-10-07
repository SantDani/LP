#include "Matriu.h"
#include <cmath>

Matriu::~Matriu()
{
	liberarMemoria();
	
}


Matriu::Matriu(int nFiles, int nColumnes)
{
	/*Este codigo luego se pondra en resize START ----------------- */
	
	m_nFiles = nFiles;
	m_nColumnes = nColumnes;
	inicializarMatriz(m_nFiles, m_nColumnes);
	/*Este codigo luego se pondra en resize END ----------------- */
}

Matriu::Matriu(const Matriu& matriu)
{
	//m_matriu = matriu.m_matriu;//Con esto apunto a la matriz que me envian como parametro
	//Guaramos memoria para filas y columnas
	inicializarMatriz( m_nFiles, m_nColumnes);
	//Copiamos el contenido de la matriz enviada a este objeto
	for (int i = 0; i < m_nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
		{
			m_matriu[i][j] = matriu.m_matriu[i][j];
		}
	}
}


Matriu& Matriu::operator=(const Matriu& matriu)
{
	//m_matriu = matriu.m_matriu;
	
	liberarMemoria();//Peremos el acontenido anterior y liberamos memoria dinamica reservada
	inicializarMatriz(matriu.m_nFiles, matriu.m_nColumnes);
	//Copiamos el contenido de la matriz enviada a este objeto
	for (int i = 0; i < m_nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
		{
			m_matriu[i][j] = matriu.m_matriu[i][j];
		}
	}

	return *this;
}



void Matriu::liberarMemoria()
{
	//eliminar columnas
	for (int i = 0; i < m_nFiles; i++)
		delete[] m_matriu[i];
	//eliminar filas
	delete[] m_matriu;
}

void Matriu::inicializarMatriz(int nFiles, int nCol)
{
	m_nFiles = nFiles;
	m_nColumnes = nCol;
	m_matriu = new float* [m_nFiles];//Guardo memoria para las filas
	for (int i = 0; i < m_nFiles; i++)
	{
		m_matriu[i] = new float[m_nColumnes];//Guardando memoria para las columnas
	}

	//Inicializamos la matriz con todos los valores a 0
	for (int i = 0; i < m_nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
		{
			m_matriu[i][j] = 0;
		}
	}
}

void Matriu::resize(int nFilas, int nCol)
{
	Matriu auxMatriu(*this);
	liberarMemoria();
	inicializarMatriz(nFilas, nCol);

	//Copiamos el contenido de la matriz enviada a este objeto
	for (int i = 0; i < auxMatriu.m_nFiles; i++)
	{
		for (int j = 0; j < auxMatriu.m_nColumnes; j++)
		{
			m_matriu[i][j] = auxMatriu.m_matriu[i][j];
		}
	}
	auxMatriu.liberarMemoria();
}

void Matriu::transpose()
{
	Matriu auxMatriu(*this);
	liberarMemoria();
	
	inicializarMatriz(m_nColumnes, m_nFiles);

	//Copiamos el contenido de la matriz enviada a este objeto
	for (int i = 0; i < auxMatriu.m_nFiles; i++)
	{
		for (int j = 0; j < auxMatriu.m_nColumnes; j++)
		{
			m_matriu[j][i] = auxMatriu.m_matriu[i][j];
		}
	}
	auxMatriu.liberarMemoria();

}

