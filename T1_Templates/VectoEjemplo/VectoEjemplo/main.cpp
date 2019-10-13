#include "main.h"
#include<iostream>
#include <vector>
#include "Map.h"
using namespace std;

int main()
{
	
	Map<string, int> m;
	
	m.afegeix("Zoe", 10);
	m.afegeix("Andrea", 30);
	m.afegeix("Esmeralda", 5);
	m.afegeix("Bananro", 10);
	m.afegeix("Zoe", 10);

	
	return 0;
	
	
}