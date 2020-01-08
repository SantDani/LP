#include "MatriuSparse.h"
#include <cmath>
#include<fstream>
#include <iostream>
#include<vector>
#include<iterator> // for iterators 

#define mostrarInfo false
using namespace std;


/*MatriuSparse::clear(): funcion que libera la memoria ocupada por los atributos del objeto MatriuSparse*/
void MatriuSparse::clear()
{
	m_nFiles = 0;
	m_nColumnes = 0;
	m_vecFila.clear();
	m_vecCol.clear();
	m_vecValue.clear();
}

/** calculaGrau(vector<int>& graus): calcula el grado(relaciones de cada nodo) de cada nodo.

	parametro graus: vector en el que se guardara el grado de cada nodo
*/
void MatriuSparse::calculaGrau(vector<int>& graus) const
{
	/*El grado de cada nodo es igual al numero de aristas/relacions con otros nodos.
	Por lo tanto, cada nodo tendra tantas relaciones como veces aparece en la matriz dispersa
	*/
	
	int cont = 0;
	int valorNodoActual = m_vecFila[0];
	graus.resize(m_nFiles + 1, 0);
		
	for (;  cont < m_vecFila.size(); cont++)
	{
		int actualFila = m_vecFila[cont];
		graus[actualFila]++;
	}
}

/*creaMaps
vMaps_deltaQ: es un vector que contiene maps. La clave del maps esta formada por un pair de dos ints. El valor del map es un double que
guardara el valor de deltaQ que se calcula en la clase Comunitats.

La finalidad de esta funcion es crear la estructura de vMaps_deltaQ, es decir, inicializar el vector de mapas. (En esta funcion no se calcula deltaQ)
*/
void MatriuSparse::creaMaps(vector< map<pair<int, int>, double> >& vMaps_deltaQ) const
{
	vMaps_deltaQ.resize(m_nFiles + 1);

	for (int cont = 0; cont < m_vecValue.size(); cont++)
	{
		int filaActual = m_vecFila[cont];
		int colActual = m_vecCol[cont];
		vMaps_deltaQ[filaActual][{filaActual, colActual}] = 0.0;
	}
}

