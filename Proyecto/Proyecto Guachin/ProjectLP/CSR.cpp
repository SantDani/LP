#include "CSR.h"

using namespace std;

//--------------------------CONTRUCTORES-------------------------------
MatriuSparse::~MatriuSparse()
{
	//liberarMemoria();
}
MatriuSparse::MatriuSparse()
{
	m_columnes.resize(0);
	m_valor.resize(0);
	m_indexFils.resize(0);

	m_nColumnes = 0;
	m_nFiles = 0;
}
MatriuSparse::MatriuSparse(int nFiles, int nColumnes)
{
	inicializarMatriz(nFiles, nColumnes);
}
void MatriuSparse::inicializarMatriz(int nFiles, int nCol)
{
	m_nFiles = nFiles;
	m_nColumnes = nCol;

	m_columnes.resize(0);
	m_valor.resize(0);
	m_indexFils.resize(0);
}
MatriuSparse::MatriuSparse(const MatriuSparse& matriu)
{
	inicializarMatriz(matriu.m_nFiles, matriu.m_nColumnes);
	//Copiamos el contenido de la matriz enviada a este objeto
	for (int i = 0; i < matriu.m_columnes.size(); i++)
	{
		m_columnes.push_back(matriu.m_columnes[i]);
		m_valor.push_back(matriu.m_valor[i]);
	}
	for (int i = 0; i < matriu.m_indexFils.size(); i++)
	{
		m_indexFils.push_back(matriu.m_indexFils[i]);
	}
	m_nElements = matriu.m_nElements;
}
MatriuSparse::MatriuSparse(string nomFitxer)
{
	ifstream miFichero; //Declaro el objeto ifstream para poder leer el fichero
	miFichero.open(nomFitxer);
	int cont,filaAux=0,tamany=0,addIndex=0;
	if (miFichero.is_open())
	{
		int fila, col, valor, contElements;
		contElements = 0;
		inicializarMatriz(0, 0);
		m_indexFils.emplace_back(0);


		miFichero >> fila >> col;
		while (!miFichero.eof()) // mientras no sea el final del fichero
		{
			addIndex = fila- filaAux ;
			if (addIndex !=0)
			{
				filaAux = fila;
				for (int i = 0; i < addIndex; i++)
				{
					m_indexFils.emplace_back(contElements);
				}
			}

			if (tamany < fila)
				tamany = fila;
			if (tamany < col)
				tamany = col;

			m_columnes.emplace_back(col);
			m_valor.emplace_back(1);
			contElements++;
			miFichero >> fila >> col;
		}
		m_nElements = contElements;
		m_indexFils.emplace_back(contElements);
		miFichero.close();
		m_nFiles=tamany+1;
		m_nColumnes=tamany+1;
	}
	else
		cout << "Error al leer el fichero" << endl;

}
//_____________________________________________________________________




#pragma region Metodos
//----------------------------METODOS-----------------------------------
void MatriuSparse::init(int nFiles, int nCol)
{
	inicializarMatriz(nFiles, nCol);
}
void MatriuSparse::conseguirPos(const int &valorFil, const int &columna, int &valorColumna, vector<int>::iterator  &posColumna, vector<float>::iterator  &posValor) {

	valorColumna = m_columnes[valorFil];
	if (columna<valorColumna)
	{
		posColumna += valorFil;
		posValor += valorFil;
	}
	else
	{
		posColumna += valorFil + 1;
		posValor += valorFil + 1;
	}
}

