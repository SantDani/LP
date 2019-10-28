//Sobrecarga de operator<<
//1 En la clase parte publica
friend ostream& operator<<(ostream& out, Matriu& m);
//hacer su definicion correspondiente
ostream& operator<<(ostream& out, Matriu& m)
{
	cout << "MATRIU DE (FILES: " << m.m_nFiles << " COLUMNES: " << m.m_nColumnes << " )" << endl;

	for (int i = 0; i < m.m_vecX.size(); i++)
	{
		out << "( " << m.m_vecX[i] << " :: " << m.m_vecY[i] << " :: " << m.m_vecValue[i] << " )" << endl;
	}
	return out;
}
// ----------------- Lectura ficheros ----------------------
#include<fstream>

void leerFichero(nombreFichero)
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

			miFichero >> fila >> col >> valor;

			if (m_nFiles < fila)
				m_nFiles = fila;
			if (m_nColumnes < col)
				m_nColumnes = col;

			m_vecX.push_back(fila);
			m_vecY.push_back(col);
			m_vecValue.push_back(valor);
			i++;
		}
		miFichero.close();
	}
	else
		cout << "Error al leer el fichero" << endl;
}
