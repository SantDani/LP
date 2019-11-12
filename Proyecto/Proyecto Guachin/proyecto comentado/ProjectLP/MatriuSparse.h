#pragma once
#include <vector>
#include <cmath>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
using namespace std;
///<summary>
///Clase principal de la aplicación.
///</summary>
///<remarks>
///Matriz de adyacencia que nos permite guardar grafos de dispersión
///</remarks>
class MatriuSparse
{
public:
	//CONTRUCTORS
	///<summary>
	///Contructor.
	///</summary>
	MatriuSparse();
	///<summary>
	///Destructor.
	///</summary>
	~MatriuSparse();
	///<summary>
	///Contructor por paramentros.
	///</summary>
	///<param name="nomFitxer">
	///Nombre del fichero donde se encuetra los datos de nuestra matriz.
	///</param>
	MatriuSparse(string nomFitxer);
	///<summary>
	///Contructor por paramentros.
	///</summary>
	///<param name="nFiles">
	///Numero de filas para iniciañizar la matriz.
	///</param>
	///<param name="nCol">
	///Numero de columnas para iniciañizar la matriz.
	///</param>
	MatriuSparse(int nFiles, int nCol);
	///<summary>
	///Contructor de copia.
	///</summary>
	///<param name="m">
	///Matriz de la cual copiaremos sus parametros.
	///</param>
	MatriuSparse(const MatriuSparse& m);
	//GETTERS 
	///<summary>
	///Devuelve el numero de filas.
	///</summary>
	///<returns>
	///Numero de filas que contiene nuestra matriz.
	///</returns>
	int getNFiles() const { return m_nFiles; }
	///<summary>
	///Devuelve el numero de columnas.
	///</summary>
	///<returns>
	///Numero de columnas que contiene nuestra matriz.
	///</returns>
	int getNColumnes() const { return m_nColumnes; }
	///<summary>
	///Devuelve el numero de elementos de contiene nustra matriz.
	///</summary>
	///<returns>
	///Devuelve el numero de elementos de contiene nustra matriz.
	///</returns>
	int getNElements() const { return m_nElements; }
	//METHODS
	/// <summary>
	/// Método para inicializar los vectores a cero e igualar el numero de filas 
	/// y columnas que se pasan por parámetro.
	/// </summary>
	/// <param name="nCol">Numero de filas.</param>
	/// <param name="nFiles">Numero de columnas.</param>
	void inicializarMatriz(int nFiles, int nCol);
	/// <summary>
	/// Método para inicializar losvectores.
	/// </summary>
	/// <param name="nCol">Numero de filas.</param>
	/// <param name="nFiles">Numero de columnas.</param>
	void init(int nFiles, int nCol);
	///<summary>
	///Añadirá el valor en la posición indicada.
	///</summary>
	///<remarks>
	///Método setVal (fila, col, valor) que añadirá el valor (si no es 0) a la posición (fila, col) de
	///la estructura.Este método añadirá tantas filas y columnas como sea necesario si la
	///posición(fila, col) es mayor que los márgenes de la matriz actual, y modificará el tamaño
	///de la matriz en este caso.
	///</remarks>
	///<param name="fila">
	///Fila donde se realizará la inserción.
	///</param>
	///<param name="columna">
	///Columa donde se realizará la inserción.
	///</param>
	///<param name="valor">
	///Valor que se inserirá.
	///</param>
	void setVal(int fila, int columna, int valor);
	///<summary>
	///Retorna el valor segun la fila y la columna.
	///</summary>
	///<remarks>
	///Método getVal (fila, col, valor) que devolverá un booleano indicando si la posición (fila, col) es
	///una posición de la matriz.En caso de ser una posición de la matriz, si encuentra el valor lo
	///devolverá a un parámetro por referencia "valor" y si no hay ningún valor guardado en
	///aquella posición devolverá a un parámetro por referencia "valor" un 0.
	///</remarks>
	///<param name="fila">
	///Fila de la matriz donde se encuetra el valor.
	///</param>
	///<param name="columna">
	///Columna de la matriz donde se encuetra el valor.
	///</param>
	///<param name="valor">
	///Parametro donde se guardará el valor si se encuentra.
	///</param>
	///<returns>
	///Devuelve un booleano si el valor buscado podría estar dentro de la matriz.
	///</returns>
	bool getVal(int fila, int columna, float& valor);
	//OVERLOADS
	///<summary>
	///Sobrecarga Operador * que multiplica los valores de la matriz por un numero real.
	///</summary>
	///<remarks>
	///Una sobrecarga del operador * de multiplicación para que reciba como parámetro un nº
	///real y devuelva el resultado de multiplicar todos los valores de la matriz por este valor que
	///se pasa como parámetro.
	///</remarks>
	///<param name="num">
	///Numero real por el cual se multiplicara los valores de la matriz.
	///</param>
	///<returns>
	///Matriz con los valores multiplicados por el numero real.
	///</returns>
	MatriuSparse operator*(float num);
	///<summary>
	///Sobrecarga Operador * que multiplica los valores de la matriz por un vector de floats.
	///</summary>
	///<remarks>
	///Una sobrecarga del operador * de multiplicación para que reciba como parámetro un
	///vector de floats de la STL y devuelva otro vector del mismo tamaño, que será el resultado.
	///</remarks>
	///<param name="vect">
	///Vector de floats por el cual se multiplicara la matriz.
	///</param>
	///<returns>
	///Matriz con los resultados de la multiplicación.
	///</returns>
	vector<float> operator*(vector<float> vect);
	///<summary>
	///Sobrecarga Operador / que divide los valores de la matriz por un numero real.
	///</summary>
	///<remarks>
	///Una sobrecarga del operador / de división para que reciba como parámetro un nº real y
	///devuelva el resultado de dividir todos los valores de la matriz por este valor que se pasa
	///como parámetro.
	///</remarks>
	///<param name="num">
	///Numero real por el cual se divide los valores de la matriz.
	///</param>
	///<returns>
	///Matriz con los valores dividos por el numero real.
	///</returns>
	MatriuSparse operator/(float num);
	///<summary>
	///Sobrecarga Operador copia que copiara la matriz pasada por paramentro.
	///</summary>
	///<param name="m">
	///Matriz del cual se realizará la copia.
	///</param>
	///<returns>
	///Matriz con las variables copias.
	///</returns>
	MatriuSparse& operator=(const MatriuSparse& m);
	///<summary>
	///Metodo que devuelve un oestream con los valores de la matriz.
	///</summary>
	///<param name="out">
	///La salida.
	///</param>
	///<param name="m">
	///Matriz de cual realizaremos la salida.
	///</param>
	///<returns>
	///oestream de los valores de la matriz.
	///</returns>
	friend ostream& operator<<(ostream& out, MatriuSparse& m);
private:
	void resize(const int medidaReal,const int medida);
	int m_nFiles;
	int m_nColumnes;
	int m_nElements;
	vector<float> m_valor;
	vector<int> m_columnes;
	vector<int> m_indexFils;
};

