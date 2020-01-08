#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include "graf.h"
//#include "GrafList.h"

using namespace std;


void main()
{
	int numNodes = 53;

	vector<string> noms_nodes;
	noms_nodes.resize(numNodes);
	noms_nodes = {"Pl. Sants","Hostafr.","Esp.","Roc.","Urgell","Univ.","Cat.","Urq.","Triomf","Marina","Glòries","Clot","Navas","Sagrera",
				 "Paral·lel","St. Ant.","Pg. Gràcia","Tetuan","Monumental","S. Família","Encants","Bac Roda","Sant Martí","La Pau",
		         "Sants Est.","Tarragona","Poble Sec","Drassanes","Liceu","Diagonal",
				  "Besòs","Besòs Mar","El Maresme","Selva Mar","Poblenou","Llacuna","Bogatell","Ciutadella","Barcelone.","Jaume I","Girona","Verdaguer","Joanic","Alfons X",
		          "Guinardó","Maragall","Llucmajor","Via Júlia",
		          "Entença","H. Clínic","Sant Pau","Camp Arpa","Congrés"};

	vector<vector<int>> parells_parades;
	
	parells_parades = { {0,1},{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{8,9},{9,10},{10,11},{11,12},{12,13},{14,15},{15,5},{5,16},{16,17},{17,18},{18,19},{19,20},{20,11},{11,21},{21,22},
	{22,23},{24,25},{25,2},{2,26},{26,14},{14,27},{27,28},{28,6},{6,16},{16,29},{23,30},{30,31},{31,32},{32,33},{33,34},{34,35},{35,36},{36,37},{37,38},{38,39},{39,7},{7,16},{16,40},{40,41},
	{41,42},{42,43},{43,44},{44,45},{45,46},{46,47},{0,24},{24,48},{48,49},{49,29},{29,41},{41,19},{19,50},{50,51},{51,13},{13,52},{52,45}};

	vector<int> pesos = {511,995,425,2271,1782,787,375,1603,493,960,1212,499,1181,647,494,124,1794,1607,536,1781,311,708,186,882,1796,1132,1090,1145,2393,1730,620,442,1654,706,292,305,1204,
		617,20,1242,184,655,2034,1170,281,979,1569,990,461,1702,1024,986,647,113,1585,520,962,1339,662,851,1695,1337,622,1290 }; //64 pesos
	
	Graf g(noms_nodes, parells_parades);

	
	g.mostra();
	system("PAUSE");
	

	/*
	vector<vector<int>> cicles = g.cicles();
	for (int i = 0; i < cicles.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << noms_nodes[cicles[i][j]] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
	*/


	//grafPonderat gP(noms_nodes, parells_parades,numNodes,pesos);
	//gP.mostra();
	//system("PAUSE");
}