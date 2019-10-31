#include "Matriu.h"
#include <cmath>
#include<fstream>
#include <iostream>
#include<vector>
#include<iterator> // for iterators 

using namespace std;
//Constructores
MatriuSparse::~MatriuSparse()
{
	liberarMemoria();
}


MatriuSparse::MatriuSparse()
{
	m_vecFila.resize(0);
	m_vecCol.resize(0);
	m_vecValue.resize(0);

	m_nColumnes = 0;
	m_nFiles = 0;
}

MatriuSparse::MatriuSparse(string nomFitxer)
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

			resize(fila, col);

			m_vecFila.emplace_back(fila);
			m_vecCol.emplace_back(col);
			m_vecValue.emplace_back(DEFAULT_VEC_VALUE);
			i++;
		}
		miFichero.close();
	}
	else
		cout << "Error al leer el fichero" << endl;
	this->ordenar();
}

MatriuSparse::MatriuSparse(int nFiles, int nColumnes)
{
	
	inicializarMatriz(nFiles, nColumnes);
}

MatriuSparse::MatriuSparse(const MatriuSparse& matriu)
{
	resize(matriu.m_nFiles, matriu.m_nColumnes);

	//Copiamos el contenido de la matriz enviada a este objeto
	m_vecFila = matriu.m_vecFila;
	m_vecCol = matriu.m_vecCol;
	m_vecValue = matriu.m_vecValue;	
}


MatriuSparse& MatriuSparse::operator*(float num)
{
	int posFila = 0;
	MatriuSparse mAux(*this);
	while (posFila < m_vecFila.size())
	{
		mAux.m_vecValue[posFila] = m_vecValue[posFila] * num;
		posFila++;
	}

	return  mAux;
}

MatriuSparse MatriuSparse::operator/(float num)
{
	MatriuSparse mAux(*this);
	
	int posFila = 0;
	while (posFila < m_vecFila.size())
	{
		mAux.m_vecValue[posFila] = m_vecValue[posFila] * num;
		posFila++;
	}

	return  mAux;
}

