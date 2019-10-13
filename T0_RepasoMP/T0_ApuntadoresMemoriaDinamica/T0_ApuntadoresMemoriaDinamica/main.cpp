#include <iostream>
#include "Racional.h"
#include "Conjunt.h"
#include "main.h"

using namespace std;


int main()
{
	Racional* p; //Guardamos una direccion de memoria de la clase Racional 

	Racional r(1, 5);

	//guardar memoria para un apuntador con new
	p = new Racional; //podemos utilizar cualquier constructor
	//liberar memoria
	delete p;
	return 0;
}