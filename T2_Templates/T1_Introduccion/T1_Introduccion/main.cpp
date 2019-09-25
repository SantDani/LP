#include "Pila.h"
#include <iostream>

using namespace std;

int main()
{
	Pila<int> p;
	
	for (int i = 0; i < 10; i++)
	{
		p.push(i);
	}
	p.pop();
	cout << "El primer element de la pila es: " << p.top() << endl;

	return 0;

}