vector<float> MatriuSparse::operator*(vector<float> vect)
{
	int numFila = 0;
	int posFila = 0;
	int sizeVect = vect.size();
	vector<float> vecAux(sizeVect, 0);

	while (posFila < m_vecFila.size())
	{
		if (m_vecFila[posFila] == numFila)
		{
			int posCol = m_vecCol[posFila];
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

MatriuSparse& MatriuSparse::operator=(const MatriuSparse& matriu)
{
	resize(matriu.m_nFiles, matriu.m_nColumnes);

	//Copiamos el contenido de la matriz enviada a este objeto
	m_vecFila = matriu.m_vecFila;
	m_vecCol = matriu.m_vecCol;
	m_vecValue = matriu.m_vecValue;
	
	return *this;
}



void MatriuSparse::init(int nFiles, int nCol)
{
	inicializarMatriz(nFiles, nCol);
}

bool MatriuSparse::existe(int nFila, int nCol)
{
	bool existe = false;
	//existira si encuentro la fila y la columna de la posicion
	//volveremos
	return existe;
}



bool MatriuSparse::setVal(int fila, int columna, float valor)
{
	bool trobat = false;
	if (filaColMayor(fila, columna))
	{
		//posicion indicada mayor que la matriz actual
		//por lo tanto no encontramos el valor
		//add valor al final
		resize(fila, columna);//modificamos dimensiones

		valor = DEFAULT_VEC_VALUE;
		m_vecFila.push_back(fila);
		m_vecCol.push_back(columna);
		m_vecValue.push_back(DEFAULT_VEC_VALUE);
		return trobat;
	}
	
	
	if (!false)
	{
		vector<int>::iterator itFila = m_vecFila.begin();
		
		vector<int>::iterator itCol = m_vecCol.begin();
		vector<float>::iterator itValor = m_vecValue.begin();
		int cont = 0;
		vector<int>::iterator end = m_vecFila.end();
		while (itFila != end && !trobat)
		{
			cout << " valor fila : "<< *itFila << endl;
			if ((*itFila) <= fila)
			{
				/*Podemos hacer la condicion siguiente porque el vector
				esta ordenado. de esta manera tambien podemos add los nuevos elementos
				de manera ordenada*/
				if ((*itFila) == fila)
				{
					cout << " valor col : " << *itCol << endl;
					if (columna < *itCol)
					{
						//add valor que no exisita
						m_vecFila.insert(itFila, fila);
						m_vecCol.insert(itCol, columna);
						m_vecValue.insert(itValor, valor);
						return false;//hemos add el valor por lo tanto no lo hemos encontrado
					} 

					//si es igual modificamos


					//modificamos el valor porque existe
					if (*itCol == columna)
					{
						valor = *itValor;
						trobat = true;
					}

					
				}
				
				
			}
			else if(*itFila > fila)
			{
				if (!trobat)
				{
					m_vecFila.insert(itFila, fila);
					m_vecCol.insert(itCol, columna);
					m_vecValue.insert(itValor, valor);
					return trobat;
				}
			
			}
			//nadie ha cumplido 
			//veamos si el siguiente cumple alguna condicion
			++itFila;
			++itCol;
			++itValor;
		}
		
	}
	if (!trobat) // pensar como hacerlo
	{
		//cambiamos de fila y elemento menor no encontrado
		/*Significa que no existe por lo tanto add*/
		m_vecFila.push_back(fila);
		m_vecCol.push_back(columna);
		m_vecValue.push_back(DEFAULT_VEC_VALUE);
		return false;
	}
	
	return trobat;
}
	
	/*En el caso que las nuevas filas y columnas sean mayores que las actuales se actualizan de manera 
que la dimension de la matriz sea cuadrada.*/
bool MatriuSparse::resize(int nuevaFila, int nuevaColumna)
{
	bool nuevaDimension = false;

	if (nuevaFila > m_nFiles || nuevaColumna > m_nColumnes)
	{
		m_nFiles = nuevaFila;
		m_nColumnes = nuevaFila;
		nuevaDimension = true;
	}

	return nuevaDimension;
}

bool MatriuSparse::filaColMayor(int fila, int columna)
{
	bool mayor = false;

	if (fila > m_nFiles || columna > m_nColumnes)
	{
		m_nFiles = fila;
		m_nColumnes = columna;
		mayor = true;
	}

	return mayor;
}

MatriuSparse MatriuSparse::operator+(const MatriuSparse& m)
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
		return MatriuSparse();
	}

}

MatriuSparse MatriuSparse::operator+(float s)
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



bool MatriuSparse::operator==(const MatriuSparse& m)
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

void MatriuSparse::ordenar()
{
	for (int j = 0; j< m_vecFila.size() - 1; j++)
	{
		for (int i = 0; i < m_vecFila.size() -1; i++)
		{
			if (m_vecFila[i] >= m_vecFila[i + 1])
			{
				float aux;
				if (m_vecFila[i] > m_vecFila[i + 1])
				{
					//cout << "cambio filas X : " << m_vecX[i] << "swap by " << m_vecX[i + 1] << endl;
					swap(m_vecFila, i);
					swap(m_vecCol, i);
					swap(m_vecValue, i);
				}
				
				if (m_vecFila[i] == m_vecFila[i + 1]) 
				{
					if (m_vecCol[i] > m_vecCol[i + 1])
					{
						//cout << "cambio col Y : " << m_vecX[i] << "swap by " << m_vecX[i + 1] << endl;
						swap(m_vecFila, i);
						swap(m_vecCol, i);
						swap(m_vecValue, i);
					}
				}
			}
		}
	}
	
	
}


void MatriuSparse::swap(vector<float>& vec, int posActual)
{
	float aux = vec[posActual + 1];
	vec[posActual + 1] = vec[posActual];
	vec[posActual] = aux;
}

void MatriuSparse::swap(vector<int>& vec, int posActual)
{
	float aux = vec[posActual + 1];
	vec[posActual + 1] = vec[posActual];
	vec[posActual] = aux;
}




bool MatriuSparse::getVal(int fila, int columna, int &valor) 
{
	bool trobat = false;
	valor = std::nanf("");
	//se puede mejorar la eficiencia, reccorrer solo las filas que queremos
	for (int i = 0; i < m_vecFila.size(); i++)
	{
		if (m_vecFila[i] == fila)
		{
			if (m_vecCol[i] == columna)
			{
				valor = m_vecValue[i];
				i = m_vecFila.size();
			}
				
		}
	}
	return trobat;
}



void MatriuSparse::liberarMemoria()
{
	// MOD
	////eliminar columnas
	//for (int i = 0; i < m_nFiles; i++)
	//	delete[] m_matriu[i];
	////eliminar filas
	//delete[] m_matriu;
}

void MatriuSparse::inicializarMatriz(int nFiles, int nCol)
{
	m_nFiles = nFiles;
	m_nColumnes = nCol;

	m_vecFila.resize(nFiles,0);
	m_vecCol.resize(nFiles, 0);
	m_vecValue.resize(nFiles, DEFAULT_VEC_VALUE);
}



void MatriuSparse::transpose()
{
	MatriuSparse auxMatriu(*this);
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

ostream& operator<<(ostream& out, MatriuSparse& m)
{
	// volveremos, a valorar si incrementamos filas y columnas aqui o por defecto
	cout << "MATRIU DE (FILES: " << m.m_nFiles + 1 << " COLUMNES: " << m.m_nColumnes + 1<< " )" << endl;
	cout << "VALORS (FILA::COL::VALOR)" << endl;
	for (int i = 0; i < m.m_vecFila.size(); i++)
	{
		out << i << "( " << m.m_vecFila[i] << " :: " << m.m_vecCol[i] << " :: "<< m.m_vecValue[i]<<" )" << endl;
	}
	return out;
}
