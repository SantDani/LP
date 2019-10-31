#include "MatriuSparse.h"
#include <cmath>
#include<fstream>
#include <iostream>
#include<vector>
#include<iterator> // for iterators 

#define style false
using namespace std;
//Constructores


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
		inicializarMatriz(0, 0);
		int fila, col, filaAnterior , colAnterior;

		miFichero >> filaAnterior >> colAnterior;
		m_vecFila.emplace_back(filaAnterior);
		m_vecCol.emplace_back(colAnterior);
		m_vecValue.emplace_back(DEFAULT_VEC_VALUE_1);
		
		
		while (!miFichero.eof()) // mientras no sea el final del fichero
		{

			miFichero >> fila >> col;
		
			resize(fila, col);
			if (filaAnterior == fila && colAnterior != col)
			{
				m_vecFila.emplace_back(fila);
				m_vecCol.emplace_back(col);
				m_vecValue.emplace_back(DEFAULT_VEC_VALUE_1);
			}
			else
			{
				if (filaAnterior != fila && colAnterior != col)
				{
					m_vecFila.emplace_back(fila);
					m_vecCol.emplace_back(col);
					m_vecValue.emplace_back(DEFAULT_VEC_VALUE_1);
				}
						
			}

			//cout << fila << " : " << col<< "\t";
			filaAnterior = fila;
			colAnterior = col;
			
		}
		miFichero.close();
	}
	else
		throw "Error al leer el fichero: " +nomFitxer ;
	//this->ordenar();
}

MatriuSparse::MatriuSparse(int nFiles, int nColumnes)
{

	inicializarMatriz(nFiles, nColumnes);
}



MatriuSparse& MatriuSparse::operator*(float num)
{
	int posFila = 0;
	MatriuSparse *mAux(new MatriuSparse(*this));
	while (posFila < m_vecFila.size())
	{
		float res = m_vecValue[posFila] * num;
		(*mAux).m_vecValue[posFila] = m_vecValue[posFila] * num;
		posFila++;
	}
	
	return  *mAux;
}


vector<float> MatriuSparse::operator*(vector<float> vect)
{
	if (vect.size() > m_nColumnes || vect.size() > m_nFiles)
	{
		throw "ERROR: para multiplicar el vector ha de ser igual de largo que el numero de columnas de la matriz";
	}
	int numFila = 0;
	int posFila = 0;
	int sizeVect = vect.size();
	vector<float> vecAux(vect.size()+1 , 0);//volveremos

	while (posFila < m_vecFila.size())
	{
		if (m_vecFila[posFila] == numFila)
		{
			int posCol = m_vecCol[posFila]-1;
			float valorMul = vect[posCol];
			vecAux[posCol] += m_vecValue[posCol] * vect[posCol];
		}
		else 
		{
			numFila++;//vamos a la siguiente fila
		}
		posFila++;
	}

	return vecAux;
}

MatriuSparse& MatriuSparse::operator/(float num)
{
	if (num == 0)
	{
		throw "Error al dividir entre 0!" ;
	}
	
	int posFila = 0;
	MatriuSparse* mAux(new MatriuSparse(*this));
	while (posFila < m_vecFila.size())
	{

		(*mAux).m_vecValue[posFila] = m_vecValue[posFila] / num;
		posFila++;
	}
	
	return  *mAux;
}

MatriuSparse& MatriuSparse::operator=(const MatriuSparse& matriu)
{
	resize(matriu.m_nFiles, matriu.m_nColumnes);

	m_vecFila = matriu.m_vecFila;
	m_vecCol = matriu.m_vecCol;
	m_vecValue = matriu.m_vecValue;

	return *this;
}



MatriuSparse::MatriuSparse(const MatriuSparse& matriu)
{
	resize(matriu.m_nFiles, matriu.m_nColumnes);

	//Copiamos el contenido de la matriz enviada a este objeto
	m_vecFila = matriu.m_vecFila;
	m_vecCol = matriu.m_vecCol;
	m_vecValue = matriu.m_vecValue;
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
		//m_vecFila.push_back(fila);
		//m_vecCol.push_back(columna);
		//m_vecValue.push_back(valor);
		//return false;
	}


	if (!trobat)
	{
		vector<int>::iterator itFila = m_vecFila.begin();
		vector<int>::iterator itCol = m_vecCol.begin();
		vector<float>::iterator itValor = m_vecValue.begin();
		
		while (itFila != m_vecFila.end() && !trobat)
		{
			if ((*itFila) <= fila)
			{
				/*Podemos hacer la condicion siguiente porque el vector
				esta ordenado. de esta manera tambien podemos add los nuevos elementos
				de manera ordenada*/
				if ((*itFila) == fila)
				{
					if (columna < *itCol)
					{
						//add valor que no exisita
						//if(*itValor != 0) //hemos add el valor por lo tanto no lo hemos encontrado
							addElementoMatriz(itFila, fila, itCol, columna, itValor, valor);
						return false;
					}

					//si es igual modificamos
					
					if (*itCol == columna)
					{
						//modificamos el valor porque existe
						*itValor = valor;
						return true;
					}
				}
			}
			else if (*itFila > fila)
			{
				if (!trobat)
				{
					/*En el caso que vayamos a la siguiente fila (mayor)
						no hemos encontrado una columna menor, por lo tanto
						la que se ha enviado ser sera la mayor y hay que add*/
					addElementoMatriz(itFila, fila, itCol, columna, itValor, valor);

					return false;
				}
			}
			//nadie ha cumplido 
			//veamos si el siguiente cumple alguna condicion
			++itFila;
			++itCol;
			++itValor;
		}

	}
	if (!trobat)//dejo el trobat porque asi se entiende mejor que no se ha encontrado ningun elemento
	{
		//cambiamos de fila y elemento menor no encontrado
		/*Significa que no existe por lo tanto add*/
		m_vecFila.push_back(fila);
		m_vecCol.push_back(columna);
		m_vecValue.push_back(valor);
		return false;
	}

	return trobat;
}

