#include <iostream>
using namespace std;
#include "Hash.h"

int main()
{
	try 
	{
		//CODI INICIAL
		//Hash h(20);
		Hash h;
		const int MAXELEMENTS = 6;
		pair<string, string> vEntrada[MAXELEMENTS] = { pair<string,string>("Hola", "Es una salutacio."),
		pair<string,string>("Adeu","Es un comiat."),
		pair<string,string>("Dia", "Es un periode de 24 hores."),
		pair<string,string>("Mes", "Es un periode de entre 28 i 31 dies."),
		pair<string,string>("Any", "Es un periode de 12 mesos."),
		pair<string,string>("ornitorinc", "Animal."),
		};

		for (int i = 0; i < MAXELEMENTS; i++)
		{
			h.insert(vEntrada[i].first, vEntrada[i].second);			
		}

		cout << "=====DICCIONARI=====" << endl;
		cout << h;

		cout << "Definicio de caleidoscopi es: " << h["caleidoscopi"] <<endl;
		cout << "Definicio d'eina es: " << h["eina"] <<endl;

		cout << "=====DICCIONARI DESPRES CERCA=====" << endl;
		cout << h;
		
		h.esborra("Mes");
		h.esborra("taula");
		cout << "Definicio de Any es: " << h["Any"] << endl;
		cout << "=====DICCIONARI DESPRES ESBORRAT=====" << endl;
		cout << h;
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	catch (std::out_of_range)
	{
		cout << "Intentes accedir a una posició fora del vector";
	}
	return 0;
}