void MatriuSparse::resize(int fila, int columna, int valor)
{

	int valorFil, valorFilAnt, valorColumna, penultimoValorFil, valorGran, tamany;
	vector<int>::iterator posColumna = m_columnes.begin();
	vector<int>::iterator posIndexFil = m_indexFils.begin();
	vector<float>::iterator  posValor = m_valor.begin();
	int nVacios;

	if (columna>fila)
	{
		tamany = columna + 1;
		nVacios = columna - (m_nColumnes - 1);
	}
	else
	{
		tamany = fila + 1;
		nVacios = fila - (m_nFiles - 1);
	}
	m_nColumnes = tamany;
	m_nFiles = tamany;


	penultimoValorFil = m_indexFils[m_indexFils.size() - 1];
	if (nVacios>1)
	{
		for (int i = 0; i < nVacios; i++)
		{
			m_indexFils.insert(m_indexFils.end(), penultimoValorFil);
		}
	}
	else
		m_indexFils.insert(m_indexFils.end(), penultimoValorFil);


	valorFil = m_indexFils[fila];
	valorFilAnt = m_indexFils[fila - 1];
	if (valorFil == valorFilAnt)
	{
		posColumna += valorFil + 1;
		posValor += valorFil + 1;
		m_indexFils[fila] = valorFil + 1;
		for (int i = fila; i < m_indexFils.size() - 1; i++)
		{
			m_indexFils[i]++;
		}
	}

	else
		posColumna = m_columnes.end(); posValor = m_valor.end();


	m_columnes.insert(posColumna, columna);
	m_valor.insert(posValor, valor);



}
/*
if (columna >= m_nColumnes && fila<m_nFiles)
{
m_nColumnes = columna + 1;
posColumna += m_indexFils[fila + 1]; posValor += m_indexFils[fila + 1];
m_columnes.insert(posColumna, columna);
m_valor.insert(posValor, valor);

for (int i = fila+1; i < m_indexFils.size(); i++)
m_indexFils[i]++;
}
else if (columna>= m_nColumnes && fila >=m_nFiles)
{
posColumna = m_columnes.end(); posValor = m_valor.end();
m_columnes.insert(posColumna, columna);
m_valor.insert(posValor, valor);


}



//Solo hay que realizar cambio si l numero de files es mayor al actual
if (fila > m_nFiles-1 || columna > m_nColumnes-1) {
if (columna>fila)
{
tamany = columna+1;
nVacios = columna-(m_nColumnes-1);
}
else
{
tamany = fila+1;
nVacios = fila-(m_nFiles-1);
}
m_nColumnes = tamany;
m_nFiles = tamany;


penultimoValorFil = m_indexFils[m_indexFils.size() - 2];
if (nVacios>1)
{
for (int i = 0; i < nVacios; i++)
{
m_indexFils.insert(m_indexFils.end(), penultimoValorFil);
}
}else
m_indexFils.insert(m_indexFils.end(), penultimoValorFil);



posIndexFil += (m_nFiles-1);

for (int i = 0; i <  nVacios; i++)
{
m_indexFils.insert(posIndexFil,penultimoValorFil);
}

valorFil = m_indexFils[fila];


}

if (columna >= m_nColumnes || fila >= m_nFiles) {
resize(fila, columna, valor);
}

else {		/*Aquí se conseguen las posiciones, para Insert segun
- Sea la primera fila
- Si no es la primera hay que mirar si la anterior es igual
eso significacria que hay una fila vacia.
- Despues  e mirara si el valor de la columna es mayo o menor
- El primero de cada fila tiene que ser la PosColumna mas pequeña de la fila.

valorFil = m_indexFils[fila];
if (fila != 0 && m_columnes[valorFil] == columna && m_indexFils[fila] != m_indexFils[fila - 1])
m_valor[valorFil] = valor;
else {
if (fila != 0)
{
valorFilAnt = m_indexFils[fila - 1];
if (valorFil == valorFilAnt)
{
posColumna += valorFil + 2;
posValor += valorFil + 2;
m_indexFils[fila] = valorFil;
}

else
conseguirPos(valorFil, columna, valorColumna, posColumna, posValor);
}
else
conseguirPos(valorFil, columna, valorColumna, posColumna, posValor);
//Aumentara el numero de valores


m_indexFils[m_indexFils.size() - 1] = m_indexFils[m_indexFils.size() - 1] + 1;
for (int i = fila + 1; i < m_indexFils.size() - 1; i++)
{
m_indexFils[i] = m_indexFils[i] + 1;
}
//________________________________________________

m_columnes.insert(posColumna, columna);
m_valor.insert(posValor, valor);

//________________________________________________
}


}

*/

