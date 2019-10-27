#include "Matriu.h"
#include <cmath>

Matriu::~Matriu()
{
	liberarMemoria();
}


Matriu::Matriu(int nFiles, int nColumnes)
{
	/*Este codigo luego se pondra en resize START ----------------- */
	
	inicializarMatriz(nFiles, nColumnes);
	/*Este codigo luego se pondra en resize END ----------------- */
}

Matriu::Matriu(const Matriu& matriu)
{
	//m_matriu = matriu.m_matriu;//Con esto apunto a la matriz que me envian como parametro
	//Guaramos memoria para filas y columnas
	inicializarMatriz(matriu.m_nFiles, matriu.m_nColumnes);
	//Copiamos el contenido de la matriz enviada a este objeto
	for (int i = 0; i < matriu.m_nFiles; i++)
	{
		for (int j = 0; j < matriu.m_nColumnes; j++)
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

void Matriu::setValor(int fila, int columna, float valor)
{
	if ((fila <= m_nFiles) && (columna <= m_nColumnes))
	{
		m_matriu[fila][columna] = valor;
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

bool Matriu::operator==(const Matriu& m)
{
	bool iguales = true;

	for (int i = 0; i < m_nFiles; i++)
	{
		for (int j = 0; j < m_nColumnes; j++)
		{
			int thisM = m_matriu[i][j];
			int laOtraM = m.m_matriu[i][j];
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
	bool resizeMayor = false;

	if ((nFilas > m_nFiles) || (nCol > m_nColumnes))
		resizeMayor = true;


	Matriu auxMatriu(*this);
	liberarMemoria();
	inicializarMatriz(nFilas, nCol);

	if (resizeMayor) {
		//Copiamos el contenido de la matriz enviada a este objeto
		for (int i = 0; i < auxMatriu.m_nFiles; i++)
		{
			for (int j = 0; j < auxMatriu.m_nColumnes; j++)
			{
				m_matriu[i][j] = auxMatriu.m_matriu[i][j];
			}
		}
	}
	else {
		//Copiamos el contenido de la matriz enviada a este objeto
		for (int i = 0; i < nFilas; i++)
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

