#include "Matriu.h"
#include <string>
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

Matriu::~Matriu()
{
	liberarMemoria();
}

Matriu::Matriu(string nomFitxer, int nFilas, int nCol)
{
	
	//crearMatrizDinamica(nomFitxer, nFilas, nCol);
	//Lo que queremos es una matriz Dispersa
	ifstream fitxer;
	fitxer.open(nomFitxer);
	m_nRegistros = 0;

	if (fitxer.is_open())
	{
		inicializarMatriz(0, 0);
		int posFila, posCol;//fila y, col x
		while (!fitxer.eof())//mientras no sea el final del fichero
		{
			fitxer >> posFila >> posCol;

			setValor(posFila, posCol);
			cout << "fila " << posFila << " col " << posCol << " valor add" << endl;
			
		}
	}
	else
	{
		cout << "Error al abrir el fichero" << endl;
	}
}

Matriu::Matriu(string nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);
	m_nRegistros = 0;

	if (fitxer.is_open())
	{
		inicializarMatriz(0, 0);
		int posFila, posCol;//fila y, col x
		while (!fitxer.eof())//mientras no sea el final del fichero
		{
			fitxer >> posFila >> posCol;

			setValor(posFila, posCol);
			cout << "fila " << posFila << " col " << posCol << " valor add" << endl;

		}
	}
	else
	{
		cout << "Error al abrir el fichero" << endl;
	}
}



Matriu::Matriu(int nFiles, int nColumnes)
{
	inicializarMatriz(nFiles, nColumnes);
}

Matriu::Matriu(const Matriu& matriu)
{
	//m_matriu = matriu.m_matriu;// NOPE pues Con esto apunto a la matriz que me envian como parametro
	//Guaramos memoria para filas y columnas
	//inicializarMatriz(matriu.m_nRegistros , 2);
	init(matriu.m_nRegistros, 2);
	//Copiamos el contenido de la matriz enviada a este objeto
	for (int i = 0; i < matriu.m_nRegistros ; i++)
	{
		for (int j = 0; j < MAX_COL - 1; j++)
		{
			m_matriu[i][j] = matriu.m_matriu[i][j];
		}
	}
	
}


Matriu& Matriu::operator=(const Matriu& matriu)
{
	//m_matriu = matriu.m_matriu;

	liberarMemoria();//Perdemos el acontenido anterior y liberamos memoria dinamica reservada
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

void Matriu::setValor(int nFila, int nCol)
{
	//setValorMatrizDinamica(fila, columna, valor);
	//Ceremos cerar la matriz dispersa
	
	if (nFila > m_nFiles)
		m_nFiles = nFila;
	if(nCol > m_nColumnes)
		m_nColumnes = nCol;

	//add registro y ordenar
	m_nRegistros++;
	this->resize(m_nRegistros, 2);
	m_matriu[m_nRegistros-1][0] = nFila;
	m_matriu[m_nRegistros-1][1] = nCol;
	

	for (int i = 0; i < m_nRegistros; i++)
	{
			cout << "num reg " <<m_nRegistros  << " ->" <<m_matriu[i][0] << "\t" <<m_matriu[i][1] << endl;
	}
	

	

}



Matriu Matriu::operator+(const Matriu& m)
{
	bool iguals = false;
	if ((m.m_nFiles == m_nFiles) && (m.m_nColumnes == m_nColumnes))
	{
		iguals = true;
		for (int i = 0; i < m_nFiles; i++)
		{
			for (int j = 0; j < m_nColumnes; j++)
				m_matriu[i][j] += m.m_matriu[i][j];
		}
	}


	if (iguals)
	{
		return *this;
	}
	else
	{
		return Matriu();
	}

}

Matriu Matriu::operator+(float s)
{

	for (int i = 0; i < m_nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
			m_matriu[i][j] += s;
	}
	return *this;
}

Matriu Matriu::operator*(int num)
{
	for (int i = 0; i < m_nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
			m_matriu[i][j] = m_matriu[i][j] * num;
	}
	return *this;
}

Matriu Matriu::operator/(int num)
{
	for (int i = 0; i < m_nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
			m_matriu[i][j] = m_matriu[i][j] / num;
	}
	return *this;
}

bool Matriu::operator==(const Matriu& m)
{
	bool iguales = true;

	for (int i = 0; i < m_nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
		{
			float thisM = m_matriu[i][j];
			float laOtraM = m.m_matriu[i][j];
			if ((m_matriu[i][j] != m.m_matriu[i][j]))
			{
				iguales = false;
				i = m_nFiles;
				j = m_nColumnes;
			}

		}

	}

	return iguales;
}

float Matriu::getValor(int fila, int columna) const
{
	float valor = std::nanf("");
	if ((fila <= m_nFiles) && (columna <= m_nColumnes))
	{
		valor = m_matriu[fila][columna];
	}
	return valor;
}

bool Matriu::getValor(int fila, int columna, float& valor)
{
	//Volveremos para adaptarla a matriz Dispersa
	bool trobat = false;
	valor = 0;
	
	if ((fila <= m_nFiles) && (columna <= m_nColumnes))
	{
		valor = m_matriu[fila][columna];
		trobat = true;
	}
	return trobat;
}




void Matriu::liberarMemoria()
{
	////eliminar columnas
	//for (int i = 0; i < 2; i++)
	//	delete[] m_matriu[i];
	////eliminar filas
	//delete[] m_matriu;
}

void Matriu::inicializarMatriz(int nFiles, int nCol)
{
	
	m_matriu = new float* [nFiles];//Guardo memoria para las filas
	for (int i = 0; i < nFiles; i++)
	{
		m_matriu[i] = new float[nCol];//Guardando memoria para las columnas
	}

	//Inicializamos la matriz con todos los valores a 0
	for (int i = 0; i < nFiles; i++)
	{
		for (int j = 0; j < nCol; j++)
		{
			m_matriu[i][j] = 0;
		}
	}
}

void Matriu::init(int nFiles, int nCol)
{
	inicializarMatriz(nFiles, nCol);
}

void Matriu::resize(int nFilas, int nCol)
{

	Matriu auxMatriu(*this);
	liberarMemoria();
	inicializarMatriz(nFilas, nCol);
	{
		//Copiamos el contenido de la matriz actual
		for (int i = 0; i < m_nRegistros; i++)
		{
			for (int j = 0; j < nCol; j++)
			{
				m_matriu[i][j] = auxMatriu.m_matriu[i][j];
				
			}
		}
	}

	//auxMatriu.liberarMemoria();
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
	//auxMatriu.liberarMemoria();

}

ostream& operator<<(ostream& output, const Matriu& m)
{
	cout << "MATRIU DE (FILES:" << m.m_nFiles << " COLUMNES: " << m.m_nColumnes << ")" <<endl;
	cout << "VALORS(FILA::COL::VALOR)" << endl;
	for (int i = 0; i < m.getNFiles(); i++)
	{
		cout << "Comment :=>> [";
		for (int j = 0; j < m.getNColumnes(); j++)
			cout << m.getValor(i, j) << " ";
		output << "]" << endl;
	}
	
	return output;
}