void MatriuSparse::setVal(int fila, int columna, int valor)
{
	int valorFil, valorFilAnt, valorColumna, ultimoValorFil, valorGran, tamany;
	vector<int>::iterator posColumna = m_columnes.begin();
	vector<int>::iterator posIndexFil = m_indexFils.begin();
	vector<float>::iterator  posValor = m_valor.begin();
	int posInsert, numCopias, posComparar, cont;
	bool afegir = true;
	if (columna >= m_nColumnes || fila >= m_nFiles)
	{

		if (columna >= m_nColumnes && fila <= m_nFiles) {
			//Si la columna es mayor, significa que sempre sera la ultima posisio de la fila
			// o si ho mires aquesta es la posicio del primer numero de la seguent fila, es a dir el seguent index
			posColumna += m_indexFils[fila + 1];
			posValor += m_indexFils[fila + 1];
			m_columnes.insert(posColumna, columna);
			m_valor.insert(posValor, valor);
			//Cal copiar el penultim valor tantes vegades com calgui, perque aquesta files seran nules
			numCopias = (m_nColumnes - columna) + 1;
			posIndexFil += m_indexFils.size() - 1;
			ultimoValorFil = m_indexFils[m_indexFils.size() - 1];
			for (int i = 0; i < numCopias; i++) {
				m_indexFils.insert(posIndexFil, ultimoValorFil);
			}
			//com se ha afegit un numero cal augmenta tots els indexs
			for (int i = fila + 1; i < m_indexFils.size(); i++)
				m_indexFils[i]++;


		}
		else
		{
			//Cal copiar el penultim valor tantes vegades com calgui, perque aquesta files seran nules
			numCopias = (m_nFiles - fila) + 1;
			posIndexFil += m_indexFils.size() - 1;
			ultimoValorFil = m_indexFils[m_indexFils.size() - 1];
			for (int i = 0; i < numCopias; i++)
				m_indexFils.insert(posIndexFil, ultimoValorFil);
			//Si la fila es mayor sempre si inserira al final de m_Columan i m_Valor
			m_columnes.push_back(columna);
			m_valor.push_back(valor);
			//En aquest cal indicar que el penultim valor del m_Indez apunta al valor inserit i aumentar 1 el num de valors
			m_indexFils[fila] = m_columnes.size() - 1;
			m_indexFils[m_indexFils.size() - 1]++;

		}
		if (columna>fila)
			tamany = columna + 1;
		else
			tamany = fila + 1;
		m_nColumnes = tamany;
		m_nFiles = tamany;
		m_nElements++;
	}
	else {
		//Si el valor se afegeix dins de la matriu que ja tenim
		//Em de comprobar si aquesta vila esta buida
		posInsert = m_indexFils[fila];
		posComparar = m_indexFils[fila + 1];

		if (posComparar!=posInsert)
	
		{
			int id,id2,id3,id4;
			id = m_indexFils[fila];
			id2 = m_indexFils[fila + 1];
			id3 = m_columnes[id];
			id4= m_columnes[id2-1];
			valorFil = m_columnes[m_indexFils[fila]];
			int valorFilSiguient= m_columnes[m_indexFils[fila+1]-1];
			if (valorFil>columna)
				posInsert = m_indexFils[fila];
			else if (valorFilSiguient<columna)
			{
				posInsert = m_indexFils[fila+1];
			}
			else if (valorFil==columna)
			{
				m_valor[fila] = valor;
				afegir = false;
			}
			else {

				int abajo = m_indexFils[fila];
				int arriba = m_indexFils[fila + 1];
				if (arriba == m_nElements)
					arriba = m_columnes.size() - 1;
				int centro = 0;
				bool trobat = false;
				while (abajo <= arriba && !trobat)
				{
					centro = (arriba + abajo);
					if (centro == 0) {
						
						trobat = true;
					}
						
					else
					{
						centro = centro / 2;
						if (m_columnes[centro]<columna && m_columnes[centro + 1]>columna)
							trobat = true;
						else if (m_columnes[centro]>columna)
							arriba = centro - 1;
						else
							abajo = centro + 1;
					}
					if (abajo <= arriba && centro !=1 && centro !=0)
					{
						int a = m_columnes[centro-2];
						if (m_columnes[centro-2] == columna)
						{
							m_valor[centro - 2] = valor;
							afegir = false;
						}
					}
				}
				posInsert = centro + 1;
			}
		}
		if (afegir)
		{
			m_nElements++;
			for (int i = fila + 1; i < m_indexFils.size(); i++)
			{
				m_indexFils[i]++;
			}
			posColumna += posInsert;
			posValor += posInsert;

			m_columnes.insert(posColumna, columna);
			m_valor.insert(posValor, valor);
		}
	}
}
bool MatriuSparse::getVal(int fila, int columna, float &valor)
{
	bool potExitir = false;
	bool trobat = false;
	int pos, siguentePos;
	valor = 0;
	if (fila < m_nFiles && columna < m_nColumnes)
	{
		potExitir = true;
		pos = m_indexFils[fila];
		siguentePos = m_indexFils[fila + 1];

		if (siguentePos!=pos)
		{
			int arriba,abajo,centro,aux;
			abajo = pos;
			arriba = siguentePos;
			while (abajo <= arriba && !trobat)
			{
				centro = (arriba + abajo) / 2;
				aux = m_columnes[centro];
				if (aux == columna) {
					trobat = true;
					valor = m_valor[centro];
				}
				else
					if (aux> columna)
						arriba = centro - 1;
					else
						abajo = centro + 1;
			}

		}
		/*
		if (pos == m_indexFils[m_indexFils.size() - 2])
		siguentePos = m_columnes.size();
		else
		siguentePos = m_indexFils[fila + 1];
		for (int j = pos; j < siguentePos; j++)
		{
		if (m_columnes[j] == columna)
		{
		valor = m_valor[j];
		}
		}
		*/


	}

	return potExitir;
}
/*
void CSR::ordenar()
{
for (int j = 0; j< m_vecFilaX.size() - 1; j++)
{
for (int i = 0; i < m_vecFilaX.size() - 1; i++)
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
void CSR::swap(vector<float>& vec, int posActual)
{
float aux = vec[posActual + 1];
vec[posActual + 1] = vec[posActual];
vec[posActual] = aux;
}
void CSR::liberarMemoria()
{
// MOD
////eliminar columnas
//for (int i = 0; i < m_nFiles; i++)
//	delete[] m_matriu[i];
////eliminar filas
//delete[] m_matriu;
}
void CSR::resize(int nFilas, int nCol)
{
bool resizeMayor = false;

if ((nFilas > m_nFiles) || (nCol > m_nColumnes))
resizeMayor = true;

CSR auxMatriu(*this);
liberarMemoria();
inicializarMatriz(nFilas, nCol);

if (resizeMayor) {
//Copiamos el contenido de la matriz enviada a este objeto
for (int i = 0; i < auxMatriu.m_nFiles; i++)
{
for (int j = 0; j < auxMatriu.m_nColumnes; j++)
{
//m_matriu[i][j] = auxMatriu.m_matriu[i][j];
}
}
}
else {
//Copiamos el contenido de la matriz enviada a este objeto
for (int i = 0; i < nFilas; i++)
{
for (int j = 0; j < nCol; j++)
{
//m_matriu[i][j] = auxMatriu.m_matriu[i][j];
}
}
}
}
void CSR::transpose()
{
CSR auxMatriu(*this);
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
//_______________________________________________________________________
*/
#pragma endregion