void MatriuSparse::addElementoMatriz(std::vector<int>::iterator& itFila, int& fila, std::vector<int>::iterator& itCol, int& columna, std::vector<float>::iterator& itValor, float& valor)
{
	m_vecFila.insert(itFila, fila);
	m_vecCol.insert(itCol, columna);
	m_vecValue.insert(itValor, valor);
}

/*En el caso que las nuevas filas y columnas sean mayores que las actuales se actualizan de manera
que la dimension de la matriz sea cuadrada.*/
bool MatriuSparse::resize(int nuevaFila  , int nuevaColumna )
{
	bool nuevaDimension = false;

	if (nuevaFila > m_nFiles)
	{
		m_nFiles = nuevaFila;
		m_nColumnes = nuevaFila;
		nuevaDimension = true;
	}
	else if (nuevaColumna > m_nColumnes)
	{
		m_nFiles = nuevaColumna;
		m_nColumnes = nuevaColumna;
		nuevaDimension = true;
	}

	return nuevaDimension;
}

bool MatriuSparse::filaColMayor(int fila, int columna) 
{
	bool mayor = false;

	if (fila > m_nFiles || columna > m_nColumnes)
	{
		mayor = true;
	}

	return mayor;
}



void MatriuSparse::ordenar()
{
	for (int j = 0; j < m_vecFila.size() - 1; j++)
	{
		for (int i = 0; i < m_vecFila.size() - 1; i++)
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

bool MatriuSparse::getVal(int  fila, int  col,  float& valor) 
{
	return getInteractivo(valor, fila, col);

	//return getBinario(valor, fila, col);
}

bool MatriuSparse::getBinario(float& valor, int fila, int col)
{
	valor = DEFAULT_VEC_VALUE_0;
	if (filaColMayor(fila, col))
	{
		//es mayor por lo tanto no lo vamos a encontrar el elemento
		return false;
	}
	else
	{
		int max, min, medio;
		max = m_vecFila.size();
		min = 0;

		bool trobat = false;

		int contFila = 0;
		while (contFila < m_vecFila.size() && !trobat)
		{
			medio = ((max + min) / 2);
			if (style)
				cout << m_vecFila[contFila] << "\t" << m_vecCol[contFila] << endl;

			if (m_vecFila[medio] == fila && m_vecCol[medio] == col)
			{
				valor = m_vecValue[contFila];
				trobat = true;
			}
			else
			{
				if (m_vecFila[medio] < fila  && m_vecCol[medio] < col)
				{
					max = medio - 1;
				}
				else
				{
					min = medio + 1;
				}
			}
			contFila++;

		}

		return true;//no encontrado valor pero esta dentro de la matriz por lo tanto existe con valor 0
	}
}

bool MatriuSparse::getInteractivo(float& valor, int fila, int col)
{
	valor = DEFAULT_VEC_VALUE_0;
	if (filaColMayor(fila, col))
	{
		//es mayor por lo tanto no lo vamos a encontrar el elemento
		return false;
	}
	else
	{
		bool trobat = false;

		int contFila = 0;
		while (contFila < m_vecFila.size() && !trobat)
		{
			if (style)
				cout << m_vecFila[contFila] << "\t" << m_vecCol[contFila] << endl;
			if (m_vecFila[contFila] == fila && m_vecCol[contFila] == col)
			{
				valor = m_vecValue[contFila];
				trobat = true;
			}
			else
			{
				if (m_vecFila[contFila] > fila)
				{
					//no encontrado valor, por lo tanto la posicion vale 0. Valor por defecto
					return true;
				}
			}
			contFila++;

		}

		return true;//no encontrado valor pero esta dentro de la matriz por lo tanto existe con valor 0
	}
}

void MatriuSparse::inicializarMatriz(int nFiles, int nCol)
{
	resize(nFiles, nCol);

	m_vecFila.resize(nFiles, 0);
	m_vecCol.resize(nFiles, 0);
	m_vecValue.resize(nFiles, DEFAULT_VEC_VALUE_0);
}

ostream& operator<<(ostream& out, MatriuSparse& m)
{
	// volveremos, a valorar si incrementamos filas y columnas aqui o por defecto
	out << "MATRIU DE (FILES: " << m.m_nFiles + 1  << "  COLUMNES: " << m.m_nColumnes + 1  << " )" << endl;
	out << "VALORS (FILA::COL::VALOR)" << endl;
	for (int i = 0; i < m.m_vecFila.size(); i++)
	{
		out << "( " << m.m_vecFila[i] << " :: " << m.m_vecCol[i] << " :: " << m.m_vecValue[i] << " ) " << endl ;
	}
	return out;
}
