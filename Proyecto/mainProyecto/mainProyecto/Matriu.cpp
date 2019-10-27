#include "Matriu.h"
#include <cmath>
#include<fstream>
#include <iostream>

using namespace std;
//Constructores
Matriu::~Matriu()
{
	liberarMemoria();
}


Matriu::Matriu()
{
	m_vecFilaX.resize(0);
	m_vecColY.resize(0);
	m_vecValue.resize(0);

	m_nColumnes = 0;
	m_nFiles = 0;
}

Matriu::Matriu(string nomFitxer)
{
	ifstream miFichero; //Declaro el objeto ifstream para poder leer el fichero
	miFichero.open(nomFitxer);

	if (miFichero.is_open())
	{
		int fila, col, valor, i;
		i = 0;
		inicializarMatriz(0, 0);
		while (!miFichero.eof()) // mientras no sea el final del fichero
		{
			
			miFichero >> fila >> col;

			if (m_nFiles < fila)
				m_nFiles = fila;
			if (m_nColumnes < col)
				m_nColumnes = col;

			m_vecFilaX.emplace_back(fila);
			m_vecColY.emplace_back(col);
			m_vecValue.emplace_back(DEFAULT_VALUE);
			i++;
		}
		miFichero.close();
	}
	else
		cout << "Error al leer el fichero" << endl;
	this->ordenar();
}

Matriu::Matriu(int nFiles, int nColumnes)
{
	
	inicializarMatriz(nFiles, nColumnes);
}

Matriu::Matriu(const Matriu& matriu)
{
	checkFilaColumna(matriu.m_nFiles, matriu.m_nColumnes);

	//Copiamos el contenido de la matriz enviada a este objeto
	m_vecFilaX = matriu.m_vecFilaX;
	m_vecColY = matriu.m_vecColY;
	m_vecValue = matriu.m_vecValue;	
}


Matriu& Matriu::operator*(float num)
{
	int posFila = 0;
	Matriu mAux(*this);
	while (posFila < m_vecFilaX.size())
	{
		mAux.m_vecValue[posFila] = m_vecValue[posFila] * num;
		posFila++;
	}

	return  mAux;
}

Matriu Matriu::operator/(float num)
{
	Matriu mAux(*this);
	
	int posFila = 0;
	while (posFila < m_vecFilaX.size())
	{
		mAux.m_vecValue[posFila] = m_vecValue[posFila] * num;
		posFila++;
	}

	return  mAux;
}

vector<float> Matriu::operator*(vector<float> vect)
{
	int numFila = 0;
	int posFila = 0;
	int sizeVect = vect.size();
	vector<float> vecAux(sizeVect, 0);

	while (posFila < m_vecFilaX.size())
	{
		if (m_vecFilaX[posFila] == numFila)
		{
			int posCol = m_vecColY[posFila];
			vecAux[posCol] += m_vecValue[posCol] * vect[posCol];
		}
		else 
		{
			numFila++;
		}
		posFila++;
	}

	return vecAux;
}

Matriu& Matriu::operator=(const Matriu& matriu)
{
	checkFilaColumna(matriu.m_nFiles, matriu.m_nColumnes);

	//Copiamos el contenido de la matriz enviada a este objeto
	m_vecFilaX = matriu.m_vecFilaX;
	m_vecColY = matriu.m_vecColY;
	m_vecValue = matriu.m_vecValue;
	
	return *this;
}



void Matriu::init(int nFiles, int nCol)
{
	inicializarMatriz(nFiles, nCol);
}