#pragma region Operators

//--------------------------OPERADORED---------------------------------------

MatriuSparse& MatriuSparse::operator=(const MatriuSparse& matriu)
{
	inicializarMatriz(matriu.m_nFiles, matriu.m_nColumnes);
	//Copiamos el contenido de la matriz enviada a este objeto
	for (int i = 0; i < m_nColumnes; i++)
	{
		m_columnes[i] = matriu.m_columnes[i];
		m_valor[i] = matriu.m_valor[i];
		m_indexFils[i] = matriu.m_indexFils[i];
	}
	m_nElements = matriu.m_nElements;
	return *this;
}

/*
pos = m_indexFils[i];
if (i != vect.size())
siguentePos = m_indexFils[i + 1];
else
siguentePos = m_valor.size();
resultat = 0;
for (int j = pos; j < siguentePos; j++)
{
resultat += m_valor[j] * vect[i];
}
vecAux.push_back(resultat);
*/
MatriuSparse  MatriuSparse::operator*(float num)
{
	int valor = 0;
	int resulatat;
	MatriuSparse mAux(*this);
	for (int i = 0; i < m_valor.size(); i++)
	{
		valor = mAux.m_valor[i];
		resulatat = valor * num;
		mAux.m_valor[i] = resulatat;
	}
	return mAux;
}
MatriuSparse  MatriuSparse::operator/(float num)
{
	int valor = 0;
	int resulatat;
	MatriuSparse mAux(*this);

	for (int i = 0; i < m_valor.size(); i++)
	{
		valor = mAux.m_valor[i];
		resulatat = valor / num;
		mAux.m_valor[i] = resulatat;
	}
	return mAux;
}
vector<float> MatriuSparse::operator*(vector<float> vect)
{
	vector<float> vecAux;
	try
	{
		int numFila = 0;
		int posFila = 0;
		int pos, siguentePos, posVector, cont;
		float resultat = 0.0f;

		if (m_nColumnes == vect.size())
		{
			for (int i = 0; i < m_indexFils.size()-1; i++)
			{
				pos = m_indexFils[i];
				siguentePos = m_indexFils[i + 1];


				for (int j = pos; j < siguentePos; j++)
				{
					resultat += m_valor[j] * vect[i];
				}

					vecAux.push_back(resultat);
					resultat = 0;


			}
		}


		return vecAux;
	}
	catch (const std::exception&)
	{
		return vecAux;
	}
	
}
/*
MatriuSparse MatriuSparse::operator+(const Matriu& m)
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
return CSR();
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
*/
ostream& operator<<(ostream& out, MatriuSparse& m)
{
	// volveremos, a valorar si incrementamos filas y columnas aqui o por defecto
	out << "MATRIU DE FILES: " << m.m_nFiles << " : COLUMNES: " << m.m_nColumnes << endl;
	int pos, siguentePos;
	for (int i = 0; i < m.m_indexFils.size() - 1; i++)
	{
	
		pos = m.m_indexFils[i];
		siguentePos = m.m_indexFils[i + 1];

		if (pos != siguentePos)
		{
			out << "VALORS FILA:" << i << "(COL:VALOR)" << endl;		
				for (int j = pos; j < siguentePos; j++)
				{
					out << "(" << m.m_columnes[j] << " : " << m.m_valor[j] << ") ";
				}
				out << endl;
		}
	}
	out << "MATRIUS" << endl;
	out << "VALORS" << endl;
	out << "(";
	for (int i = 0; i < m.m_columnes.size(); i++)
	{
		out << m.m_valor[i] << "  ";
	}
	out << ")" << endl;
	out << "COLS" << endl;
	out << "(";
	for (int i = 0; i < m.m_columnes.size(); i++)
	{
		out << m.m_columnes[i] << "  ";
	}
	out << ")" << endl;
	out << "INIFILA" << endl;
	out << "(";
	int nextValue;
	for (int i = 0; i < m.m_indexFils.size() - 1; i++)
	{
		pos = m.m_indexFils[i];
		siguentePos = m.m_indexFils[i + 1];
		if (pos != siguentePos) 
			out << "[ " << i << " : " << m.m_indexFils[i] << " ] ";
	}
	out << " [Num Elems:" << m.m_nElements << "]";
	out << " )" << endl;
	return out;
}
//_____________________________________________________________________

#pragma endregion
