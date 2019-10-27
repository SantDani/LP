#include <list>
#include <string>
#include <stack>
#include <iostream>
#include "main.h"
using namespace std;




int main() 
{
	list<int> l = { 9,8,7,6,5,4,3,2,1 };

	list<string> lNom = { "Anna","Carles","David","Francesc","Joan","Jordi","Marc","Marta","Monica","Silvia" };

	invertirOrden(lNom);
	
	return 0;
}

void invertirOrden(std::list<std::string>& lNom)
{
	stack<string> pila;

	list<string>::iterator itLNom;
	list<string>::iterator itEndLNom;
	itLNom = lNom.begin();
	itEndLNom = lNom.end();

	while (!(itEndLNom == itLNom))
	{
		pila.push(*itLNom);
		itLNom++;
	}

	itLNom = lNom.begin();
	while (!pila.empty())
	{
		cout << pila.top() << "\t";
		pila.pop();
	}
}

bool cerca(list<int> &llista, int valor)
{
	list<int>::iterator it;
	
	if (llista.empty())
	{
		return false;
	}
	//else if( it == )
}

void invertirOrdre(list<int>& llista)
{

}

