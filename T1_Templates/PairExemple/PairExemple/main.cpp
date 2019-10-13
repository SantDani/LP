#include "cerca.h"
#include <iostream>

using namespace std;
int main()
{
	int const CANT_MAX = 3;
	pair<int, string> p0;//constructor por defecto
	pair<int, string> p1 (0, "Ivan"); // consturctor con valores
	pair<int, string> p2(p1);//constuctor copia

	pair<int, string> vector[CANT_MAX] = { p0, p1, p2 };
	mostrar(vector, CANT_MAX);



	pair<string, string> p3("NO SERGIO! es", "Spiderman en 4");
	pair<string, string> p4("El peluca", "SAPE"); 
	pair<string, string> p5("k mas ve", "Pete seguro");

	pair<string, string> vectorSting[CANT_MAX] = { p3, p4, p5 };
	mostrar(vectorSting, CANT_MAX);
	
	
	return 0;
}
