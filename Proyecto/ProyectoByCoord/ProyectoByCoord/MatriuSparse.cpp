#include "MatriuSparse.h"
#include <cmath>
#include<fstream>
#include <iostream>
#include<vector>
#include<iterator> // for iterators 

#define mostrarInfo true
#define setValBinarioON true
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
		//inicializarMatriz(0, 0);
		int fila, col;
		float valor;
		while (!miFichero.eof()) // mientras no sea el final del fichero
		{
			miFichero >> fila >> col;
			if (filaColMayor(fila, col))
			{
				resize(fila, col);
			}
		
			setVal(fila, col, DEFAULT_VEC_VALUE_1);

		}
		miFichero.close();
	}
	else
		throw "Error al leer el fichero: " + nomFitxer ;
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
	if (vect.size() > getNColumnes() || vect.size() > getNFiles())
	{
		throw "ERROR: para multiplicar el vector ha de ser igual de largo que el numero de columnas de la matriz";
	}
	int numFila = 0;
	float cont = 0;
	int sizeVect = vect.size();
	vector<float> vecAux(getNColumnes(), 0);//volveremos

	while (cont < m_vecFila.size())
	{
		
		
		float posVecFila = m_vecFila[cont];
		float posVecCol = m_vecCol[cont];
			
 		vecAux[posVecFila] += m_vecValue[cont] * vect[posVecCol];
		
		cont++;
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

bool MatriuSparse::setVal(int fila, int columna, float valor)
{
	
	bool trobat = false;
	if (filaColMayor(fila, columna))
	{
		//posicion indicada mayor que la matriz actual
		//por lo tanto no encontramos el valor
		//add valor al final
		resize(fila, columna);//modificamos dimensiones
	}

	if (setValBinarioON)
	{
		bool retflag;
		bool retval = setValBinario(trobat, fila, columna, valor, retflag);
		if (retflag) return retval;
	}
	else
	{
		//bloque de set value ineratctivo
		bool retflag;
		bool retval = setValIneractivo(trobat, fila, columna, valor, retflag);
		if (retflag) return retval;
	}
	

	


	return trobat;
}

bool MatriuSparse::setValBinario(bool trobat, int& fila, int& col, float& valor, bool& retflag)
{
	retflag = true;
	if (m_vecFila.size() > 0)
	{
		vector<int>::iterator itFila = m_vecFila.begin();
		vector<int>::iterator itCol = m_vecCol.begin();
		vector<float>::iterator itValor = m_vecValue.begin();

		int max, min, medio;
		medio = 0;
		
		max = m_vecFila.size() - 1;
		
		min = 0;

		bool trobat = false;
		while (!trobat && min <= max)
		{
			medio = ((max + min) / 2);
			
			if (m_vecFila[medio] == fila)
			{
				if (m_vecCol[medio] == col)
				{
					m_vecValue[medio] = valor;
					trobat = true;
					if(mostrarInfo)
						cout << m_vecFila[medio]<< " :: " << m_vecCol[medio] <<"encontrado, valor subtituido\t valor medio " << medio  << endl;
					return true;
				}
				{
					if (col < m_vecCol[medio])//es mayor la col del vector
					{
						max = medio - 1;
						if(mostrarInfo)
							cout << m_vecFila[medio] << " :: " << m_vecCol[medio] << "columna menor\t Nuevo MAX " << max << endl;
					}
					else//es menor la col del vector
					{
						min = medio + 1;
						if(mostrarInfo)
							cout << m_vecFila[medio] << " :: " << m_vecCol[medio] << "columna mayor\t Nuevo MIN " << min << endl;
					}
				}
			}
			{
				if (fila < m_vecFila[medio])
				{
					max = medio - 1;
					if (mostrarInfo)
						cout << m_vecFila[medio] << " :: " << m_vecCol[medio] << "fila menor\t Nuevo MAX " << max << endl;
				}
				else//fila es menor
				{
					min = medio + 1;
					if (mostrarInfo)
						cout << m_vecFila[medio] << " :: " << m_vecCol[medio] << "fila mayor\t Nuevo MIN " << min << endl;
				}
					
			}

		}

		if (!trobat)
		{
			if(mostrarInfo)
				cout << "nuevo elemenmto : "<<  m_vecFila[medio] << " :: " << m_vecCol[medio] <<  endl;
			if (fila < m_vecFila[medio])
			{
				if (col > m_vecCol[medio])
				{
					medio++;
				}
			}
			else
			{
			
				medio++;
			}
			
			//insert de la nueva posicion
			//incrementamos el iterador hasta la posicion deseada
			itFila += medio;
			itCol += medio;
			itValor += medio;
			
			addElementoMatriz(itFila, fila, itCol, col, itValor, valor);
		}
		else// no hay nada en el vector lo add
		{
			if (mostrarInfo)
				cout << "Primer elemento : " << m_vecFila[medio] << " :: " << m_vecCol[medio] << endl;
			m_vecFila.push_back(fila);
			m_vecCol.push_back(col);
			m_vecValue.push_back(valor);
			return false;
		}
	}
	else// no hay nada en el vector lo add
	{
		m_vecFila.push_back(fila);
		m_vecCol.push_back(col);
		m_vecValue.push_back(valor);
		return false;
	}
	
	return {};
}

bool MatriuSparse::setValIneractivo(bool trobat, int& fila, int& columna, float& valor, bool& retflag)
{
	retflag = true;
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
	retflag = false;
	return {};
}

void MatriuSparse::addElementoMatriz(
	std::vector<int>::iterator& itFila, 
	int& fila, std::vector<int>::iterator& itCol, 
	int& columna, std::vector<float>::iterator& itValor, 
	float& valor)
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
	//return getInteractivo(valor, fila, col);

	return getBinario(valor, fila , col);
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
		max = m_vecFila.size()-1;
		min = 0;

		bool trobat = false;
		while (!trobat && min <= max)
		{
			medio = ((max + min) / 2);
			
			if (m_vecFila[medio] == fila && m_vecCol[medio] == col)
			{
				valor = m_vecValue[medio];
				trobat = true;
			}
			else
			{
				if (m_vecFila[medio] >= fila  && m_vecCol[medio] > col)
				{
					/*cuando la fila es mayor o igual he de decidir si es mayor o menor a apartir de la columna*/
					if (m_vecFila[medio] == fila)
					{
						if (m_vecCol[medio] > col)
						{
							max = medio - 1;
						}
						else
						{
							min = medio + 1;
						}
					}
					else //if(m_vecFila[medio] > fila)
					{

						max = medio - 1;
					}
				}
				else
				{
					min = medio + 1;
				}
			}
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
			if (mostrarInfo)
				//cout << m_vecFila[contFila] << "\t" << m_vecCol[contFila] << endl;
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
	out << "MATRIU DE (FILES: " << m.getNFiles()  << "  COLUMNES: " << m.getNColumnes()  << " )" << endl;
	out << "VALORS (FILA::COL::VALOR)" << endl;
	for (int i = 0; i < m.m_vecFila.size(); i++)
	{
		out << "( " << m.m_vecFila[i] << " :: " << m.m_vecCol[i] << " :: " << m.m_vecValue[i] << " ) " << endl ;
	}
	return out;
}