/** MatriuSparse(): constructor por defecto que inicializa los atributos de la matriz dispersa.
*/
MatriuSparse::MatriuSparse()
{
	m_vecFila.resize(0);
	m_vecCol.resize(0);
	m_vecValue.resize(0);

	m_nColumnes = 0;
	m_nFiles = 0;
}
/** MatriuSparse::MatriuSparse(string nomFitxer): constructor con parametro. Que inicializa la matriz dispersa a partir de la informacion que contiene
el fichero pasado por parametro (nomFitxer).

El constructor va leyendo el fichero linea por linea hasta el final. Cada linea que lee comprueba las dimensiones de la matriz (fila y columna), en el 
caso que estas sean mayores actualiza el tamaño de la fila o columna.
Se utiliza el setVal() para añadir la fila, columna y el valor (que es un valor por defecto de valor 1). De esta manera estas quedan ordenadas, aunque,
nos dieran el fichero con las filas y columnas desordenadas. 

En el caso de haber un error con la lectura lanza un error que se recoge en el main.

	nomFitxer: parametro String que contiene la direccion de un fichero con la infromacion de una matriz.


*/
MatriuSparse::MatriuSparse(string nomFitxer)
{
	ifstream miFichero; //Declaro el objeto ifstream para poder leer el fichero
	miFichero.open(nomFitxer);

	if (miFichero.is_open())
	{
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
		throw "Error al leer el fichero: " + nomFitxer;
}

/** MatriuSparse::MatriuSparse(int nFiles, int nColumnes): constructor que inicializa la matriz con unas filas y columnas indicadas. Con el valor de las
filas y columnas se inicializan los atributos de la matriz dispersa con unas filas y columnas indicadas mediante la funcion int().
Muy similar al constructor por defecto, pero en este caso se le da un tamaño (filas y columnas) a la matriz dispersa .

	nFiles: parametro integer que indica el valor de las filas.
	nColumnes : parametro integer que indica el valor de las columnas.
*/
MatriuSparse::MatriuSparse(int nFiles, int nColumnes)
{
	init(nFiles, nColumnes);
}


/** MatriuSparse& MatriuSparse::operator*(float num): funcion que multiplica la matriz por un numero real

	num: parametro flotante (numero real) que contiene el valor por el cual se quiere multiplicar la matriz dispersa.

	return: devuelve una matriz con la operacion realizada, Es decir, la matriz actual no se modifica se envia una matriz auxiliar con el resultado.
 */
MatriuSparse& MatriuSparse::operator*(float num)
{
	int posFila = 0;
	MatriuSparse* mAux(new MatriuSparse(*this));
	while (posFila < m_vecFila.size())
	{
		float res = m_vecValue[posFila] * num;
		(*mAux).m_vecValue[posFila] = m_vecValue[posFila] * num;
		posFila++;
	}

	return  *mAux;
}

/*operator*(vector<float> vect): funcion que multplica la matriz por un vector.

	vect: es un vector flotante (vector de numeros reales) que contiene los valores por el cual se va a multiplicar la matriz dispresa.

	return: devuelve la matriz multiplicada por el vector, esto significa que cambian las dimensiones de la matriz y devuelve un vector auxirliar con el
	resultado, es decir, no se modifica la matriz actual.
*/
vector<float> MatriuSparse::operator*(vector<float> vect)
{
	if (vect.size() > getNColumnes() || vect.size() > getNFiles())
	{
		throw "ERROR: al multiplicar. El vector ha de tener el mismo tramaño que la matriz";
	}

	float cont = 0;
	vector<float> vecAux(getNColumnes(), 0);

	/*cont es un contador que nos sirve para desplazarnos por la matriz de manera vertical (imaginamos la matriz X Y valor). Una vez cont llege al final
	de la matriz se habra acabado la operacion.
	*/
	while (cont < m_vecFila.size())
	{
		float posVecFila = m_vecFila[cont];
		float posVecCol = m_vecCol[cont];

		vecAux[posVecFila] += m_vecValue[cont] * vect[posVecCol];

		cont++;
	}

	return vecAux;
}

/**
*/
MatriuSparse& MatriuSparse::operator/(float num)
{
	if (num == 0)
	{
		throw "Error al dividir entre 0!";
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
	resize(nFiles, nCol);

	m_vecFila.resize(nFiles, 0);
	m_vecCol.resize(nFiles, 0);
	m_vecValue.resize(nFiles, DEFAULT_VEC_VALUE_0);
}

bool MatriuSparse::setVal(int newFila, int newCol, float valor)
{

	bool trobat = false;
	if (filaColMayor(newFila, newCol))
	{
		//posicion indicada mayor que la matriz actual
		//por lo tanto no encontramos el valor
		//add valor al final
		resize(newFila, newCol);//modificamos dimensiones
	}

	if (m_vecFila.size() > 0)
	{


		int max, min, medio;

		medio = 0;
		max = m_vecFila.size() - 1;
		min = 0;

		bool trobat = false;
		while (!trobat && min <= max)
		{

			medio = ((max + min) / 2);
			if (mostrarInfo)
				cout << " medio actual\t " << medio << endl;

			if (m_vecFila[medio] == newFila)
			{
				if (m_vecCol[medio] == newCol)
				{
					m_vecValue[medio] = valor;
					trobat = true;
					if (mostrarInfo)
						cout << m_vecFila[medio] << " :: " << m_vecCol[medio] << " encontrado, valor subtituido\t valor medio " << medio << endl << endl;;
					return true;
				}
				else
				{
					if (newCol < m_vecCol[medio])//es mayor la col del vector
					{
						max = medio - 1;
						if (mostrarInfo)
							cout << m_vecFila[medio] << " :: " << m_vecCol[medio] << " columna menor\t Nuevo MAX " << max << endl;
					}
					else//es menor la col del vector
					{
						min = medio + 1;
						if (mostrarInfo)
							cout << m_vecFila[medio] << " :: " << m_vecCol[medio] << " columna mayor\t Nuevo MIN " << min << endl;
					}
				}
			}
			else
			{
				if (newFila < m_vecFila[medio])
				{
					max = medio - 1;
					if (mostrarInfo)
						cout << m_vecFila[medio] << " :: " << m_vecCol[medio] << " fila menor\t Nuevo MAX " << max << endl;
				}
				else//fila es menor
				{
					min = medio + 1;
					if (mostrarInfo)
						cout << m_vecFila[medio] << " :: " << m_vecCol[medio] << " fila mayor\t Nuevo MIN " << min << endl;
				}
			}

		}

		if (!trobat)
		{
			vector<int>::iterator itFila = m_vecFila.begin();
			vector<int>::iterator itCol = m_vecCol.begin();
			vector<float>::iterator itValor = m_vecValue.begin();

			if (mostrarInfo)
				cout << "medio actual " << medio << " nuevo elemenmto : " << newFila << " :: " << newCol << endl;
			if (newFila <= m_vecFila[medio])
			{
				if (newFila == m_vecFila[medio])
				{
					if (newCol > m_vecCol[medio])
					{
						medio++;
					}
				}
				else if (newFila > m_vecFila[medio])
				{
					medio++;
				}
			}
			else
			{
				medio++;
				if (mostrarInfo)
					cout << "fila mayor, medio incrementado " << medio << endl;
			}

			//insert de la nueva posicion
			//incrementamos el iterador hasta la posicion deseada
			itFila += medio;
			itCol += medio;
			itValor += medio;

			addElementoMatriz(itFila, newFila, itCol, newCol, itValor, valor);
		}

	}
	else// no hay nada en el vector lo add
	{
		if (mostrarInfo)
			cout << "Primer elemento : " << newFila << " :: " << newCol << endl << endl;

		m_vecFila.emplace_back(newFila);
		m_vecCol.emplace_back(newCol);
		m_vecValue.emplace_back(valor);
		return false;
	}
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
bool MatriuSparse::resize(int nuevaFila, int nuevaColumna)
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

//void MatriuSparse::ordenar()
//{
//	for (int j = 0; j < m_vecFila.size() - 1; j++)
//	{
//		for (int i = 0; i < m_vecFila.size() - 1; i++)
//		{
//			if (m_vecFila[i] >= m_vecFila[i + 1])
//			{
//				float aux;
//				if (m_vecFila[i] > m_vecFila[i + 1])
//				{
//					//cout << "cambio filas X : " << m_vecX[i] << "swap by " << m_vecX[i + 1] << endl;
//					swap(m_vecFila, i);
//					swap(m_vecCol, i);
//					swap(m_vecValue, i);
//				}
//
//				if (m_vecFila[i] == m_vecFila[i + 1])
//				{
//					if (m_vecCol[i] > m_vecCol[i + 1])
//					{
//						//cout << "cambio col Y : " << m_vecX[i] << "swap by " << m_vecX[i + 1] << endl;
//						swap(m_vecFila, i);
//						swap(m_vecCol, i);
//						swap(m_vecValue, i);
//					}
//				}
//			}
//		}
//	}
//}
//
//void MatriuSparse::swap(vector<float>& vec, int posActual)
//{
//	float aux = vec[posActual + 1];
//	vec[posActual + 1] = vec[posActual];
//	vec[posActual] = aux;
//}
//
//void MatriuSparse::swap(vector<int>& vec, int posActual)
//{
//	float aux = vec[posActual + 1];
//	vec[posActual + 1] = vec[posActual];
//	vec[posActual] = aux;
//}

bool MatriuSparse::getVal(int  fila, int  col, float& valor)
{
	//return getInteractivo(valor, fila, col);
	return getBinario(valor, fila, col);
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
		max = m_vecFila.size() - 1;
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
				if (m_vecFila[medio] >= fila)
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

ostream& operator<<(ostream& out,   const MatriuSparse& m)
{
	out << "MATRIU DE (FILES: " << m.getNFiles() << "  COLUMNES: " << m.getNColumnes() << " )" << endl;
	out << "VALORS (FILA::COL::VALOR)" << endl;
	for (int i = 0; i < m.m_vecFila.size(); i++)
	{
		out << "( " << m.m_vecFila[i] << " :: " << m.m_vecCol[i] << " :: " << m.m_vecValue[i] << " ) " << endl;
	}
	return out;
}
