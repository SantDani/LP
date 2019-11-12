#include "MatriuSparse.h"

using namespace std;

//--------------------------CONSTRUCTORS-------------------------------
#pragma region CONSTRUCTORS
MatriuSparse::~MatriuSparse()
{
}
MatriuSparse::MatriuSparse()
{
	try
	{
		m_columnes.resize(0);
		m_valor.resize(0);
		m_indexFils.resize(0);
		m_nColumnes = 0;
		m_nFiles = 0;
	}
	catch (std::bad_alloc)
	{
		cout << "Comment ==> error allocatant memoria:" << endl;
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

}
MatriuSparse::MatriuSparse(int nFiles, int nColumnes)
{
	inicializarMatriz(nFiles, nColumnes);
}
MatriuSparse::MatriuSparse(const MatriuSparse& matriu)
{
	try
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
	catch (std::bad_alloc)
	{
		cout << "Comment ==> error allocatant memoria:" << endl;
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

}
MatriuSparse::MatriuSparse(string nomFitxer)
{
	try
	{
		ifstream miFichero; //Declaro el objeto ifstream para poder leer el fichero
		miFichero.open(nomFitxer);


		if (miFichero.is_open())
		{
			int filaAux = 0, tamany = 0, addIndex = 0, fila, col, contElements = 0;
			inicializarMatriz(0, 0);
			m_indexFils.push_back(0);//El primer valor de index siempre es 0

			miFichero >> fila >> col;//Leer la fila y la columna del fichero
			while (!miFichero.eof()) // mientras no sea el final del fichero
			{
				addIndex = fila - filaAux;//Es para saber si se añader una nueva linea, si addIndex a mayo que 1 significa que hay filas en blanco.
				if (addIndex != 0)
				{
					filaAux = fila;
					for (int i = 0; i < addIndex; i++)//Se realiza un for, si se pasa de la fila 5 a la 10 significa que hay filas en blanco.
						m_indexFils.emplace_back(contElements);
				}
				if (tamany < fila)//Para saber el tamaño de la matriz
					tamany = fila;
				if (tamany < col)
					tamany = col;
				m_columnes.push_back(col);//Añadiendo la columna al vector m_Columna.
				m_valor.push_back(1);//Añadiendo un 1 al vector m_Valor.
				contElements++;//Sumamos los elementos totales.
				miFichero >> fila >> col;
			}
			m_nElements = contElements;//Igualamos los elementos totales
			m_indexFils.push_back(contElements);
			miFichero.close();
			m_nFiles = tamany + 1;
			m_nColumnes = tamany + 1;
		}
		else
			cout << "Error al leer el fichero" << endl;
	}
	catch (std::bad_alloc)
	{
		cout << "Comment ==> error allocatant memoria:" << endl;
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}


}
//_____________________________________________________________________
#pragma endregion
//----------------------------METHODS-----------------------------------
#pragma region METHODS
void MatriuSparse::init(int nFiles, int nCol)
{
	inicializarMatriz(nFiles, nCol);
}
void MatriuSparse::inicializarMatriz(int nFiles, int nCol)
{
	try
	{
		m_nFiles = nFiles;
		m_nColumnes = nCol;

		m_columnes.resize(0);
		m_valor.resize(0);
		m_indexFils.resize(0);
	}
	catch (std::bad_alloc)
	{
		cout << "Comment ==> error allocatant memoria:" << endl;
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

}
void MatriuSparse::resize(const int medidaReal,const int  medida)
{
	try
	{
		vector<int>::iterator posIndexFil = m_indexFils.begin();
		int numFilasVacias, ultimoValorIndexFil;
		numFilasVacias = (medidaReal - medida) + 1;//Las filas que serán añadidas
		posIndexFil += m_indexFils.size() - 1;//Posición
		ultimoValorIndexFil = m_indexFils[m_indexFils.size() - 1];//Último Valor
		for (int i = 0; i < numFilasVacias; i++)
			m_indexFils.insert(posIndexFil, ultimoValorIndexFil);
	}
	catch (std::bad_alloc)
	{
		cout << "Comment ==> error allocatant memoria:" << endl;
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

}
//Este metodo es el más complejo 
/*
Lo primero que realiza es mirar si la inserción está dentro del rango:
	- Si no esta dentro de rango hay dos opciones:
		+ Que la columna esté furea de rango pero la fila este dentro
			· Si pasa este lo se realiza es con el index mirar en que posición se añade.
			· Se realiza un resize que consiste en replicar el ultimo valor"filas nulas"
			· I augmentar los valores del indice ya que se desplazan en uno.
		+ Que la fila esté fuera de rango y será indiferente si la columna tambien lo está o no
			· Aquí siempre se añade al final del vector Columna y Valor.
			· Se realiza el resize.
			· Y el penultimo valo del vector Index fil indica la posicion del valor añadido y se augmenta el numero de valores
		Al final hay que cambiar el tamaño de nuestro array.
	-"Else" Que el valor que vamos a añadir esté dentro del rango:
		+Lo primero es mirar si la fila no esta nula, de ser así sabiendo la fila tenemos que saver en que poscion de Vector Columna irá.
		 Mirando el vector IndexFils sabremos el rango donde podria ir
			· Si la columna de inserción es más pequeña de la que nos ha dado el Index fil significa que va al principio de la fila
			· Si la columna de inserción es la más gran de fila irá al final.
			· Si la columna de inserción es igual significa que el valor ya existe por lo que hay cambiar el valor
			· Si no es ninguna realizaremos un busqueda binaria de la posición adecuada
			  cabe la posivilidad que el sitio que encontremos ya exita un valor por lo que en vez de añadir un nuevo valor 
			  cambiamos el que ya existe.
		+En el caso que sea en una fila nula es más facil sabemos que ira en la posicion m_IndexFil[fila]
		 es decir ira al principio de la fila
	 Al final aumentamos el numero de elemento siempre y cuando se realize un inserción y no un update, como
	 se ha añadido un valor augementamos los valores del vector IndexFil.
		  */
void MatriuSparse::setVal(int fila, int columna, int valor)
{
	try
	{
		int valorFil, valorFilAnt, valorColumna, ultimoValorFil, tamany, posInsert, numCopias, posComparar;
		vector<int>::iterator posColumna = m_columnes.begin();
		vector<int>::iterator posIndexFil = m_indexFils.begin();
		vector<float>::iterator  posValor = m_valor.begin();

		bool afegir = true;

		if (columna >= m_nColumnes || fila >= m_nFiles)
		{
			//Miramos si la columna donde queremos insertar está fuera de los margenes pero la fila no
			if (columna >= m_nColumnes && fila <= m_nFiles) {
				//Si solo la columna esta fuera el valor que se inserta siempre esta al final de la
				// fila indicada.
				//----------INSERT----------------
				posColumna += m_indexFils[fila + 1];
				posValor += m_indexFils[fila + 1];
				m_columnes.insert(posColumna, columna);
				m_valor.insert(posValor, valor);
				//------------------------------------
				//Hay que realizar un "resize" de la matriz 
				//Eso significa añadir filas con los "valores en cero"
				//Esto se hace repitiendo el ultimo valor.
				resize(m_nColumnes, columna);

				//Como se ha añadido un valor hemos de incrementar los Indices.
				for (int i = fila + 1; i < m_indexFils.size(); i++)
					m_indexFils[i]++;
			}
			else
			{
				//Si la fila se encuentra fuera del margen es diferente.
				//El valor siempre se insertará al final de los vectores Columna y Valor
				//----------INSERT------------
				m_columnes.push_back(columna);
				m_valor.push_back(valor);
				//-------------------------
				//Hay que realizar un "resize" de la matriz 
				//Eso significa añadir filas con los "valores en cero"
				//Esto se hace repitiendo el ultimo valor.
				resize(m_nFiles, fila);

				m_indexFils[fila] = m_columnes.size() - 1;//Hay que indicar que fila donde inserimos apunta hacia la ultima posición del vector Columna valdria con el vector Valor
				m_indexFils[m_indexFils.size() - 1]++;// Tambien aumentamos en numero de valores.

			}
			//Al final redimencionamos la matriz y aumentamos el numero de valores.
			if (columna>fila)
				tamany = columna + 1;
			else
				tamany = fila + 1;
			m_nColumnes = tamany;
			m_nFiles = tamany;
			m_nElements++;
		}
		else {
			//Si el valor esta dentro la matriz
			posInsert = m_indexFils[fila];
			posComparar = m_indexFils[fila + 1];

			if (posComparar != posInsert)//Miramos si la fila no esta vacía
			{
				valorFil = m_columnes[m_indexFils[fila]];
				int valorFilSiguient = m_columnes[m_indexFils[fila + 1] - 1];// con esto miramos la ultima posición de lafila


				if (valorFil>columna)//Mira si la columna que insertaremos es la primera de la fila
					posInsert = m_indexFils[fila];//La posición donde insertaremos sera la que indique el indice
				else if (valorFilSiguient<columna)//Aquí miramos si insertamos en la ultima posición de la fila 
					posInsert = m_indexFils[fila + 1];
				else if (valorFil == columna)//Aquí nos aseguramos si donde vamos a añadir ya existe un valor
				{
					m_valor[fila] = valor;//Si ya exite lo cambiamos directament
					afegir = false;//Por lo que no se añader ningun nuevo valor.
				}
				else {
					//Aquí se entra la columna se encuentra en medio de la fila 
					//Se realizara un inserción con metodo binario

					int abajo = m_indexFils[fila];
					int arriba = m_indexFils[fila + 1];
					if (arriba == m_nElements)//Si arriba es igual que el numero de valores, realmente arriba tiene que ir hasta el fianl del vector Columna
						arriba = m_columnes.size() - 1;
					int centro = 0;
					bool trobat = false;
					while (abajo <= arriba && !trobat)
					{
						centro = (arriba + abajo);
						if (centro == 0) {//Este caso es si las primeras fila estan nula, si intentaramos dividir entre 0"petaria"
							trobat = true;
						}
						else
						{
							centro = centro / 2;
							if (m_columnes[centro]<columna && m_columnes[centro + 1]>columna)//si la columan donde queremos inserta es mas grande que el anterior y mas pequeño que la siguiente columna ya hemos encontrado la posicion
								trobat = true;
							else if (m_columnes[centro]>columna)//La columana donde queremos inserta aun se encuentra "demasiado hacia la derecha de donde tiene que ir"
								arriba = centro - 1;
							else//La columana donde queremos inserta aun se encuentra "demasiado hacia la izquierda de donde tiene que ir"
								abajo = centro + 1;
						}
						if (abajo <= arriba && centro != 1 && centro != 0)//Este if es por si donde vamos a inserta el VALOR ya hay un valor previamente
						{// Si pasa esto no se añade sino se cambia el valor que hay por uno nuevo
							int a = m_columnes[centro - 2];
							if (m_columnes[centro - 2] == columna)
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
	catch (std::bad_alloc)
	{
		cout << "Comment ==> error allocatant memoria:" << endl;
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}
//Este metodo realiza una busqueda binaria del valor que bucamos.
bool MatriuSparse::getVal(int fila, int columna, float &valor)
{
	try
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

			if (siguentePos != pos)
			{
				int arriba, abajo, centro, aux;
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
		}

		return potExitir;
	}
	catch (std::bad_alloc)
	{
		cout << "Comment ==> error allocatant memoria:" << endl;
		return false;
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
		return false;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		return false;
	}
	
}

#pragma endregion
#pragma region Operators

//--------------------------OPERADORED---------------------------------------

MatriuSparse& MatriuSparse::operator=(const MatriuSparse& matriu)
{
	try
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
	catch (std::bad_alloc)
	{
		cout << "Comment ==> error allocatant memoria:" << endl;
		return *this;
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
		return *this;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		return *this;
	}

}

MatriuSparse  MatriuSparse::operator*(float num)
{
	MatriuSparse mAux(*this);
	try
	{
		int valor = 0;
		int resulatat;
		for (int i = 0; i < m_valor.size(); i++)
		{
			valor = mAux.m_valor[i];
			resulatat = valor * num;
			mAux.m_valor[i] = resulatat;
		}
		return mAux;
	}
	catch (std::bad_alloc)
	{
		cout << "Comment ==> error allocatant memoria:" << endl;
		return mAux;
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
		return mAux;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		return mAux;
	}

}
MatriuSparse  MatriuSparse::operator/(float num)
{
	MatriuSparse mAux(*this);
	try
	{
		int valor = 0;
		int resulatat;
	

		for (int i = 0; i < m_valor.size(); i++)
		{
			valor = mAux.m_valor[i];
			resulatat = valor / num;
			mAux.m_valor[i] = resulatat;
		}
		return mAux;
	}
	catch (std::bad_alloc)
	{
		cout << "Comment ==> error allocatant memoria:" << endl;
		return mAux;
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
		return mAux;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		return mAux;
	}

}
//Este metodo coge el rango del Vector columna que corresponda a la fila y lo multiplica por el vector.
vector<float> MatriuSparse::operator*(vector<float> vect)
{	
	vector<float> vecAux;
	try
	{
		int pos, siguentePos;
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
	catch (std::bad_alloc)
	{
		cout << "Comment ==> error allocatant memoria:" << endl;
		return vecAux;
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
		return vecAux;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		return vecAux;
	}
	
}
ostream& operator<<(ostream& out, MatriuSparse& m)
{

	try
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
	catch (std::bad_alloc)
	{
		cout << "Comment ==> error allocatant memoria:" << endl;
		return out;
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
		return out;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		return out;
	}
	
}
//_____________________________________________________________________

#pragma endregion
