#include<iostream>

#include<fstream>//libreria de ficheros
#include<string>// para que funcione getLine()

using namespace std;

//Funciones: PROTOTIPO
void crearSubtituirFichero();
void addText(string fichero);
string addTextByConsole();
void lecturaME(string urlFichero);
void lectura();

string const URL_FICHERO = "ficheros/FicheroPrueba.txt";
int main()
{
	//crearSubtituirFichero();
	
	addText(URL_FICHERO);
	//lecturaME(URL_FICHERO);
	lectura();
	system("pause");
	return 0;
}
/*Crear el fichero o substituir*/
void crearSubtituirFichero()
{

	ofstream archivo; //ouput: o- fstream:
	string nombreArchivo;
	string extension = ".txt";

	/*cout << "que nombre quiere poner al fichero? " << endl;
	cin >> nombrearchivo ;*/
	nombreArchivo = "FicheroPrueba";
	// SI el archivo existe lo remplaza
	// SI NO Existe crea un archivo
	////Para guardar los ficheros en una capeta, esta hay que crearla primero.
	archivo.open( "ficheros/"+ nombreArchivo + extension, ios::out); // Abriendo archivo

	if (archivo.fail())
	{
		cout << "No se pudo crear/abrir el archivo" << endl;
		exit(1);
	}

	archivo << "k mas ve, wey no mms! esta cosa se prendio" << endl;
	archivo << "k mas ve, wey no mms! esta cosa se prendio" << endl;
	archivo << nombreArchivo << endl;
	archivo.close();
}

void addText(string urlFichero) 
{	
	//abrimos el fichero en modo add
	ofstream archivo(urlFichero, ios::app);

	if (archivo.fail())
	{
		cout << "Error al abrir el fichero para add texto";
		exit(1);
	}
	if (archivo)
	{
		archivo << "Add text" << endl;
		archivo << addTextByConsole() << endl;
		archivo.close();
	}

}

string addTextByConsole()
{
	string texto;
	cout << " Texto a add?";
	getline(cin, texto);

	return texto;
}

void lecturaME(string urlLetura)
{
	ifstream archivo(URL_FICHERO);
	char contendioArchivo[128];
	//Abrir el fichero en modo lectura
	//archivo.open(URL_FICHERO, ios::in);

	if (archivo.fail())
	{
		cout << "Error al abrir achivo" << endl;
		exit(1);
	}
	//Mientras no sea el final del archivo
	while (!archivo.eof())
	{
		archivo.getline(contendioArchivo, 128);
		cout << contendioArchivo << endl;
	}
}

void lectura()
{
	ifstream archivo;
	string texto;
	//abrir archivo en modo lectura
	archivo.open(URL_FICHERO, ios::in);

	if (archivo.fail())
	{
		cout << "Error al abrir fichero";
		exit(1);
	}
	// mientras no sea el final del archivo
	while (!archivo.eof())
	{
		getline(archivo, texto);
		cout << texto << endl;
	}

	archivo.close();
}