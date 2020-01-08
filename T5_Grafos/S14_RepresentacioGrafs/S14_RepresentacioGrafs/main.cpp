#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include "graf.h"

using namespace std;


int main()
{
	// EXEMPLE TASQUES
	int numNodes = 11;

	vector<string> nomsNodes;
	nomsNodes.resize(numNodes);
	nomsNodes = {"Tasca 1","Tasca 2","Tasca 3","Tasca 4","Tasca 5","Tasca 6","Tasca 7","Tasca 8","Tasca 9","Tasca 10","Tasca 11"};

	vector<vector<int>> arestes;
	arestes = { {0,1},{0,2},{0,3},{2,1},{2,3},{1,4},{1,5},{3,5},{6,3},{5,4},{5,6},{4,7},{4,8},{6,8},{6,9},{7,8},{8,9},{7,10},{8,10},{9,10} };

	vector<int> pesos = {5,5,5,7,7,10,10,4,4,6,6,3,3,9,9,1,8,2,8,4}; //20 pesos
	
	Graf gP(nomsNodes,arestes,pesos,true);

	cout << "mostra graf dirigit ponderat:" << endl;
	gP.mostra();
	system("PAUSE");


	// GRAUS d'un node
	vector<int> graus_in;
	graus_in.resize(numNodes);
	vector<int> graus_out;
	graus_out.resize(numNodes);

/*	for (int i = 0; i < numNodes; i++)
	{
		graus_in[i] = gP.grauInNode(nomsNodes[i]);
		graus_out[i] = gP.grauOutNode(nomsNodes[i]);
	}

	cout << "mostra graus de tots els nodes in:" << endl;
	for (int i = 0; i < numNodes; i++)
		cout << graus_in[i] << " ";
	cout << endl;

	cout << "mostra graus de tots els nodes out:" << endl;
	for (int i = 0; i < numNodes; i++)
		cout << graus_out[i] << " ";
	cout << endl;
	system("PAUSE");

	// CAMINS d'una tasca a una altra
	gP.camins("Tasca 2", "Tasca 9");
	*/

	return 0;
}