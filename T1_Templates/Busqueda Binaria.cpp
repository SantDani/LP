//Busqueda Binaria

#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	
	
	return 0;
}


template <class T>
bool cercaBinaria(T vector[], const T& valor, int nElements)
{

	int mitad, i;
	int inf = 0;
	int sup = nElements - 1;
	i = 0;

	bool encontrado = false;


	while ((inf <= sup))
	{
		mitad = (inf + sup) / 2;
		if (vector[mitad] == valor)
		{
			encontrado = true;
			return encontrado;
		}
		else
			if (vector[mitad] > valor)
			{
				sup = mitad - 1;
			}
			else //(vector[mitad] < valor) 
			{
				inf = mitad + 1;
			}
		i++;
	}
	return encontrado;
}