void Matriu::setValor(int fila, int columna, float valor)
{
	checkFilaColumna(fila, columna);
	
	bool trobat = false;
	vector<int>::iterator itFilas = m_vecFilaX.begin();
	vector<int>::iterator itCol = m_vecColY.begin();
	vector<int>::iterator itValor = m_vecColY.begin();
	int cont = 0;
	int posAdd = 0;
	while (itFilas != m_vecFilaX.end() && !trobat)
	{
		if (*itFilas == fila) 
		{
			
			if (*itCol >= columna)// 
			{
				if (*itCol == columna)
				{
					//en el caso que exista el valor lo modificamos
					*itValor = valor;
					trobat = true;
				}
				else
				{
				}
				 
				
			}

			
		}
		itFilas++;
		itCol++;
		itValor++;
		cont++;

		
	}

	
	if (!trobat)
	{

	
		// es mayor por lo tanto no hemos encontrado el  elemento
				//esto significa que en esta pos add el elemento no encontrado
		cout << "\n\n luego de add--------------------------" << endl;
		m_vecFilaX.insert(m_vecFilaX.begin() + posAdd, fila);
		m_vecColY.insert(m_vecColY.begin() + posAdd, columna);
		m_vecValue.insert(m_vecValue.begin() + posAdd, valor);
		//posAdd = cont;
		
	}

	
}
/*En el caso que las nuevas filas y columnas sean mayores que las actuales se actualizan. Ademas se mantiene una matriz cuadrada.*/
bool Matriu::checkFilaColumna(int nuevaFila, int nuevaColumna)
{
	bool nuevaDimension = false;

	if (nuevaFila > m_nFiles) 
	{
		m_nFiles = nuevaFila;
		m_nColumnes = nuevaFila;
		nuevaDimension = true;
	}
		
	if (nuevaColumna > m_nColumnes)
	{
		m_nColumnes = nuevaColumna;
		m_nFiles = nuevaColumna;
		nuevaDimension = true;
	}

	return nuevaDimension;
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
			{

			}
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
		{
		}
		//m_matriu[i][j] += s;
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
			//int thisM = m_matriu[i][j];
			//int laOtraM = m.m_matriu[i][j];
			//if ((m_matriu[i][j] != m.m_matriu[i][j]))
			{
				iguales = false;
				i = m_nFiles;
				j = m_nColumnes;
			}
		}

	}
	return iguales;
}

void Matriu::ordenar()
{
	for (int j = 0; j< m_vecFilaX.size() - 1; j++)
	{
		for (int i = 0; i < m_vecFilaX.size() -1; i++)
		{
			if (m_vecFilaX[i] >= m_vecFilaX[i + 1])
			{
				float aux;
				if (m_vecFilaX[i] > m_vecFilaX[i + 1])
				{
					//cout << "cambio filas X : " << m_vecX[i] << "swap by " << m_vecX[i + 1] << endl;
					swap(m_vecFilaX, i);
					swap(m_vecColY, i);
					swap(m_vecValue, i);
				}
				
				if (m_vecFilaX[i] == m_vecFilaX[i + 1]) 
				{
					if (m_vecColY[i] > m_vecColY[i + 1])
					{
						//cout << "cambio col Y : " << m_vecX[i] << "swap by " << m_vecX[i + 1] << endl;
						swap(m_vecFilaX, i);
						swap(m_vecColY, i);
						swap(m_vecValue, i);
					}
				}
			}
		}
	}
	
	
}


void Matriu::swap(vector<float>& vec, int posActual)
{
	float aux = vec[posActual + 1];
	vec[posActual + 1] = vec[posActual];
	vec[posActual] = aux;
}

void Matriu::swap(vector<int>& vec, int posActual)
{
	float aux = vec[posActual + 1];
	vec[posActual + 1] = vec[posActual];
	vec[posActual] = aux;
}




bool Matriu::getValor(int fila, int columna, int &valor) 
{
	bool trobat = false;
	valor = std::nanf("");
	//se puede mejorar la eficiencia, reccorrer solo las filas que queremos
	for (int i = 0; i < m_vecFilaX.size(); i++)
	{
		if (m_vecFilaX[i] == fila)
		{
			if (m_vecColY[i] == columna)
			{
				valor = m_vecValue[i];
				i = m_vecFilaX.size();
			}
				
		}
	}
	return trobat;
}



void Matriu::liberarMemoria()
{
	// MOD
	////eliminar columnas
	//for (int i = 0; i < m_nFiles; i++)
	//	delete[] m_matriu[i];
	////eliminar filas
	//delete[] m_matriu;
}

void Matriu::inicializarMatriz(int nFiles, int nCol)
{
	m_nFiles = nFiles;
	m_nColumnes = nCol;

	m_vecFilaX.resize(nFiles,0);
	m_vecColY.resize(nFiles, 0);
	m_vecValue.resize(nFiles, DEFAULT_VALUE);
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
			//m_matriu[j][i] = auxMatriu.m_matriu[i][j];
		}
	}
}

ostream& operator<<(ostream& out, Matriu& m)
{
	// volveremos, a valorar si incrementamos filas y columnas aqui o por defecto
	cout << "MATRIU DE (FILES: " << m.m_nFiles + 1 << " COLUMNES: " << m.m_nColumnes + 1<< " )" << endl;
	cout << "VALORS (FILA::COL::VALOR)" << endl;
	for (int i = 0; i < m.m_vecFilaX.size(); i++)
	{
		out << i << "( " << m.m_vecFilaX[i] << " :: " << m.m_vecColY[i] << " :: "<< m.m_vecValue[i]<<" )" << endl;
	}
	return out;
}
